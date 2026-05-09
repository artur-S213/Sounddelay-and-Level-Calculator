#include "app-window.h"
#include "controller.h"
#include "SdalcalCore.h"
#include <utility> 

// Constructor
SdalcalController::SdalcalController(slint::ComponentHandle<AppWindow> ui){
    this->m_ui = std::move(ui);
    set_Callback_handling();
}

void SdalcalController::set_Callback_handling(){
    m_ui->on_parameter_changed([this](float distance, float level){
        this->handleInputChange(distance, level);
    });
}

void SdalcalController::handleInputChange(float distance, float level){
    updateUI(calculateParameters(distance, level));
}

SdalcalCoreResults SdalcalController::calculateParameters(float distance, float level){
    return SdalcalCore::calculateAllValues(distance, level);
}

void SdalcalController::updateUI(SdalcalCoreResults results){
    m_ui->set_delay(results.delay);
    m_ui->set_speakerL2(results.soundLevelL2);
    m_ui->set_adjustmentLevel(results.dropLevel);
    m_ui->set_dropLevel(results.adjustmentLevel);
    m_ui->set_setpoint(results.setpoint);

}

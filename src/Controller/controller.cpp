#include "app-window.h"
#include "controller.h"
#include "SdalcalCore.h"

SdalcalController::SdalcalController(AppWindow* ui){
    this->m_ui = ui;
    
    m_ui->on_parameter_changed([this](float distance, float level){
        this->handleInputChange(distance, level);
    });
}

void SdalcalController::handleInputChange(float distance, float level){
    updateUI(calculateParameters(distance, level));
}

SdalcalCoreResults calculateParameters(float distance, float level){
    return SdalcalCore::calculateAllValues(distance, level);
}
        

void updateUI(SdalcalCoreResults results){

}
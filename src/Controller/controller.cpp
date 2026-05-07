#include "app-window.h"
#include "controller.h"
#include "SdalcalCore.h"

SdalcalController::SdalcalController(AppWindow* ui){
    this->m_ui = ui;
    // TODO: implement Controller for UI Event (Callbacks) 
}


void SdalcalController::handleInputChange(float distance, float levelL1){
    auto result = SdalcalCore::calculateAllValues(distance, levelL1);

}
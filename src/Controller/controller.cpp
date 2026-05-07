#include "app-window.h"
#include "CoreCalculations.h"

SdalcalController::SdalcalController(AppWindow* ui){
    this.m_ui = ui;
}

SdalcalController::handleInputChange(float distance, float levelL1){
    auto result = CoreCalculations::calculateAllValues(distance, levelL1);
    

}
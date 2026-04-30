#include "app-window.h"
#include "CoreCalculations.h"

Sdalcal_Controller::Sdalcal_Controller(AppWindow* ui){
    this.m_ui = ui;
}

Sdalcal_Controller::handleInputChange(float distance, float levelL1){
    auto result = CoreCalculations::calculateAllValues(distance, levelL1);
    

}
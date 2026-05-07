#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "app-window.h"
#include "SdalcalCore.h"

class SdalcalController {
    private:
        AppWindow* m_ui;

        void handleInputChange(float distance, float levelL1);
        SdalcalCoreResults calculateParameters(float distance, float level);
        void updateUI();

    public:
        SdalcalController(AppWindow* ui);
    

};

#endif
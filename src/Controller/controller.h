#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "app-window.h"

class SdalcalController {
    private:
        AppWindow* m_ui;

        void handleInputChange(float distance, float levelL1);

    public:
        SdalcalController(AppWindow* ui);
    

}

#endif
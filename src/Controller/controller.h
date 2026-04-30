#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "app-window.h"

class Sdalcal_Controller {
    private:
        AppWindow* m_ui;

        void handleInputChange(float distance, float levelL1);

    public:
        Sdalcal_Controller(AppWindow* ui);
    

}


#endif
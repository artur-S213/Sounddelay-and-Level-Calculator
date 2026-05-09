#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "app-window.h"
#include "SdalcalCore.h"
#include <slint-cpp.h> 
#include <memory>

class SdalcalController {
    private:
        slint::ComponentHandle<AppWindow> m_ui;

        void handleInputChange(float distance, float levelL1);
        void set_Callback_handling();
        SdalcalCoreResults calculateParameters(float distance, float level);
        void updateUI(SdalcalCoreResults results);

    public:
        SdalcalController(slint::ComponentHandle<AppWindow> ui);
    

};

#endif
#include "Controller/controller.h"
#include "controller.h"
#include "app-window.h"
#include <memory>
#include <slint.h> 

int main(int argc, char **argv)
{
    auto ui = AppWindow::create();

    // auto controller = std::make_shared<SdalcalController>(ui);
    SdalcalController ui_ctrl(ui);

    ui->run();
    return 0;
}

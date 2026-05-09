#include "Controller/controller.h"
#include "app-window.h"
#include <memory>

int main(int argc, char **argv)
{
    auto ui = AppWindow::create();

 
    std::make_shared<SdalcalController>(ui);

    ui->run();
    return 0;
}

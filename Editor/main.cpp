
#include "src/MainWindow.hpp"

int main()
{

    fiene::MainWindow *app = new fiene::MainWindow();
    app->execute();
    delete app;

    return 0;
}
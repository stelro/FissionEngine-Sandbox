#include "App.hpp"

int main()
{
    App app;
    app.init();
    app.run();
    app.terminate();

    return app.getExitCode();
}
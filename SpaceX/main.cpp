#include <Engine/Game/App.hpp>


int main()
{
    Fiene::App app;

    app.run();
    app.terminate();

    return app.getExitCode();
}

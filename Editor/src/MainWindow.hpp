//
// Created by stel on 29/12/2016.
//

#ifndef PROJECT_MAPEDITOR_HPP
#define PROJECT_MAPEDITOR_HPP

#include "../imgui/imgui.h"
#include <Engine/Core/Window.hpp>
#include <Engine/Core/Camera2D.hpp>



namespace fiene {

    class InputManager;
    class Window;
    class ShaderProgram;


    class MainWindow {
    public:
        MainWindow();
        ~MainWindow();
        void execute();



    private:
        bool mTerminate;

        Fiene::Window *mWindow;
        Fiene::Camera2D mCamera;

    };

}


#endif //PROJECT_MAPEDITOR_HPP

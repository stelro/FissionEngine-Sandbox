//
// Created by stel on 30/12/2016.
//

#ifndef PROJECT_WORLDEDITOR_HPP
#define PROJECT_WORLDEDITOR_HPP

namespace fiene {

    class ShaderProgram;
    class SpriteBatch;
    class Camera2D;
    class InputManager;


    class WorldEditor {
    public:
        WorldEditor();
        ~WorldEditor();
        void show();

        void generateOrthoMap();

    private:
        ShaderProgram *mShaderProgram;
        SpriteBatch *mSpriteBatch;
        Camera2D *mCamera;
        InputManager *mInputHandler;


    };

}


#endif //PROJECT_WORLDEDITOR_HPP

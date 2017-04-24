//
// Created by stel on 6/1/2017.
//

#ifndef PROJECT_SNAKE_HPP
#define PROJECT_SNAKE_HPP

#include <Engine/2D/SpriteBatch.hpp>
#include <Engine/Core/InputManager.hpp>

enum class CurrentPosition {
    UP,
    DOWN,
    RIGHT,
    LEFT
};

class Snake {
public:
    Snake();
    ~Snake();
    void init(fiene::InputManager *inputManager);
    void render(fiene::SpriteBatch& spriteBatch);
    void update();

private:
    fiene::InputManager *mInputManager;
    fiene::SpriteBatch  mSpriteBatch;
    int                 mTotalLength;
    bool                mDead;
    fiene::Vec2         mPosition;
    GLuint              textureId;
    CurrentPosition     mCurrentPosition;


    const float SNAKE_WIDTH = 12.0f;
    const float SNAKE_HEIGHT = 12.0f;
    const float SNAKE_SPEED = 2.8f;

};


#endif //PROJECT_SNAKE_HPP

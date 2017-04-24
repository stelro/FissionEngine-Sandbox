//
// Created by stel on 6/1/2017.
//

#include "Snake.hpp"

#include <Engine/ResourceManager/ResourceManagerBase.hpp>
#include <Engine/Math/Vector.hpp>
#include <Engine/Utils/FDebug.hpp>

Snake::Snake()
    : mCurrentPosition(CurrentPosition::UP)
{

}

Snake::~Snake()
{

}

void Snake::init(fiene::InputManager *inputManager)
{
    mInputManager = inputManager;
    textureId  = fiene::ResourceManager::getTextureId("Textures/rect.png");
}
// Sniek Fender Bender
void Snake::render(fiene::SpriteBatch& spriteBatch)
{

    fiene::Vec4 destVec(mPosition.x,mPosition.y,SNAKE_WIDTH, SNAKE_HEIGHT);
    fiene::Vec4 upVec(0.0f, 0.0f, 1.0f, 1.0f);
    fiene::Color color(224,224,224,255);

    spriteBatch.append(destVec,upVec,textureId, 0.0f, color);

}

void Snake::update()
{

    if (mInputManager->isKeyPressed(SDLK_w)) {
        mCurrentPosition = CurrentPosition::UP;
    }

    else if (mInputManager->isKeyPressed(SDLK_s)) {
        mCurrentPosition = CurrentPosition::DOWN;
    }

    if (mInputManager->isKeyPressed(SDLK_a)) {
        mCurrentPosition = CurrentPosition::LEFT;
    }

    else if (mInputManager->isKeyPressed(SDLK_d)) {
        mCurrentPosition = CurrentPosition::RIGHT;
    }

    switch ( mCurrentPosition ) {

        case CurrentPosition::UP:
            mPosition.y += SNAKE_SPEED;
            break;
        case CurrentPosition::DOWN:
            mPosition.y -= SNAKE_SPEED;
            break;
        case CurrentPosition::RIGHT:
            mPosition.x += SNAKE_SPEED;
            break;
        case CurrentPosition::LEFT:
            mPosition.x -= SNAKE_SPEED;
            break;
    }
}




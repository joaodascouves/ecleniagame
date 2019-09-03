#include "eplayable.h"
#include "gameinstance.h"
#include <iostream>

EPlayable::EPlayable()
{
    texRun.loadFromFile("/home/void/runanim.bmp");
    drawableObject->setTexture(texRun);
    drawableObject->setScale(0.3f, 0.3f);
    drawableObject->setTextureRect(sf::IntRect(0, 0, 399, 369));

    setPosition(20, 500);

    frames = 9;
    sequences.push_back({0, 0, 8});
    sequences.push_back({0, 0, 3});

    frameWidth = texRun.getSize().x/9;
    frameHeight = texRun.getSize().y/1;
}

void EPlayable::update(const float dt)
{
    if( playerStatus == S_STANDING )
    {
        currentSequence = 1;
        tickAnimation();
    }

    drawableObject->setTextureRect(currentFrame());
    std::cout << GameInstance::get().fps << std::endl;
}

void EPlayable::handleMovement()
{
    playerStatus = S_STANDING;

    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
    {
        if( direction == D_RIGHT ) flipHorizontally();
        drawableObject->move(-2, 0);

        playerStatus = S_RUNNING;
        currentSequence = 0;
        tickAnimation();
    }

    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
    {
        if( direction == D_LEFT ) flipHorizontally();
        drawableObject->move(2, 0);

        playerStatus = S_RUNNING;
        currentSequence = 0;
        tickAnimation();
    }
}

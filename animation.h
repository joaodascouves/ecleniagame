#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
public:
    Animation();

    int frames;
    int frameWidth;
    int frameHeight;
    int frameCount = 0;

    int currentSequence = 0;

    struct sequenceMap
    {
        int row;
        int begin;
        int end;

    };

    std::vector<sequenceMap> sequences;

    sf::IntRect currentFrame();
    void tickAnimation();


};

#endif // ANIMATION_H

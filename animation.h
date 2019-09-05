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

    int currentSequence = 0;

    struct sequenceMap
    {
        int row;
        int begin;
        int end;

        int pos;

    };

    std::vector<sequenceMap> sequences;

    sf::IntRect currentFrame();
    void tickAnimation();
    void tickAnimation(int);
//    void setAnimationSize(int, int);


};

#endif // ANIMATION_H

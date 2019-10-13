#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <map>

class Animation
{
public:
    Animation();

    size_t frames;
    unsigned int frameWidth;
    unsigned int frameHeight;

    std::size_t currentSequence = 0;

    struct sequenceMap
    {
        int row;
        int begin;
        int end;

        int pos;
        int cycle;

    };

    std::map<int, sequenceMap> sequences;

    sf::IntRect currentFrame();

    void addSequence(int, sequenceMap);
    sequenceMap getSequence();
    sequenceMap getSequence(int);

    bool tickAnimation();
    bool tickAnimation(int);
    bool tickAnimation(int, bool);

//    void setAnimationSize(int, int);


};

// Declaração global da struct declarada dentro da classe
typedef Animation::sequenceMap sequenceMap;

#endif // ANIMATION_H

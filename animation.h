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
    bool sequenceEnd = false;

    enum { D_LEFT = -1, D_RIGHT = 1 };
    short direction = D_RIGHT;

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
    bool hasSequence(int);
    sequenceMap getSequence();
    sequenceMap getSequence(int);

    bool tickAnimation();
    bool tickAnimation(int);
    bool tickAnimation(int, bool);

    constexpr bool isSequenceCompleted(){ return sequenceEnd; }

//    void setAnimationSize(int, int);


};

// Declaração global da struct declarada dentro da classe
typedef Animation::sequenceMap sequenceMap;

#endif // ANIMATION_H

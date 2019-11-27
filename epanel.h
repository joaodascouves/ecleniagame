#ifndef EPanel_H
#define EPanel_H

#include "entity.h"
#include <functional>

class EPanel : public Entity<sf::RectangleShape>
{
public:
    EPanel(const sf::Vector2f&, const sf::Color&);
    ~EPanel() override = default;

    void appendLine(const std::string &);
    void moveChoice(const bool);

    void toggleChooseable(const bool);
    void toggleActive(const bool);

    bool isChooseable() const;
    bool isActive() const;

    short getChoice() const;
    virtual void action(Entity<sf::RectangleShape> *) override;

    std::function<void(const short)> actionFunc;

private:
    bool chooseable;
    bool active;

    signed short choice;

    sf::Text* choiceMark;
};

#endif // EPanel_H

#ifndef EDIALOGBOX_H
#define EDIALOGBOX_H

#include "entity.h"

class EDialogBox : public Entity<sf::RectangleShape>
{
public:
    EDialogBox();

    std::vector<std::pair<sf::Text*, sf::Text*>> dialog;

    void addDialog(const std::string&, const std::string&);

    void preview();
    void next();
    void rewind();

    void action(Entity *) override;

private:
    sf::Text nextIcon;
    std::vector<std::pair<sf::Text*, sf::Text*>>::iterator position;
};

#endif // EDIALOGBOX_H

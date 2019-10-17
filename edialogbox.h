#ifndef EDIALOGBOX_H
#define EDIALOGBOX_H

#include "entity.h"

class EDialogBox : public Entity<sf::RectangleShape>
{
public:
    EDialogBox();

    std::vector<std::pair<sf::Text*, sf::Text*>> dialog;

    void addDialog(std::string, std::string);

    void preview();
    void next();
    void rewind();

private:
    sf::Text nextIcon;
    std::vector<std::pair<sf::Text*, sf::Text*>>::iterator position;
};

#endif // EDIALOGBOX_H

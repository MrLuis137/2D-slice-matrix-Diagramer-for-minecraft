#ifndef TOPMENU_H
#define TOPMENU_H
#include <SFML/Graphics.hpp>
#include "../config/constants.hpp"
#include "../config/font.hpp"

class TopMenu{
    static const int MAX_ITEMS = 5;
    public:
        TopMenu(float width, float height);
        void draw(sf::RenderWindow &window);
    private:
        sf::Text menu[MAX_ITEMS];
        sf::RectangleShape background;
};


#endif 
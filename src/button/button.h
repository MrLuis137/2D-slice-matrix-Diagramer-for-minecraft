#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>
#include "../config/constants.hpp"
#include "../config/font.hpp"

class Button{

    
    public:

    using Action = std::function<void()>;
    // add font
    Button(std::string, sf::Vector2f size, sf::Vector2f position, Action clicAction);
    void draw(sf::RenderWindow &window);
    void clickHandler(sf::Vector2f mousePos);

    private:
    sf::Text btText;
    Action callback;
    sf::RectangleShape btBackground;
};

#endif
#include "button.h"
#include <iostream>

// add font
Button::Button(std::string text , sf::Vector2f size, sf::Vector2f position, Action clicAction) : callback(clicAction){
    btBackground = sf::RectangleShape(size);
    btBackground.setPosition(position);
    btBackground.setFillColor(Config::buttonColor);
    
    int textPosX = position.x + size.x / 2;
    int textPosY = position.y + size.y / 2;
    sf::Vector2f textPos(textPosX, textPosY);


    btText.setString(text);
    btText.setFont(Config::font);
    btText.setCharacterSize(11);
    btText.setFillColor(Config::fontColor);
    btText.setPosition(textPos);



    sf::FloatRect bounds = btBackground.getLocalBounds();
    btBackground.setPosition(position);

}
void Button::draw(sf::RenderWindow &window){
    window.draw(btBackground);
    window.draw(btText);
}
void Button::clickHandler(sf::Vector2f mousePos){
    // Modyfy it to my needs
    if (btBackground.getGlobalBounds().contains(mousePos)) {
            if (callback) callback(); // Ejecuta la función asignada
        }
}
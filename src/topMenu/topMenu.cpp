#include <SFML/Graphics.hpp>
#include <iostream>
#include "../config/constants.hpp"
#include "../config/font.hpp"
#include "topMenu.h"

    TopMenu::TopMenu(float width, float height){
        background.setFillColor(Config::menuBGColor);
        background.setSize(sf::Vector2f(width, height));
        background.setPosition(0,0);
        menu[0].setFont(Config::font);
        menu[0].setFillColor(Config::buttonColor);
        menu[0].setString("Open File");
        menu[0].setCharacterSize(11);
        menu[0].setPosition(sf::Vector2f(width/(MAX_ITEMS + 1) * 1, height / 2));

    }

    void TopMenu::draw(sf::RenderWindow &window){
        //std::cout << "Intentando dibujar el menú..." << std::endl;
        window.draw(background);
        for(int i = 0; i < MAX_ITEMS; i++){
            window.draw(menu[i]);
        }
    }
    
   
#include <iostream>
#include "src/layer.h"
#include <SFML/Graphics.hpp>
int main() {
    std::cout << "Iniciando programa.";

    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(200.f, 200.f);


    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}
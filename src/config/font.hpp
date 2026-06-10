#ifndef FONT_HPP
#define FONT_HPP

#include <SFML/Graphics.hpp>
#include <stdexcept>

namespace Config{

    inline sf::Font font;

    inline void loadFont(){
        //Chage it later.
       if(!font.loadFromFile("/run/media/mrluis137/linux-Z/Documentos Locales/Git/Minecraft_2D_Diagrammer/2D-slice-matrix-Diagramer-for-minecraft/assets/Comfortaa-Light.otf")){
                throw std::runtime_error("Font not found");
        }
    }
};

#endif
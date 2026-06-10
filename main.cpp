#include <iostream>
#include "src/layer/layer.h"
#include <SFML/Graphics.hpp>
#include "src/topMenu/topMenu.h"
#include "src/button/button.h"
#include "src/config/constants.hpp"
#include "src/config/font.hpp"
#include "imgui-sfml/imgui-SFML.h"
#include "imgui/imgui.h"
#include <nfd.hpp> // Debes incluir Native File Dialog
#include <iostream>
#include <string>
#include "src/layer/layer.h"

void drawLayer(Layer layer, sf::RenderWindow &window){
    sf::RectangleShape shape;
    for(int i = 0; i < layer.rows; i++){
        for(int j = 0; j < layer.columns; j++){
            std::cout << "Drawing block at (" << i << ", " << j << ")" << std::endl;
            shape.setSize(sf::Vector2f(30,30));
            shape.setPosition(sf::Vector2f(i*(30+3),j*(30+3)));
            shape.setFillColor(sf::Color::White);
            shape.setOutlineColor(sf::Color::Black);
            shape.setOutlineThickness(1);
            window.draw(shape);
        }
    }
}

int main() {
    std::cout << "Iniciando programa..." << std::endl;

    Layer layerTest = Layer(10,11);

    Config::loadFont();
    sf::RenderWindow window(sf::VideoMode(1000, 400), "SFML + ImGui + NFD");
    window.setFramerateLimit(60); // Importante para que ImGui no consuma 100% CPU

    if (!ImGui::SFML::Init(window)) return -1;

    sf::Clock deltaClock; // Necesario para el Update de ImGui

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // --- ACTUALIZACIÓN ---
        ImGui::SFML::Update(window, deltaClock.restart());

        // --- LÓGICA DE IMGUI ---
        ImGui::Begin("Panel de Control"); // Creamos una ventana para contener el botón
        
        if (ImGui::Button("Seleccionar archivo")) {
            NFD::Guard nfdGuard; // Inicialización local correcta
            NFD::UniquePath outPath;
            nfdresult_t result = NFD::OpenDialog(outPath, nullptr, 0);

            if (result == NFD_OKAY) {
                std::string path = outPath.get();
                std::cout << "Archivo seleccionado: " << path << std::endl;
            } else if (result == NFD_CANCEL) {
                std::cout << "Usuario canceló la selección." << std::endl;
            } else {
                std::cout << "Error: " << NFD::GetError() << std::endl;
            }
        }
        if (ImGui::Button("agregar fila")){
            layerTest.addRowBottom();
        }
        if (ImGui::Button("agregar columna")){
            layerTest.addColumnRight();
        }

        ImGui::End(); // Finaliza la ventana de ImGui

        // --- RENDERIZADO ---
        window.clear();
        
        drawLayer(layerTest, window);
        ImGui::SFML::Render(window); // Dibuja la interfaz de ImGui sobre SFML
        
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}


//Includes if needed
#include <vector>
#include <stdexcept>
#include "layer.h"
#include <iostream>


std::vector<int> blocks;
int rows;
int columns;

int Layer::getPosition(int r, int c){
    if(c> columns or r > rows){
        throw std::runtime_error("Unexpected dimentions");
    }
    return r * (rows - 1) + c;
}

Layer::Layer(int rows, int columns){
    this->rows = rows;
    this->columns = columns;
    blocks.resize(rows * columns);
}

int Layer::get(int r, int c){
    
    return blocks.at(getPosition(r,c));
}

void Layer::set(int r, int c, int value){
    blocks.assign(getPosition(r,c),value);
}

void Layer::addColumnRight(){
    std::vector<int> newBlocks;
    newBlocks.reserve(rows * (columns + 1));

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            newBlocks.push_back(get(r, c));
        }
        newBlocks.push_back(0); // Añade el nuevo bloque a la derecha de la fila
    }
    
    columns++;
    blocks = newBlocks; // Guarda los cambios
}

void Layer::addColumnLeft(){
    std::vector<int> newBlocks;
    newBlocks.reserve(rows * (columns + 1));

    for (int r = 0; r < rows; r++) {
        newBlocks.push_back(0); // Añade el nuevo bloque al inicio de la fila
        for (int c = 0; c < columns; c++) {
            newBlocks.push_back(get(r, c));
        }
    }
    
    columns++;
    blocks = newBlocks; // Guarda los cambios
}

void Layer::addRowTop(){
    // Crear una fila llena de ceros
    std::vector<int> newBlocks(columns, 0);
    
    // Insertar todos los bloques viejos al final de los nuevos ceros
    newBlocks.insert(newBlocks.end(), blocks.begin(), blocks.end());
    
    rows++;
    blocks = newBlocks; // Guarda los cambios
}

void Layer::addRowBottom(){
    blocks.insert(blocks.end(), columns, 0);
    rows++; 
}


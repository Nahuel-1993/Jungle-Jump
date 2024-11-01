#pragma once
#include <SFML/Graphics.hpp>

class Collisionable { //Clase que permite colisionar objetos y que el sistema lo reconozca

public:
    virtual sf::FloatRect getBounds() const=0; //Metodo polimorfico. Sera heredado obligatoriamente
    bool isCollision(Collisionable& col) const; //Se fija si los sprites se intersectan

};

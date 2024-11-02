#include "Camu.h"
#include <stdlib.h>

Camu::Camu() {
    _texture.loadFromFile("camu.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
    _sprite.setPosition(100, 500);
}

void Camu::update() {
    _sprite.move(0, 2); // Movimiento hacia abajo
    if (_sprite.getPosition().y >= 600) { // Asegurando que no salga de la pantalla
        _sprite.setPosition(_sprite.getPosition().x, 600);
    }
}

void Camu::respawn() {
    _sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().width);
}
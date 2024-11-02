#include "Bacaba.h"
#include <stdlib.h>

Bacaba::Bacaba() {
    _texture.loadFromFile("bacaba.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
    _sprite.setPosition(100, 500);
}

void Bacaba::update() {
    _sprite.move(0, 2); // Movimiento hacia abajo
    if (_sprite.getPosition().y >= 600) { // Asegurando que no salga de la pantalla
        _sprite.setPosition(_sprite.getPosition().x, 600);
    }
}

void Bacaba::respawn() {
    _sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().width);
}

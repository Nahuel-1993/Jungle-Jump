#include "Banana.h"

Banana::Banana() {
    _texture.loadFromFile("banana.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
    _sprite.setPosition(100, 500);
}

void Banana::update() {
    // Implementación de la función update
}

void Banana::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

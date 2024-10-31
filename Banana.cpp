#include <stdlib.h>
#include "Banana.h"

Banana::Banana() {
    _texture.loadFromFile("banana.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
    _sprite.setPosition(100, 500);
}

void Banana::update() {
    // Implementaci�n de la funci�n update
}

void Banana::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

void Banana::respawn(){
    _sprite.setPosition(std::rand()%700 + _sprite.getGlobalBounds().width,std::rand()%500 + _sprite.getGlobalBounds().width);
}

sf::FloatRect Banana::getBounds() const {
    return _sprite.getGlobalBounds();
}

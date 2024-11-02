#include "Fruta.h"

Fruta::Fruta() {
    // Constructor vacío o con inicializaciones comunes a todas las frutas
}

void Fruta::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

sf::FloatRect Fruta::getBounds() const {
    return _sprite.getGlobalBounds();
}

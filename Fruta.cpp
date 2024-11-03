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

void Fruta::setPosition(float x, float y) {
    _sprite.setPosition(x, y);
    _velocidadCaida = 0;
    _velocidadCaida -= 0.5; // Aplicando gravedad
    _sprite.move(0, -_velocidadCaida);
}

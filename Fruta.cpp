#include "Fruta.h"

Fruta::Fruta() : _velocidadCaida(2.0f) { // Inicializar la velocidad de ca�da
    // Constructor vac�o o con inicializaciones comunes a todas las frutas
}

void Fruta::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

sf::FloatRect Fruta::getBounds() const {
    return _sprite.getGlobalBounds();
}

void Fruta::setPosition(float x, float y) {
    _sprite.setPosition(x, y);
}

void Fruta::setVelocidadCaida(float velocidad) {
    _velocidadCaida = velocidad;
}

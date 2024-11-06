#include "Fruta.h"

Fruta::Fruta(int puntos) : _velocidadCaida(2.0f), puntos(puntos) { // Inicializar la velocidad de caída
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
}

void Fruta::setVelocidadCaida(float velocidad) {
    _velocidadCaida = velocidad;
}

int Fruta::getPuntos() const {
    return puntos;
}

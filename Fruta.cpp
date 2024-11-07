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

///Codigo agregado Euge
void Fruta::update() { ///chequeamos que la fruta llegue al piso
    if (_sprite.getPosition().y + _sprite.getGlobalBounds().height >= 600) {
        respawn();  ///Volvemos a ubicar la fruta
    } else {
        _sprite.move(0, _velocidadCaida); ///Si no tocó el piso sigue cayendo
    }
}
void Fruta::respawn() {
    float x = rand() % 750;  ///Ubicamos aleatoriamente la fruta en la pantalla
    _sprite.setPosition(x, -_sprite.getGlobalBounds().height);
}

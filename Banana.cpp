#include "Banana.h"
#include <stdlib.h>

Banana::Banana() {
    _texture.loadFromFile("banana.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
    _sprite.setPosition(100, 500);
}

void Banana::update() {
    _sprite.move(0, _velocidadCaida); // Mueve la fruta hacia abajo
     if (_sprite.getPosition().y >= 600) { // Asegurando que no salga de la pantalla
        _sprite.setPosition(_sprite.getPosition().x, 600);
    }
}

void Banana::respawn() {
    setPosition(rand() % 800, -50); // Posiciona la fruta justo arriba de la ventana
    setVelocidadCaida(2.0f); // Reinicia la velocidad de caída
}

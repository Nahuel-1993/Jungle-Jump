#include "Bacaba.h"
#include <stdlib.h>

Bacaba::Bacaba() : Fruta(150){
    _texture.loadFromFile("bacaba.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
    _sprite.setPosition(100, 500);
}

void Bacaba::update() {
    _sprite.move(0, _velocidadCaida); // Mueve la fruta hacia abajo
     if (_sprite.getPosition().y >= 600) { // Asegurando que no salga de la pantalla
        _sprite.setPosition(_sprite.getPosition().x, 600);
        respawn();
    }
}

void Bacaba::respawn()  {
    setPosition(rand() % 800, -50); // Posiciona la fruta justo arriba de la ventana
    setVelocidadCaida(2.0f); // Reinicia la velocidad de caída
}

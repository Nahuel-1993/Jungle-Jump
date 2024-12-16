#include "Plataforma.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime> ///Para los numero aleatorios
#include <iostream>
#include "Personaje.h"

Plataforma::Plataforma(float x, float y, float ancho, float alto)
    : _velocidadCaida(0.7f) ///Inicializamos la velocidad de caída
 {
        _shape.setPosition(x, y);  ///Posicion de la plataforma
        _shape.setSize(sf::Vector2f(100, 10));  /// Tamaño
        _shape.setFillColor(sf::Color::Green);  ///Elegimos el color
        setTexture("plataforma.png");

}

void Plataforma::cmd()
{

}
void Plataforma::setTexture(const std::string& texturefile)
{
    if (!_texture.loadFromFile(texturefile)) {
        std::cout << "Error al cargar la textura de la plataforma: " << texturefile << std::endl;
    }
    _sprite.setTexture(_texture);
    _sprite.setPosition(_shape.getPosition());
}

void Plataforma::update()
{
    _shape.move(0, _velocidadCaida); /// Movemos la plataforma para abajo
    _sprite.setPosition(_shape.getPosition());

    if (_shape.getPosition().y >= 500) {
        respawn();
    }
}

void Plataforma::setVelocidadCaida(float velocidad) {
    _velocidadCaida = velocidad;
}
const sf::Sprite& Plataforma::getDraw()const {
            return _sprite;
    }

sf::FloatRect Plataforma::getBounds() const {
    return _sprite.getGlobalBounds();
}
void Plataforma::respawn()
{
    float xAleatorio = rand() %500 + 70;
    float yAleatorio = 0; ///Bjan todas desde la parte de arriba de la pantalla
    _shape.setPosition(xAleatorio, yAleatorio); ///Ubicamos en la nueva posición la plataforma
    _sprite.setPosition(_shape.getPosition()); ///Ubicamos en la misma posició que la plataforma el sprite
}

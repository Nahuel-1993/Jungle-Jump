#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Plataforma
{
    private:
        sf::RectangleShape _shape; ///Propiedades miembros, no tiene estados porque está quieto nomás
        float _velocidadCaida;

        sf::Texture _texture;
        sf::Sprite _sprite;
    public:

        Plataforma(float x, float y, float ancho, float alto);

        void cmd();
        void update();
        void setPosition(float x, float y);
        void setVelocidadCaida(float velocidad);

        const sf::Sprite& getDraw() const;

        sf::FloatRect getBounds() const;
        void respawn();
        void setTexture(const std::string& textureFile);

};

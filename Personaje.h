#pragma once
#include <SFML\Graphics.hpp>
#include "Collisionable.h"

    enum ESTADOS_PERSONAJE{
        QUIETO,
        CAMINANDO_ADELANTE,
        CAMINANDO_ATRAS,
        SALTANDO
    };


class Personaje: public sf::Drawable, public Collisionable
{
private:

    sf::Sprite _sprite;
    sf::Texture _texture;
    //sf::Vector2f _velocity;        //Le da un valor a la velocidad de desplazamiento cuando ejecuta en CMD
    ESTADOS_PERSONAJE _estado;
    float _velocidadSalto;

public:


    Personaje();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void cmd();
     sf::FloatRect getBounds() const override;
};

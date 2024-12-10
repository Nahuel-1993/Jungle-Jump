#pragma once
#include <SFML\Graphics.hpp>
#include "Collisionable.h"
#include "Plataforma.h"
#include "Vidas.h"

    enum ESTADOS_PERSONAJE{
        QUIETO,
        CAMINANDO_ADELANTE,
        CAMINANDO_ATRAS,
        SALTANDO,
        SALTANDO_ADELANTE,
        SALTANDO_ATRAS
    };


class Personaje: public sf::Drawable, public Collisionable //Sabe colisionar
{
private:

    sf::Sprite _sprite;
    sf::Texture _texture;
    //sf::Vector2f _velocity;        //Le da un valor a la velocidad de desplazamiento cuando ejecuta en CMD
    ESTADOS_PERSONAJE _estado;
    float _velocidadSalto;
    Vidas _vidas; // Objeto de la clase Vidas

public:

    Personaje();
    void update();
    void setEstado(ESTADOS_PERSONAJE nuevoEstado);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void cmd();
    sf::FloatRect getBounds() const override; //Sabe como es su rectangulo para colisionar
    const sf::Sprite& getDraw() const;
    sf::Sprite& getSprite();
    void setVelocidadSalto(float velocidad);
    float getVelocidadSalto() const;
    bool enPlataforma;
    int getVidas() const;
    void perderVida();
};

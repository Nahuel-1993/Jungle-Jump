#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Fruta : public sf::Drawable, public Collisionable {
protected:
    sf::Sprite _sprite;
    sf::Texture _texture;
    float _velocidadCaida;
    int puntos;

public:
    Fruta(int puntos);
    virtual void update() = 0; // M�todo virtual obligatorio para que cada fruta lo implemente
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void respawn() = 0; // Igual que update
    sf::FloatRect getBounds() const override;
    void setPosition(float x, float y);
    void setVelocidadCaida(float velocidad); // A�adir m�todo para establecer velocidad de ca�da
    int getPuntos() const;
};

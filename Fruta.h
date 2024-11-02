#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Fruta : public sf::Drawable, public Collisionable {
protected:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    Fruta();
    virtual void update() = 0; // Método virtual puro para que cada fruta lo implemente
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void respawn() = 0; // Método virtual puro para que cada fruta lo implemente
    sf::FloatRect getBounds() const override;
};

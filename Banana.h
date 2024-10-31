#pragma once
#include <SFML\Graphics.hpp>
#include "Collisionable.h"

class Banana: public sf::Drawable, public Collisionable //Sabe colisionar
{
    private:
        sf::Sprite _sprite;
        sf::Texture _texture;

    public:
        Banana();
        void cmd();
        void update();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void respawn(); //Reaparece el objeto en lugares random
        sf::FloatRect getBounds() const override; //Sabe como es su rectangulo para colisionar
};


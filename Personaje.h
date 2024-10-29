#pragma once
#include <SFML\Graphics.hpp>

class Personaje: public sf::Drawable
{
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocity;        //Le da un valor a la velocidad de desplazamiento cuando ejecuta en CMD

public:
    Personaje();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

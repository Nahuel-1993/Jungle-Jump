#pragma once
#include <SFML\Graphics.hpp>

class Frutas: public sf::Drawable
{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:



    Frutas();
    void cmd();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


};

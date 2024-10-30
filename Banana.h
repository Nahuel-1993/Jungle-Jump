#pragma once
#include <SFML\Graphics.hpp>

class Banana: public sf::Drawable
{
    private:
        sf::Sprite _sprite;
        sf::Texture _texture;

    public:
        Banana();
        void cmd();
        void update();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};


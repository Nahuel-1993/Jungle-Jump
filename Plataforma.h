#pragma once
#include <SFML/Graphics.hpp>

class Plataforma
{
    private:
        sf::RectangleShape _shape; ///Propiedades miembros, no tiene estados porque est� quieto nom�s
    public:
        Plataforma()
        {
            _shape.setPosition(500, 450); ///Configuramos la posici�n incial de la plataforma
            _shape.setSize({100, 30}); ///Configuramos las medidas de las plataformas
        }
       void cmd();
       void update();
       sf::RectangleShape& getDraw();




};

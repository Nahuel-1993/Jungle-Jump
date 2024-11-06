#include "Gameplay.h"
#include <iostream>

Gameplay::Gameplay()
{
    _tics=0;
    _estado = ESTADOS_GAMEPLAY::EJECUTANDO;
}

void Gameplay::checkCollision()
{
    if (Personaje.getDraw().getGlobalBounds().intersects(ob.getDraw().getGlobalBounds())){
        std::cout<< "Colisiono! "<<std::endl;
    }
}

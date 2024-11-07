#include "Collisionable.h"
#include <iostream>

bool Collisionable::isCollision(Collisionable& obj) const {
    return getBounds().intersects(obj.getBounds());
}
/*void Gameplay::checkColision()
{
    if(p.getDraw().getGlobalBounds().intersects(ob.getDraw().GetGlobalBounds()))
    {
        std::cout<< "Colisiono! "<<std::endl;
    }
}*/

#include "Collisionable.h"
#include <iostream>
#include "Plataforma.h"
#include "Personaje.h"

bool Collisionable::isCollision(Collisionable& obj) const {
    return getBounds().intersects(obj.getBounds());

}

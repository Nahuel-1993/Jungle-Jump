#pragma once
#include "Fruta.h"

class Maracuya : public Fruta {
public:
    Maracuya();
    void update() override;
    void respawn() override;
};

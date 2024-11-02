#pragma once
#include "Fruta.h"

class Banana : public Fruta {
public:
    Banana();
    void update() override;
    void respawn() override;
};

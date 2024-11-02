#pragma once
#include "Fruta.h"

class Camu : public Fruta {
public:
    Camu();
    void update() override;
    void respawn() override;
};

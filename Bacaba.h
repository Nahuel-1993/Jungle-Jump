#pragma once
#include "Fruta.h"

class Bacaba : public Fruta {
public:
    Bacaba();
    void update() override;
    void respawn() override;
};

#pragma once
#include <iostream>

class Vidas {
private:
    int vidas;

public:

    Vidas() : vidas(3) {}


    void perderVida() {
        if (vidas > 0) {
            vidas--;
            //std::cout<<"Restamos una vida en vidas.h. Vidas : "<< vidas<< std::endl;
        }
    }

    int getVidas() const {
        return vidas;
    }

    bool estaVivo() const {
        if(vidas > 0){
            return true;
        }
        else{
            return false;
        }
    }
};

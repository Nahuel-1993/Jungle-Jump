#pragma once
#include <iostream>


class ArchivoEstadistica
{
private:
    std::string nombre;
    int puntaje;

public:

    bool grabarRegistroEstadistica();
    std::string leerRegistroEstadistica();
    void setDatos(const char* nombreJugador, int puntosJugador);

};


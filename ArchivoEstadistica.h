#pragma once
#include <iostream>
#include <string> ///Para manejar la cadena de texto


class ArchivoEstadistica
{
private:
    char*nombre; ///Puntero DINÁMICO para almacenar el nombre
    int puntaje;

public:

    ///CONSTRUCTOR
    ArchivoEstadistica();


    bool grabarRegistroEstadistica();
    void setDatos(const char* nombreJugador, int puntosJugador);
    std::string leerRegistroEstadistica();

    ///DESTRUCTOR
    ~ArchivoEstadistica();

};

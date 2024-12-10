#pragma once
#include <iostream>
#include <cstring> // Para usar funciones de manejo de cadenas como strcpy y strlen

class Puntos {
private:
    int puntos;
    char vNombreJugador[30];

public:

    // Constructor que inicializa los puntos a 0 y asigna el nombre del jugador
    Puntos(const char* nombre) : puntos(0) {
        strncpy(vNombreJugador, nombre, sizeof(vNombreJugador) - 1);
        vNombreJugador[sizeof(vNombreJugador) - 1] = '\0';  // Asegurar que termine en NULL
    }


    void agregarPuntos(int cantidad) {
        puntos += cantidad;
    }

    void restarPuntos(int cantidad) {
        puntos -= cantidad;
    }


    int getPuntos() const {
        return puntos;
    }


    void reset() {
        puntos = 0;
    }


    const char* getNombre() const {
        return vNombreJugador;
    }

};

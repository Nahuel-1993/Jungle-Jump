#pragma once

class Puntos {
private:
    int puntos;

public:
    Puntos() : puntos(0) {}

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
};

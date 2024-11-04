#pragma once


void manejarRespawn(Fruta*& frutaActual, std::vector<Fruta*>& frutas, int& indiceFrutaActual, sf::Clock& relojRespawn, bool& enRespawn, int& puntos, sf::Sound& sound, Personaje& alan) {
    if (enRespawn) {
        frutaActual->setPosition(-100, -100);

        if (relojRespawn.getElapsedTime() >= sf::seconds(5)) {
            int nuevoIndice;
            do {
                nuevoIndice = std::rand() % frutas.size();
            } while (nuevoIndice == indiceFrutaActual);
            indiceFrutaActual = nuevoIndice;
            frutaActual = frutas[indiceFrutaActual];
            frutaActual->respawn();
            enRespawn = false;
            relojRespawn.restart();
        }
    } else {
        frutaActual->update(); // Llamamos a update de la clase derivada

        if (alan.isCollision(*frutaActual)) {
            enRespawn = true;
            puntos += 50;
            sound.play();
            frutaActual->setPosition(-100, -100);
            relojRespawn.restart();
        }
    }
}

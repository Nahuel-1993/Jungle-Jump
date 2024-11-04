#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Personaje.h"
#include "Fruta.h"

void gameplay(sf::RenderWindow& window, Personaje& alan, std::vector<Fruta*>& frutas, Fruta*& frutaActual, int& indiceFrutaActual, sf::Clock& relojRespawn, bool& enRespawn, int& puntos, sf::Sound& sound, sf::Text& text, sf::Sprite& image) {
    while (window.isOpen())
    {
        // 1° Read input - Actualiza los estados de los periféricos de entrada. ↓
        // Leer la cola de mensajes

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 2° CMD (Leemos que se apretó y lo ejecutamos)

        alan.cmd(); // Evaluamos los comandos

        // 3° Update - Actualiza los estados del juego

        alan.update();
        manejarRespawn(frutaActual, frutas, indiceFrutaActual, relojRespawn, enRespawn, puntos, sound, alan);

        text.setString(std::to_string(puntos)); // Como los puntos no son string, los convierte

        window.clear(); // Borra la pantalla para que no se superpongan objetos

        // 4° DRAW (muestra en la pantalla lo que hace update)

        // Dibujamos el fondo
        window.draw(image);

        // Dibujar personaje y fruta actual
        window.draw(alan);
        window.draw(*frutaActual);
        window.draw(text);

        // 5° Display - Flip
        window.display();
    }
}

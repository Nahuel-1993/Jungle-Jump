#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Personaje.h"
#include "Fruta.h"
#include "Puntos.h"
#include "Plataforma.h"

void gameplay(sf::RenderWindow& window, Personaje& alan, std::vector<Fruta*>& frutas, Fruta*& frutaActual,
              int& indiceFrutaActual, sf::Clock& relojRespawn, bool& enRespawn, Puntos& puntos,
              sf::Sound& sound, sf::Text& text, sf::Sprite& image, sf::Music& music,
              std::vector<Plataforma>& plataformas, Vidas& vidas) {

    // Crear el objeto de texto para mostrar el nombre, los puntos y las vidas
    sf::Text nombrePuntosVidasTexto;
    nombrePuntosVidasTexto.setFont(*text.getFont());
    nombrePuntosVidasTexto.setCharacterSize(15);
    nombrePuntosVidasTexto.setFillColor(sf::Color::White);
    nombrePuntosVidasTexto.setPosition(10, 4);

    while (window.isOpen()) {
        // 1° Read input - Actualiza los estados de los periféricos de entrada. ↓
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 2° CMD (Leemos que se apretó y lo ejecutamos)
        alan.cmd();

        // 3° Update - Actualiza los estados del juego
        alan.update();
        manejarRespawn(frutaActual, frutas, indiceFrutaActual, relojRespawn, enRespawn, puntos, sound, alan);

        // Concatenar nombre, puntos y vidas con salto de línea entre puntos y vidas
        std::string nombrePuntosVidas = std::string(puntos.getNombre()) +
                                        "  Puntos: " + std::to_string(puntos.getPuntos()) +
                                        "\nVidas: " + std::to_string(vidas.getVidas());

        nombrePuntosVidasTexto.setString(nombrePuntosVidas);  // Actualizo el texto con el nombre, puntos y vidas

        // Actualizamos las frutas
        for (auto& fruta : frutas) {
            fruta->update();
        }

        // Actualizamos las plataformas
        for (auto& plataforma : plataformas) {
            plataforma.update();

            if (alan.getDraw().getGlobalBounds().intersects(plataforma.getDraw().getGlobalBounds())) {
                //std::cout << "Colisiono!" << std::endl; ///Verificamos la colision

                sf::Vector2f nuevaPosicion = alan.getSprite().getPosition();
                nuevaPosicion.y = plataforma.getDraw().getPosition().y - alan.getDraw().getGlobalBounds().height;

                alan.setVelocidadSalto(0);
                alan.getSprite().setPosition(nuevaPosicion);///Actualizamos la posición a la posición de la plataforma
                alan.setEstado(QUIETO);
                alan.enPlataforma = true;
                }
                //std::cout<<"EN gameplay"<< alan.enPlataforma << std::endl;
                }

        window.clear(); // Borra la pantalla para evitar que los objetos se sobrepongan

        // 4° DRAW (muestra en la pantalla lo que hace update)

        // Dibujamos el fondo
        window.draw(image);

        ///Dibujamos las plataformas
        for (const auto& plataforma : plataformas) {
            window.draw(plataforma.getDraw());
        }

        // Dibujar personaje y fruta actual
        window.draw(alan);
        window.draw(*frutaActual);
        window.draw(text);

        // Dibujar las plataformas
        for (const auto& plataforma : plataformas) {
            window.draw(plataforma.getDraw());
        }

        // Dibujar el nombre, los puntos y las vidas
        window.draw(nombrePuntosVidasTexto);

        // 5° Display - Flip (actualiza la ventana)
        window.display();
    }
 }

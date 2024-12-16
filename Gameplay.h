#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Personaje.h"
#include "Fruta.h"
#include "Puntos.h"
#include "Plataforma.h"
#include "RespawnFruta.h"

void gameplay(sf::RenderWindow& window, Personaje& alan, std::vector<Fruta*>& frutas, Fruta*& frutaActual,
              int& indiceFrutaActual, sf::Clock& relojRespawn, bool& enRespawn, Puntos& puntos,
              sf::Sound& sound, sf::Text& text, sf::Sprite& image, sf::Music& music,
              std::vector<Plataforma>& plataformas, Vidas& vidas, bool& gameRunning, sf::Font& font) {

    font.loadFromFile ("pixel.ttf");

    ///Creamos el GAMEOVER
    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(50);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setString("GAME OVER");
    gameOverText.setPosition(100, 150);

    ///CREAMOS EL VOLVER MENU
    sf::Text volverMenu;
    volverMenu.setFont(font);
    volverMenu.setString("Presione ENTER \n para volver al menu principal");
    volverMenu.setCharacterSize(18);
    volverMenu.setFillColor(sf::Color::White);
    volverMenu.setPosition(10, 550);

    // Crear el objeto de texto para mostrar el nombre, los puntos y las vidas
    sf::Text nombrePuntosVidasTexto;
    nombrePuntosVidasTexto.setFont(*text.getFont());
    nombrePuntosVidasTexto.setCharacterSize(15);
    nombrePuntosVidasTexto.setFillColor(sf::Color::White);
    nombrePuntosVidasTexto.setPosition(10, 4);

   while (window.isOpen() && gameRunning){
        // 1° Read input - Actualiza los estados de los periféricos de entrada. ↓
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
                return;
            }
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
                break;
            }
            if (alan.getSprite().getPosition().y >= 600 && vidas.getVidas() >0) {
                            //std::cout<<"Alan está en el piso en gameplay.h"<<std::endl;
                            vidas.perderVida(); ///Restamos una vida
                            sf::Vector2f nuevaPosicion = plataformas[0].getDraw().getPosition();
                            nuevaPosicion.y -= alan.getDraw().getGlobalBounds().height;
                            alan.getSprite().setPosition(nuevaPosicion);
                            alan.setVelocidadSalto(0);
                            alan.setEstado(QUIETO);
                            alan.enPlataforma = true;
                            }

                //std::cout<<"EN gameplay"<< alan.enPlataforma << std::endl;
            }

        ///vERIFICAMOS LAS VIDAS
        if (vidas.getVidas() <= 0) {
        gameRunning = false;
            while (true) {
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                        return;
                    }
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                        return; /// VOLVEMOS AL MENÚ
                    }
                }

            window.clear();
            window.draw(image);
            window.draw(gameOverText);   /// pintamos el GAME OVER
            window.draw(volverMenu);     /// VOLVER MENÚ
            window.display();
            }
        }
            window.clear(); // Borra la pantalla para evitar que los objetos se sobrepongan

        // 4° DRAW (muestra en la pantalla lo que hace update)

        // Dibujamos el fondo
        window.draw(image);

        // Dibujar las plataformas
        for (const auto& plataforma : plataformas) {
            window.draw(plataforma.getDraw());
        }

        // Dibujar personaje y fruta actual
        window.draw(alan);
        window.draw(*frutaActual);
        window.draw(text);

        // Dibujar el nombre, los puntos y las vidas
        window.draw(nombrePuntosVidasTexto);

        // 5° Display - Flip (actualiza la ventana)
        window.display();
    }
}

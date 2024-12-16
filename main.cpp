#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <ctime>
#include "MenuSFML.h"
#include "CapturarNombre.h"
#include "Puntos.h"
#include "Vidas.h"
#include "Personaje.h"
#include "Banana.h"
#include "Maracuya.h"
#include "Camu.h"
#include "Bacaba.h"
#include "RespawnFruta.h"
#include "Gameplay.h"
#include <iostream>
#include "Plataforma.h"
#include <cstdlib>


int main()
{
    std::srand((unsigned)std::time(0));
    bool gameRunning;

      ///Inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jungle Jump");
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("pixel.ttf");

    MenuSFML menu;
    menu.setBackground("FondoMenu.png"); // Establecer la imagen de fondo del menú
    menu.setMusic("Menu.wav");

          int op = 4;

    while (window.isOpen()){
        while (op != 0 && window.isOpen()) {
        menu.handleInput(window, op);
        window.clear();
        menu.draw(window);
        window.display();

        if (op==1){
            menu.mostrarEstadistica(window);
            op= -1;
        }

        if (op == 2){
            menu.mostrarCreditos(window);
            op = -1; //Se resetea la opcion para volver al menu
        }
    }
    if (op== 0){
        gameRunning = true;
        menu.stopMusic();
    } //else { break;}
    /// Detener la música del menú antes de comenzar el gameplay
    menu.stopMusic();

    /// Configuro texto
    sf::Font font;
    font.loadFromFile("pixel.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);

    /// Configuramos el sonido de la mordida
    sf::SoundBuffer buffer;
    buffer.loadFromFile("bite.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(30);

    /// Sonido del gameplay
    sf::Music music;
    music.openFromFile("selva.wav");
    music.setLoop(true);
    music.play();
    music.setVolume(30);

    Personaje alan;

    /// Crea frutas y las pone en un vector
    std::vector<Fruta*> frutas = {new Banana(), new Maracuya(), new Bacaba(), new Camu()};

    /// Selecciona una fruta al azar para el primer respawn
    int indiceFrutaActual = std::rand() % frutas.size();
    Fruta* frutaActual = frutas[indiceFrutaActual];
    frutaActual->respawn();

    /// Crea el reloj para controlar el tiempo de respawn
    sf::Clock relojRespawn;
    bool enRespawn = false;

    /// Pedir nombre al jugador
    std::string nombreJugador = capturarNombre(window, font);

    /// Inicializo las vidas. El constructor le pone 3
    Vidas vidas;

    /// Inicializo los puntos
    Puntos puntos(nombreJugador.c_str()); ///Le pasamos el nombre al constructor. c_str para obtener puntero const char* del string nombre


    ///Creamos el fondo
    sf::Sprite image;
    sf::Texture tex;
    tex.loadFromFile("FONDO.png");
    image.setTexture(tex);

    ///Plataformas aleatorias
    std::vector<Plataforma> plataformas; ///Usamos push_back para añadir elementos al final del vector
   const float ancho = 100.f;
   const float alto=10.f;
   const float distanciaMinima = 100.f;

    for (int i = 0; i < 3; ++i) {
        float xAleatorio = rand() % 500 + 70;
        float yAleatorio;

        do{
            yAleatorio = rand() % 400 + 50;
            bool solapado = false;

            for(const auto& plataforma:plataformas){
                if(abs(yAleatorio - plataforma.getBounds().top) < distanciaMinima){
                    solapado = true;
                    break;
                }
            }
        if (!solapado){
        plataformas.push_back(Plataforma(xAleatorio, yAleatorio, ancho, alto));
        }
        }while (plataformas.size() < i +1);
    }
    for (auto& plataforma : plataformas) {
        plataforma.setTexture("plataforma.png");
    }
    ///Alan inicia sobre una plataforma
    if (!plataformas.empty()) {
    float xInicial = plataformas[0].getDraw().getPosition().x + (ancho / 2); ///Centramos a alan respecto de las platafromas
    float yInicial = plataformas[0].getDraw().getPosition().y - alan.getDraw().getGlobalBounds().height;
    alan.getSprite().setPosition(xInicial, yInicial);
    }

    ///Game Loop (update del juego) *Se subdivide internamente*
    gameplay(window, alan, frutas, frutaActual, indiceFrutaActual, relojRespawn, enRespawn, puntos, sound, text, image, music, plataformas, vidas, gameRunning, font);

    op = 4;
    menu.setMusic("Menu.wav");
    }

    return 0;
}

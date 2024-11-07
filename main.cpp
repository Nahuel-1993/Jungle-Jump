#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <ctime>
#include "Menu.h"
#include "Puntos.h"
#include "Personaje.h"
#include "Banana.h"
#include "Maracuya.h"
#include "Camu.h"
#include "Bacaba.h"
#include "RespawnFruta.h"
#include "Gameplay.h"
#include <iostream>
#include "rlutil.h" ///Librería para mejoreas del menú
#include "Plataforma.h"
#include <cstdlib>

void Menu(int &y, int&op);
void enter(int y, int&op);
void salir();

int main()
{
    std::srand((unsigned)std::time(0));

    int op=1, y=0;

    do
    {
        Menu(y, op);
    }
    while (op != 0);

    ///Inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jungle Jump");
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("pixel.ttf"); //Carga la fuente para visualizar el puntaje

    /// Configuro texto
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);

    /// Configuramos el sonido de la mordida
    sf::SoundBuffer buffer;
    buffer.loadFromFile("bite.wav"); //Cargamos un efecto de sonido para la colision

    sf::Sound sound; //Es el canal por donde vamos a reproducir el audio
    sound.setBuffer(buffer);

    sf::Music music;
    music.openFromFile("selva.wav");
    music.setLoop(true);
    music.play();

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

    /// Inicializo los puntos
    Puntos puntos;

    ///Creamos el fondo
    sf::Sprite image;
    sf::Texture tex;
    tex.loadFromFile("FONDO.png");

    image.setTexture(tex);

    ///Plataformas aleatorias

    std::vector<Plataforma> plataformas; ///Usamos push_back para añadir elementos al final del vector
   const float ancho = 100.f;
   const float alto=20.f;

   for (int i = 0; i < 3; ++i)
        {
            float xAleatorio = rand() % 650 + 25;
            float yAleatorio = rand() % 200 + 25;

            if (i > 0) {
            while (yAleatorio < plataformas[i-1].getBounds().top + 100) {
                yAleatorio = rand() % 200 + 25;
            }
        }

        plataformas.push_back(Plataforma(xAleatorio, yAleatorio, ancho, alto));
    }

    for (auto& plataforma : plataformas){
    plataforma.setTexture("plataforma.png");
    }


    ///Game Loop (update del juego) *Se subdivide internamente*

    gameplay(window, alan, frutas, frutaActual, indiceFrutaActual, relojRespawn, enRespawn, puntos, sound, text, image, music, plataformas);

    /// Liberacion del juego (Con SFML no hace falta)

    return 0;
}

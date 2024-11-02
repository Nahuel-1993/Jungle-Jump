#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <ctime>
#include "Personaje.h"
#include "Banana.h"
#include "Maracuya.h"
#include "Camu.h"
#include "Bacaba.h"
#include <iostream>
#include "rlutil.h" ///Librería para mejoreas del menú

int main()
{
    std::srand((unsigned)std::time(0));
/*
    int op;
    rlutil::setBackgroundColor(rlutil::GREEN); ///CAMBIAMOS EL COLOR DE FONDO DE LA CONSOLA

    do{
            rlutil::cls(); ///Limpia la pantalla cada vez que se elije una opción
            rlutil::locate(45,9); ///Ubicamos el texto en el medio de la pantalla
            std::cout<<"------------------------------"<<std::endl;
            rlutil::locate(45,10);
            std::cout<<"    JUGAR " << std::endl;
            rlutil::locate(45,11);
            std::cout<<"    ESTADISTICA " << std::endl;
            rlutil::locate(45,12);
            std::cout<<"    CREDITOS " << std::endl;
            rlutil::locate(45,13);
            std::cout<<"------------------------------"<<std::endl;
            rlutil::locate(45,14);
            std::cout<<"    SALIR " << std::endl;
            rlutil::locate(45,15);
            std::cout<<"------------------------------"<<std::endl;
            rlutil::locate(45,16);
            std::cout << (char)158 << std::endl;
            std::cin >> op;
            //std::system("pause");
            //std::system("cls");
    } while (op != 0);
*/

    //Inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jungle Jump");
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("pixel.ttf"); //Carga la fuente para visualizar el puntaje

    // Configuro texto
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);

    sf::SoundBuffer buffer;
    buffer.loadFromFile("bite.wav"); //Cargamos un efecto de sonido para la colision

    sf::Sound sound; //Es el canal por donde vamos a reproducir el audio
    sound.setBuffer(buffer);


    Personaje alan;

    /// Crea frutas y las pone en un vector
    std::vector<Fruta*> frutas = {new Banana(), new Maracuya(), new Bacaba(), new Camu()};

    /// Selecciona una fruta al azar para el primer respawn
    int indiceFrutaActual = std::rand() % frutas.size();
    Fruta* frutaActual = frutas[indiceFrutaActual];
    frutaActual->respawn();

    /// Crea el reloj para controlar el tiempo de respawn
    sf::Clock relojRespawn;
    sf::Time tiempoRespawn = sf::seconds(5);
    bool enRespawn = false;

    int puntos = 0;

    ///Creamos el fondo
    sf::Sprite image;
    sf::Texture tex;
    tex.loadFromFile("FONDO.png");

    image.setTexture(tex);



    ///Game Loop (update del juego) *Se subdivide internamente*

    while (window.isOpen())
    {
        /// 1° Read input - Actualiza los estados de los perifericos de entrada. ↓
        /// Leer la cola de mensajes

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /// 2° CMD (Leemos que se apreto y los ejecutamos)



        alan.cmd(); //Evaluamos los comandos


        /// 3° Update - Actualiza los estados del juego
        ///(Se puede manejar junto con CMD pero Brian prefiere separarlos)


        /// Actualizar los estados del juego
        alan.update();

         if (!enRespawn) {
            frutaActual->update();
        }

        if (enRespawn) {
            // Respawn aleatorio después de 5 segundos
            if (relojRespawn.getElapsedTime() >= tiempoRespawn) {
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
            // Comprueba colisiones
            if (alan.isCollision(*frutaActual)) {
                enRespawn = true;
                puntos += 50;
                sound.play();
                relojRespawn.restart(); // Reiniciar el reloj de respawn
            }
        }


        text.setString(std::to_string(puntos)); //Como los punto no son string, los convierte


        window.clear(); //Borra la pantalla para que no se superpongan objetos

        ///Dibujamos el fondo
        window.draw(image);



        /// 4° DRAW (muestra en la pantalla lo que hace update)

        /// Dibujar personaje y fruta actual
        window.draw(alan);
        window.draw(*frutaActual);
        window.draw(text);


        /// 5° Display - Flip
        window.display();




    }

    /// Liberacion del juego (Con SFML no hace falta)

    return 0;
}

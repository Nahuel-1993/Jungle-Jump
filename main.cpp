#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <ctime>
#include "Personaje.h"
#include "Banana.h"

int main()
{
    std::srand((unsigned)std::time(0));

    //Inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jungle Jump");
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("pixel.ttf"); //Cargamos la fuente para visualizar el puntaje

    // Configuro texto
    sf::Text text;
    text.setFont(font); //Cargo la fuente
    text.setCharacterSize(24); // Tamaño del texto
    text.setFillColor(sf::Color::White); // Color del texto
    text.setPosition(10, 10); // Posición del texto en la pantalla

    sf::SoundBuffer buffer;
    buffer.loadFromFile("bite.wav"); //Cargamos un efecto de sonido para la colision

    sf::Sound sound; //Es el canal por donde vamos a reproducir el audio
    sound.setBuffer(buffer);


    Personaje alan;
    Banana banana;
    banana.respawn();

    int puntos = 0;

    ///Creamos el fondo
    sf::Sprite image;
    sf::Texture tex;
    tex.loadFromFile("FONDO.png");

    image.setTexture(tex);



    //Game Loop (update del juego) *Se subdivide internamente*

    while (window.isOpen())
    {
        // 1° Read input - Actualiza los estados de los perifericos de entrada. ↓
        //Leer la cola de mensajes

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 2° CMD (Leemos que se apreto y los ejecutamos)



        alan.cmd(); //Evaluamos los comandos


        // 3° Update - Actualiza los estados del juego
        //(Se puede manejar junto con CMD pero Brian prefiere separarlos)

        alan.update(); //analiza el estado del personaje

        if(alan.isCollision(banana)){ //Si los obj colisionan hace un respawn del objeto recolectado
            banana.respawn();
            puntos += 50;
            sound.play();
        }

        text.setString(std::to_string(puntos)); //Como los punto no son string, los convierto


        window.clear(); //Borra la pantalla para que no se superpongan objetos

        ///Dibujamos el fondo
        window.draw(image);



        // 4° DRAW (muestra en la pantalla lo que hace update)

        window.draw(alan);
        window.draw(banana);
        window.draw(text);


        // 5° Display - Flip
        window.display();






    }

    // Liberacion del juego (Con SFML no hace falta)

    return 0;
}

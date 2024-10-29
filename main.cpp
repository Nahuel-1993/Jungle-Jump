#include <SFML/Graphics.hpp>
#include "Personaje.h"

int main()
{
    //Inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jungle Jump");
    window.setFramerateLimit(60);

    Personaje alan;


    sf::Sprite personaje;       //Declaro un sprite
    sf::Texture personaje_text; //Declaro su textura








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






        // 3° Update - Actualiza los estados del juego
        //(Se puede manejar junto con CMD pero Brian prefiere separarlos)

        alan.update();


        window.clear(); //Borra la pantalla para que no se superpongan objetos


        // 4° DRAW (muestra en la pantalla lo que hace update)


        window.draw(alan);



        // 5° Display - Flip
        window.display();






    }

    // Liberacion del juego (Con SFML no hace falta)

    return 0;
}

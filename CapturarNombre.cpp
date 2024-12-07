#include "CapturarNombre.h"

std::string capturarNombre(sf::RenderWindow& window, sf::Font& font) {
    // Creamos un objeto de texto vacío para mostrar lo que el jugador escribe
    sf::Text textoInput("", font, 30);
    textoInput.setFillColor(sf::Color::White);  // Configura el color del texto a blanco
    textoInput.setPosition(100, 250);


    sf::Text instrucciones("Ingrese su nombre y presione ENTER:", font, 15);  //Instrucciones del jugador
    instrucciones.setFillColor(sf::Color::White);
    instrucciones.setPosition(100, 200);

    std::string nombre;
    bool nombreIngresado = false;  //La usamos para verificar si ya se ingreso el nombre


    while (!nombreIngresado && window.isOpen()) { //Bucle de la ventana
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b' && !nombre.empty()) {  // Si se presiona "Backspace"
                    nombre.pop_back();  // Para borrar
                } else if (event.text.unicode == '\r') {  //ENTER Ascii
                    nombreIngresado = true;  // Finalizar la entrada
                } else {
                    nombre += static_cast<char>(event.text.unicode); //Agrega el carácter al nombre
                }
            }
        }

        // Actualiza el texto mostrado con lo que el jugador ha escrito
        textoInput.setString(nombre);

        window.clear();
        window.draw(instrucciones);
        window.draw(textoInput);

        window.display();
    }

    return nombre;  // Devuelve el nombre ingresado para usar en la clase Puntos
}

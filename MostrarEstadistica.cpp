#include "MostrarEstadistica.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "ArchivoEstadistica.h"

void mostrarEstadisticas(sf::RenderWindow& window, const std::vector<ArchivoEstadistica>& estadisticas, sf::Font& font) {
    sf::Text texto;
    texto.setFont(font);
    texto.setCharacterSize(24);
    texto.setFillColor(sf::Color::White);

    std::string resultado = "Mejores Puntajes:\n";


    ///Ordenamos de mayor amenor
    std::vector<ArchivoEstadistica> sorted_estadisticas = estadisticas;
    std::sort(estadisticas.begin(), estadisticas.end(),
        [](const ArchivoEstadistica& a, const ArchivoEstadistica& b) {
            return a.puntaje > b.puntaje;
        });

    size_t cantidad_mostrar = std::min(static_cast<size_t>(3), estadisticas.size());
    for (size_t i = 0; i < cantidad_mostrar; ++i) {
            resultado += sorted_estadisticas[i].nombre + ": " + std::to_string(sorted_estadisticas[i].puntaje) + "\n";
    }

    texto.setString(resultado);

    window.clear();
    window.draw(texto);
    window.display();

    sf::Event event;
    while (window.waitEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Enter) {
                break; ///Volvemosal menu principal
            }
        }
    }
}

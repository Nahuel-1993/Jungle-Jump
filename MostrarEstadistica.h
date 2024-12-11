#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "ArchivoEstadistica.h"

void mostrarEstadisticas(sf::RenderWindow& window, const std::vector<ArchivoEstadistica>& estadisticas, sf::Font& font);


#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

class MenuSFML {
public:
    MenuSFML();
    void draw(sf::RenderWindow& window);
    void handleInput(sf::RenderWindow& window, int& op);
    void setBackground(const std::string& backgroundImagePath);
    void setMusic(const std::string& musicFilePath);
    void stopMusic();


private:
    sf::Font font;
    sf::Text opciones[4];
    int seleccion;
    std::string textoOpciones[4];
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Music menuMusic;
};

#include "MenuSFML.h"

MenuSFML::MenuSFML() : seleccion(0), textoOpciones{"JUGAR", "ESTADISTICA", "CREDITOS", "SALIR"} {
    font.loadFromFile("pixel.ttf");
    for (int i = 0; i < 4; ++i) {
        opciones[i].setFont(font);
        opciones[i].setString(textoOpciones[i]);
        opciones[i].setCharacterSize(24);
        opciones[i].setFillColor(sf::Color::White);
        opciones[i].setPosition(10, 200 + i * 50);
    }
}

void MenuSFML::setBackground(const std::string& backgroundImagePath) {
    backgroundTexture.loadFromFile(backgroundImagePath);
    backgroundSprite.setTexture(backgroundTexture);
}

void MenuSFML::setMusic(const std::string& musicFilePath) {
    menuMusic.openFromFile(musicFilePath);
    menuMusic.setLoop(true);
    menuMusic.play();
    menuMusic.setVolume(30);
}

void MenuSFML::draw(sf::RenderWindow& window) {
    window.draw(backgroundSprite); // Dibujar el fondo

    for (int i = 0; i < 4; ++i) {
        if (i == seleccion) {
            opciones[i].setFillColor(sf::Color::Red);
        } else {
            opciones[i].setFillColor(sf::Color::White);
        }
        window.draw(opciones[i]);
    }
}

void MenuSFML::handleInput(sf::RenderWindow& window, int& op) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                seleccion = (seleccion - 1 + 4) % 4;
            }
            if (event.key.code == sf::Keyboard::Down) {
                seleccion = (seleccion + 1) % 4;
            }
            if (event.key.code == sf::Keyboard::Enter) {
                if (seleccion == 0) {
                    op = 0; // JUGAR
                } else if (seleccion == 1) {
                    op = 1; // ESTADISTICA
                } else if (seleccion == 2) {
                    op = 2; // CREDITOS
                } else if (seleccion == 3) {
                    window.close(); // SALIR
                }
            }
        }
    }
}

void MenuSFML::mostrarCreditos(sf::RenderWindow& window) {
    sf::Text creditsText;
    creditsText.setFont(font);
    creditsText.setString("Creditos:\n\nDesarrolladores:\nNahuel Feijoo\nEugenia Sanchez \n\nTrabajo Practico Final\nProgramacion II \n\nUTN Pacheco 2024 tm. \n\n\nGRACIAS POR JUGAR!");
    creditsText.setCharacterSize(24);
    creditsText.setFillColor(sf::Color::White);
    creditsText.setPosition(50, 50);

    // Bucle para mostrar los cr�ditos
    bool showingCredits = true;
    while (showingCredits) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                showingCredits = false;
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    showingCredits = false;
                }
            }
        }
        window.clear(sf::Color::Black);
        window.draw(creditsText);
        window.display();
    }
}

void MenuSFML::stopMusic() {
    menuMusic.stop();
}

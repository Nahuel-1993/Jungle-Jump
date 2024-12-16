#include "Personaje.h"
#include "Plataforma.h"
#include "Vidas.h"
#include <iostream>

Personaje::Personaje()
{
    //_velocity = {4,4}; //inicializo velocity para luego analizarla en update y cambiar la orientacion del personaje
    _texture.loadFromFile("alan.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height);
    _sprite.setPosition(100, 500);
    _estado = ESTADOS_PERSONAJE::QUIETO;
    _velocidadSalto = 0;
}


void Personaje::cmd() {
    if (_estado != ESTADOS_PERSONAJE::SALTANDO && _estado != ESTADOS_PERSONAJE::SALTANDO_ADELANTE && _estado != ESTADOS_PERSONAJE::SALTANDO_ATRAS) {
        _estado = ESTADOS_PERSONAJE::QUIETO; // Estado predeterminado
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            _estado = ESTADOS_PERSONAJE::SALTANDO_ADELANTE;
            _velocidadSalto = 13;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            _estado = ESTADOS_PERSONAJE::SALTANDO_ATRAS;
            _velocidadSalto = 13;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            _estado = ESTADOS_PERSONAJE::SALTANDO;
            _velocidadSalto = 13;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            _estado = ESTADOS_PERSONAJE::CAMINANDO_ADELANTE;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            _estado = ESTADOS_PERSONAJE::CAMINANDO_ATRAS;
        }
    }
}


bool enPlataforma = false;

void Personaje::update() {

    switch (_estado) {
        case QUIETO:
            //std::cout<<"EN QUIETO"<< enPlataforma << std::endl;
            if(!enPlataforma){
            _velocidadSalto -= 0.5; /// Aplicamos gravedad
            _sprite.move(0, -_velocidadSalto);
            }
            if (_sprite.getPosition().y >= 600) { ///Si el personaje está en el piso
                _sprite.setPosition(_sprite.getPosition().x, 600);
                _velocidadSalto = 0;
                _estado = ESTADOS_PERSONAJE::QUIETO;
                //_vidas.perderVida();
                //std::cout<<"Alan está en el piso en personaje.cpp"<<std::endl;
            }
            break;
        case CAMINANDO_ADELANTE:
            _velocidadSalto -= 0.5;
            _sprite.move(5, 0);
            _sprite.setScale(1, 1);
            if (_sprite.getPosition().y >= 600) {
                _sprite.setPosition(_sprite.getPosition().x, 600);
                _estado = ESTADOS_PERSONAJE::QUIETO;
                _velocidadSalto = 0;
            }
            break;
        case CAMINANDO_ATRAS:
            _sprite.move(-5, 0);
            _sprite.setScale(-1, 1);
            if (_sprite.getPosition().y >= 600) {
                _sprite.setPosition(_sprite.getPosition().x, 600);
                _estado = ESTADOS_PERSONAJE::QUIETO;
                _velocidadSalto = 0;
            }
            break;
        case SALTANDO:
            _velocidadSalto -= 0.5;
            _sprite.move(0, -_velocidadSalto);
            if (_sprite.getPosition().y >= 600) {
                _sprite.setPosition(_sprite.getPosition().x, 600);
                _estado = ESTADOS_PERSONAJE::QUIETO;
                _velocidadSalto = 0;
            }
            break;
        case SALTANDO_ADELANTE:
            _velocidadSalto -= 0.5;
            _sprite.move(5, -_velocidadSalto);
            _sprite.setScale(1, 1);
            if (_sprite.getPosition().y >= 600) {
                _sprite.setPosition(_sprite.getPosition().x, 600);
                _estado = ESTADOS_PERSONAJE::QUIETO;
                _velocidadSalto = 0;
            }
            break;
        case SALTANDO_ATRAS:
            _velocidadSalto -= 0.5;
            _sprite.move(-5, -_velocidadSalto);
            _sprite.setScale(-1, 1);
            if (_sprite.getPosition().y >= 600) {
                _sprite.setPosition(_sprite.getPosition().x, 600);
                _estado = ESTADOS_PERSONAJE::QUIETO;
                _velocidadSalto = 0;
            }
            break;
        default:
            break;
    }
    if (enPlataforma){
        _sprite.move(0, 2);
    }

    //Para evitar que salga de la pantalla:
    if (_sprite.getGlobalBounds().left < 0) {
        _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
    }
    if (_sprite.getGlobalBounds().top < 0) {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
    }
    if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800) {
        _sprite.setPosition(800 - (_sprite.getGlobalBounds().width - _sprite.getOrigin().x), _sprite.getPosition().y);
    }
    if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 600) {
        _sprite.setPosition(_sprite.getPosition().x, 600 + (_sprite.getGlobalBounds().height - _sprite.getOrigin().y));
    }
}

void Personaje::setEstado(ESTADOS_PERSONAJE nuevoEstado) {
    _estado = nuevoEstado;
}

void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

 sf::FloatRect Personaje::getBounds() const {
    return _sprite.getGlobalBounds(); //Hacemos un get de globalBounds porque devuelve un FloatRect que es lo
}                                     //que necesita getBounds()

const sf::Sprite& Personaje::getDraw() const {
    return _sprite;
}
sf::Sprite& Personaje::getSprite() {
    return _sprite;
}
void Personaje::setVelocidadSalto(float velocidad) {
    _velocidadSalto = velocidad;  ///Modificamos la velocidad de salto para arreglar la colisión con las plataformas
    }
    float Personaje::getVelocidadSalto() const {
    return _velocidadSalto; ///Devolvemos la velocidad de salto para la colision de plataformas
    }
int Personaje::getVidas() const {
    return _vidas.getVidas();
}
void Personaje::perderVida() {
    _vidas.perderVida();
}

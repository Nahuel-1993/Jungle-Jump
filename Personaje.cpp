#include "Personaje.h"

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

void Personaje::cmd(){

    //Para mover al personaje:

        //_velocity = {0,0};

        //_estado = ESTADOS_PERSONAJE::QUIETO;



        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            _estado = ESTADOS_PERSONAJE::SALTANDO;
            _velocidadSalto = 10;
        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            _estado = ESTADOS_PERSONAJE::CAMINANDO_ADELANTE;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            _estado = ESTADOS_PERSONAJE::CAMINANDO_ATRAS;
        }


       // _sprite.move(_velocity); //Velocity me dice hacia donde esta yendo el personaje
}
void Personaje::update(){

    switch(_estado){
    case QUIETO:
        //Aca programamos si hace algo estando quieto (respirar x ejemplo)
        break;
    case CAMINANDO_ADELANTE:
        _sprite.move(5,0);
        _estado = ESTADOS_PERSONAJE::QUIETO;
        break;
    case CAMINANDO_ATRAS:
        _sprite.move(-5,0);
        _estado = ESTADOS_PERSONAJE::QUIETO;
        break;
    case SALTANDO:
        _velocidadSalto -= 2;
        _sprite.move(0, -_velocidadSalto);
        break;
    default:
        break;
    }

    //Para orientar al personaje segun hacia que lado esta desplazandose:
/*
        if(_velocity.x < 0){
            _sprite.setScale(-1,1);
        }
        else if(_velocity.x > 0){
            _sprite.setScale(1,1);
        }
*/
    //Para evitar que salga de la pantalla:

        if(_sprite.getGlobalBounds().left < 0){                                         //Lo vuelvo a setear dentro de los limites
           _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);       // y lo dejo igual con el get de y.
        }
        if(_sprite.getGlobalBounds().top < 0){
           _sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
        }
        if(_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800){
           _sprite.setPosition(800 - (_sprite.getGlobalBounds().width - _sprite.getOrigin().x), _sprite.getPosition().y);
        }
        if(_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 600){
           _sprite.setPosition(_sprite.getPosition().x, 600 + (_sprite.getGlobalBounds().height - _sprite.getOrigin().y));
        }
}


void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

 sf::FloatRect Personaje::getBounds() const {
    return _sprite.getGlobalBounds(); //Hacemos un get de globalBounds porque devuelve un FloatRect que es lo
                                      //que necesita getBounds()
 }

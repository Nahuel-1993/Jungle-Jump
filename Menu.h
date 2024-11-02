#pragma once
#include <iostream>
#include "rlutil.h"

void Menu(){
    void enter(int *y, int *op);
int op=1, y =0;
    rlutil::setBackgroundColor(rlutil::GREEN); ///CAMBIAMOS EL COLOR DE FONDO DE LA CONSOLA
    rlutil::hidecursor(); ///Ocultamos el cursor para que no se vea al lado
    do{
            ///Debería comentarlo para que no titlé la pantalla cuando muevo el cursor, pero cuando lo hago se sale lo verde
            rlutil::cls(); ///Limpia la pantalla cada vez que se elije una opción
            rlutil::setBackgroundColor(rlutil::GREEN); ///CAMBIAMOS EL COLOR DE FONDO DE LA CONSOLA

            rlutil::locate(48,9); ///Ubicamos el texto en el medio de la pantalla
            std::cout<<"----------------------"<<std::endl;
            rlutil::locate(55,10);
            std::cout<<"JUGAR " << std::endl;
            rlutil::locate(55,11);
            std::cout<<"ESTADISTICA " << std::endl;
            rlutil::locate(55,12);
            std::cout<<"CREDITOS " << std::endl;
            rlutil::locate(55,14);
            std::cout<<"SALIR " << std::endl;
            rlutil::locate(48,15);
            std::cout<<"----------------------"<<std::endl;
            rlutil::locate(53,10 + y);
            std::cout << (char)158 << std::endl;

            switch (rlutil::getkey()){

                case 14: ///Arriba
                    rlutil::locate(53,10 + y);
                    std::cout << " " << std::endl;///Dibujamos un espacio en el lugar del cursor para que no titile la pantalla
                    y--;
                    if (y<0){ y = 0;}
                    break;
                case 15: ///Abajo
                    rlutil::locate(53,10 + y);
                    std::cout << " " << std::endl;
                    y++;
                    if(y>4){ y =4; }///Con esto evitamos que sevaya más abajo de las opciones
                    break;
                case 1: ///Enter
                    enter(&y, &op);
                    break;
                default:
                    break;
            }
    }while (op != 0);
}
void enter(int *y, int *op){
        switch (*y){
                case 2:
                    std:: system("cls");
                    rlutil::locate(48,9);
                    std::cout<< "-------::JUNGLE - JUMP::------- " << std::endl;
                    rlutil::locate(48, 10);
                    std::cout<< "\n"<<std::endl;
                    rlutil::locate(50,11);
                    std::cout<< "Feijoo Nahuel, "<< std::endl;
                    rlutil::locate(50, 12);
                    std::cout<< "Sanchez Eugenia, 27704"<<std::endl;
                    rlutil::locate(48, 13);
                    std::cout<< "\n"<<std::endl;
                    rlutil::locate(40, 14);
                    std::cout<< "PRESIONE ENTER PARA VOLVER AL MENU PRINCIPAL"<<std::endl;
                    if (rlutil::getkey() == 1){ op = 0;}

                case 4:
                     op=0;
                     break;
                default:
                     break;
            }


}

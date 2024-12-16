#include "ArchivoEstadistica.h"
#include <iostream>
#include <fstream>
#include <cstring>


bool ArchivoEstadistica::grabarRegistroEstadistica(){
        FILE *pEstadistica; ///Puntero FILE que nos conecta con el archivo fisico
        pEstadistica = fopen ("estadistica.dat", "ab"); ///Abrimos el archivo

        if(pEstadistica == NULL) return false;

        int escribio = fwrite(this, sizeof (ArchivoEstadistica), 1, pEstadistica); ///fwrite(&VARIABLE, TAMAÑO_VARIABLE, CANTIDAD_REGISTROS, PUNTEROFILE)

        fclose(pEstadistica);
        return escribio;
    }

void ArchivoEstadistica::setDatos(const char* nombreJugador, int puntosJugador) {
    nombre = new char[ strlen(nombreJugador)+1];
    if (nombre == NULL){
        std::cout<< "Error de asignación de memoria" <<std::endl;
            return;
    }
    strncpy(nombre, nombreJugador, strlen(nombreJugador) + 1); ///Copiamos el valoer
    puntaje = puntosJugador;

}

std::string ArchivoEstadistica::leerRegistroEstadistica(){
    FILE *pEstadistica;
    pEstadistica=fopen("estadistica.dat", "rb");
    if(pEstadistica==NULL) return "false";

    fclose(pEstadistica);
    return " ";
}


///DESTRUCTOR
ArchivoEstadistica::~ArchivoEstadistica(){
    delete[] nombre;
}

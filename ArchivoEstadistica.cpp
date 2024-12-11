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

std::string ArchivoEstadistica::leerRegistroEstadistica(){
    FILE *pEstadistica;
    pEstadistica=fopen("estadistica.dat", "rb");
    if(pEstadistica==NULL) return "false";
    /*int leyo=fread(this, sizeof(ArchivoEstadistica), 1,pEstadistica);
    fclose(pEstadistica);
    return leyo;*/
    ///cAMBIAMOS A UN BUFFER PORQUE LA FUNCIÓN DEVOLVÍA UN BOOL Y NECESITANBAMOS UN STRING
    char buffer[512];
    size_t bytesRead = fread(buffer, sizeof(char), sizeof(buffer), pEstadistica);
    fclose(pEstadistica);

    return std::string(buffer, bytesRead);
}
void ArchivoEstadistica::setDatos(const char* nombreJugador, int puntosJugador) {
    char destino[100];
    size_t tamanio = sizeof(destino);
    strncpy(destino, nombreJugador, tamanio);
    nombre[sizeof(nombre) - 1] = '\0';
    int puntos = puntosJugador;
}

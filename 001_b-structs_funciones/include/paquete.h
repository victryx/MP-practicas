#ifndef PAQUETE_H
#define PAQUETE_H

#include <string>

struct Paquete
{
    int origen;
    int destino;
    int peso;
    Paquete() : origen(0), destino(0), peso(0) {}
};

std::string toString(const Paquete &paquete);
Paquete creaPaquete(int origen, int destino, int peso);
bool esValido(const Paquete &paquete);

#endif
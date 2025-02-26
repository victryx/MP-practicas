#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#include <string>
#include "paquete.h"

struct Contenedor {
    static const int MAX = 100;
    Paquete lista[MAX];
    int peso = 0;
    int index = 0;
};

bool agregaPaquete(Contenedor &c, const Paquete &p);
void mostrarContenedor(const Contenedor &c);
double calcularPeso(const Contenedor &c);
Contenedor obtienePaquetes(const Contenedor &c, int origen);
void ordenar(Contenedor &c);
void enviosDestino(const Contenedor &c, int destino, int &contador, float &kilos);
void analisisDestinos(Contenedor &c);

#endif
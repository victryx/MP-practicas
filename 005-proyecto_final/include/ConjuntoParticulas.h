#ifndef CONJUNTO_PARTICULAS_H
#define CONJUNTO_PARTICULAS_H

#include "Particula.h"
#include <string>

const int TAM_BLOQUE = 3; // dentro de la clase?

class ConjuntoParticulas {
private:
    Particula* set = nullptr; // ¿hacer aquí la asignación es igual que ponerla al principio del constructor?
    int capacidad = 0;
    int utiles = 0;

    void liberaMemoria();

    void reservaMemoria();

    void redimensiona(int nuevaCapacidad);

public:
    ConjuntoParticulas(int n = 0);

    ConjuntoParticulas(const ConjuntoParticulas &otro);

    ~ConjuntoParticulas();

    int getUtiles();

    int getCapacidad();

    void agregar(const Particula &ppart);

    /// @brief Elimina la partícula en la posición pos del array 
    /// @param pos 
    /// @return La partícula eliminada
    Particula borrar(int pos);

    /// @brief Devuelve una referencia a la partícula en la posición pos del array
    /// @param pos 
    /// @return 
    Particula& obtener(int pos);

    Particula reemplazar(int pos, const Particula &part);

    void mover(int tipo = 0);

    void gestionarColisiones();

    std::string toString();

};

#endif
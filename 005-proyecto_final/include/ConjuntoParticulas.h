#ifndef CONJUNTO_PARTICULAS_H
#define CONJUNTO_PARTICULAS_H

#include "Particula.h"
#include <string>

const int TAM_BLOQUE = 3; // dentro de la clase? sí

class ConjuntoParticulas {
private:
    Particula* set = nullptr; // ¿hacer aquí la asignación es igual que ponerla al principio del constructor? sí
    int capacidad = 0;
    int utiles = 0;

    void liberaMemoria();

    void reservaMemoria();

    void redimensiona(int nuevaCapacidad);

public:
    ConjuntoParticulas(int n = 0);

    ConjuntoParticulas(const ConjuntoParticulas &otro);

    ~ConjuntoParticulas();

    int getUtiles() const;

    int getCapacidad() const;

    void agregar(const Particula &part);

    /// @brief Elimina la partícula en la posición pos del array 
    /// @param pos 
    /// @pre 0 <= pos < utiles
    void borrar(int pos);

    /// @brief Devuelve una referencia a la partícula en la posición pos del array
    /// @param pos posición de la partícula
    /// @return 
    /// @pre 0 <= pos < utiles
    const Particula &obtener(int pos) const;

    /// @brief Sobreescribe la particula en la posición pos por la particula part
    /// @param pos Posición de la particula sobreescrita
    /// @param part Nueva partícula
    void reemplazar(int pos, const Particula &part);

    /// @brief Si tipo = 0, se le aplica a cada partícula el método mover.
    ///        si tipo = 1, se le aplica a cada partícula el método mover seguido de rebotar.
    ///        si tipo = 2, se le aplica a cada partícula el método mover seguido de wrap.
    /// @param tipo Tipo de movimiento, por defecto 0
    void mover(int tipo = 0);

    /// @brief Por cada PAR de partículas, evalua si estas colisionan y chocan
    void gestionarColisiones();

    /// @brief Devuelve una representación en texto del objeto
    /// @return 
    std::string toString();

};

#endif
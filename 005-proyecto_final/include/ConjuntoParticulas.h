#ifndef CONJUNTO_PARTICULAS_H
#define CONJUNTO_PARTICULAS_H

#include "Particula.h"
#include <string>

const int TAM_BLOQUE = 3; 

class ConjuntoParticulas {
private:
    Particula* set = nullptr; 
    int capacidad = 0;
    int utiles = 0;

    /// @brief Libera la memoria dinámica utilizada por este objeto
    void liberaMemoria();

    /// @brief Reserva la memoria dinámica que utiliza este objeto
    /// @param capacidad Capacidad inicial del conjunto
    /// @pre capacidad >= 0
    void reservaMemoria(int capacidad);

    /// @brief Copia los datos del conjunto 'otro' a este conjunto
    /// @param otro Conjunto del que se copian los datos
    void copia(const ConjuntoParticulas &otro);
    
    /// @brief Redimensiona el conjunto de partículas
    /// @param nuevaCapacidad Nueva capacidad del conjunto
    /// @pre nuevaCapacidad >= utiles
    void redimensiona(int nuevaCapacidad);

public:
    /// @brief Si n <= 0, crea un conjunto vacío. Si n > 0, crea un conjunto 
    ///        con n elementos
    /// @param n Capacidad inicial del conjunto, por defecto 0.
    ConjuntoParticulas(int n = 0);

    ConjuntoParticulas(const ConjuntoParticulas &otro);

    ~ConjuntoParticulas();

    int getUtiles() const;

    int getCapacidad() const;

    /// @brief Añade la particula part al conjunto de partículas
    /// @param part particula que se añade al conjunto
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

    /// @brief Transforma el conjunto de partículas en un string
    /// @return Una representación en texto de la partícula
    std::string toString();

};

#endif
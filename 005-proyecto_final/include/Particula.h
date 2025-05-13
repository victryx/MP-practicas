#ifndef PARTICULA_H
#define PARTICULA_H

#include "Vector2D.h"

class Particula
{
private:
    Vector2D pos;
    Vector2D acel;
    Vector2D veloc;
    float radio;
    int tipo;

    /// @brief Comprueba si la partícula choca con el límite superior del mapa
    bool chocaNorte();

    /// @brief Comprueba si la partícula choca con el límite inferior del mapa
    bool chocaSur();

    /// @brief Comprueba si la partícula choca con el límite derecho del mapa
    bool chocaEste();

    /// @brief Comprueba si la partícula choca con el límite izquierdo del mapa
    bool chocaOeste();

    /// @brief Genera un número aleatorio entre min y max
    /// @param min 
    /// @param max 
    /// @return Un número aleatorio
    /// @pre min < max
    float aleatorio(float min, float max);

    /// @brief Ajusta el valor val para que esté en el intervalo definido por
    ///        limiteInferior y limiteSuperior
    /// @param val Valor a ajustar
    /// @param limiteInferior valor mínimo
    /// @param limiteSuperior valor máximo
    /// @return 
    float ajustarValor(float val, float limiteInferior, float limiteSuperior);

    /// @brief Ajusta la posición de la partícula a los límites del mundo
    void ajustarPosicion();

    /// @brief Ajusta la velocidad de la partícula a los límites establecidos
    void ajustarVelocidad();

public:

    /// @brief Constructor de partícula
    ///
    /// Si tipoPart != 0, se crea una particula con radio 3 y con posición,
    /// aceleración y velocidad iguales a 0.
    /// Si tipoPart = 0, posición, aceleración, velocidad y radio se eligen
    /// de forma aleatoria según los parámetros de params.h
    ///
    /// @param tipoPart Tipo de particula, por defecto 0
    Particula(int tipoPart = 0);

    Particula(const Vector2D &_pos, const Vector2D &_acel, const Vector2D &_veloc, float _radio, int _tipo);

    Vector2D getPos() const;
    Vector2D getAcel() const;
    Vector2D getVeloc() const;
    float getRadio() const; 

    void setPos(const Vector2D &_pos);
    void setAcel(const Vector2D &_acel);
    void setVeloc(const Vector2D &_veloc);
    void setRadio(int _radio);

    /// @brief Actualiza la posición de la partícula en función de su 
    /// aceleración y de su velocidad.
    void mover();

    /// @brief Actualiza la velocidad de la partícula SI esta está colisionando 
    /// con alguno de los límites del mundo
    void rebotar();

    /// @brief Comprueba si esta partícula esta colisionando con otra
    /// @param otro partícula con la que se comprueba la colisión
    /// @return true si esta partícula colisiona con la que se pasa como parámetro,
    ///         false en caso contrario
    bool colision(const Particula &otro);

    /// @brief Simula el choque elástico entre dos partículas
    /// @param otro 
    void choque(Particula &otro);

    /// @brief Transforma la partícula en string
    /// @return Una representación en texto de la partícula
    std::string toString() const;

    /// @brief Si la partícula está colisionando con uno de los bordes, la mueve
    ///        al borde opuesto
    void wrap();
};

#endif
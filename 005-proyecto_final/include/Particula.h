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
    bool chocaNorte() const;

    /// @brief Comprueba si la partícula choca con el límite inferior del mapa
    bool chocaSur() const;

    /// @brief Comprueba si la partícula choca con el límite derecho del mapa
    bool chocaEste() const;

    /// @brief Comprueba si la partícula choca con el límite izquierdo del mapa
    bool chocaOeste() const;

    /// @brief Ajusta el valor val para que esté en el intervalo definido por
    ///        limiteInferior y limiteSuperior
    /// @param val Valor a ajustar
    /// @param limiteInferior valor mínimo
    /// @param limiteSuperior valor máximo
    /// @return Valor ajustado
    float ajustarValor(float val, float limiteInferior, float limiteSuperior) const;

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

    bool operator==(const Particula &otro) const;

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
    bool colision(const Particula &otro) const;

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

/// @brief Lectura de un objeto Particula con el formato
///        @Particula: {(240.56,94.00),(-3.91,-3.70),(-0.16,0.29),8.0,1}
std::istream &operator>>(std::istream &flujo, Particula &part);

/// @brief Escritura de un objeto Particula con el formato
///        @Particula: {(240.56,94.00),(-3.91,-3.70),(-0.16,0.29),8.0,1}
std::ostream &operator<<(std::ostream &flujo, const Particula &part);


#endif
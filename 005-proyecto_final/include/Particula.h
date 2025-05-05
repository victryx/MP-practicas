#ifndef PARTICULA_H
#define PARTICULA_H

#include "Vector2D.h"
#include "utils.h"

class Particula
{
private:
    Vector2D pos;
    Vector2D acel;
    Vector2D veloc;
    float radio;
    int tipo;
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
    void setAcel(const Vector2D &_pos);

};


#endif
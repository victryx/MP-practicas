#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <string>
#include <iostream>
#include "params.h"
#include "utils.h"
#include <cmath>

class Vector2D {
private:
    float x, y;

public:
    /// @brief Constructor de Vector2D
    /// @param _x Valor de la coordenada x, por defecto 0
    /// @param _y Valor de la coordenada y, por defecto 0
    Vector2D(float _x = 0, float _y = 0);

    bool operator==(const Vector2D &otro) const;
    Vector2D &operator+=(const Vector2D &otro);

    float getX() const;
    float getY() const;

    void setX(float _x);
    void setY(float _y);

    /// @brief Actualiza los valores de las dos coordenadas simultáneamente
    /// @param _x Nuevo valor de la coordenada X
    /// @param _y Nuevo valor de la coordenada Y
    void setXY(float _x, float _y);

    /// @brief Recibe un vector como parámetro y se lo suma al vector actual
    /// @param otro Vector sumado a este vector
    void sumar(const Vector2D &otro);

    /// @brief suma el valor _x a la componente X del vector
    void sumarX(float _x);

    /// @brief suma el valor _y a la componente Y del vector
    void sumarY(float _y);
    
    /// @brief Multiplica este vector por el valor recibido como parámetro
    /// @param val Valor por el que es multiplicado el vector
    void escalar(float val);

    /// @brief Calcula el módulo de este vector
    /// @return El módulo de este vector
    float modulo() const;
    
    /// @brief Normaliza el vector
    ///
    /// divide cada componente por el módulo del vector,
    /// para conseguir un vector con módulo 1.
    void normalizar();

    /// @brief Calcula la distancia entre este vector y 'otro'
    /// @param otro 
    /// @return Distancia entre los dos vectores
    float distancia(const Vector2D &otro) const;

    /// @brief Devuelve los datos de este vector como un string
    /// @return Un string con formato "(x,y)"
    std::string toString() const;
};

std::ostream &operator<<(std::ostream &flujo, const Vector2D &vector);
std::istream &operator>>(std::istream &flujo, Vector2D &vector);

#endif
#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <string>

class Vector2D {
private:
    float x, y;

public:
    /// @brief Constructor de Vector2D
    /// @param _x Valor de la coordenada x, por defecto 0
    /// @param _y Valor de la coordenada y, por defecto 0
    Vector2D(float _x = 0, float _y = 0);

    /// @brief
    /// @return Valor de la coordenada x
    float getX() const;

    /// @brief 
    /// @return Valor de la coordenada y
    float getY() const;

    /// @brief
    /// @param _x Nuevo valor de la coordenada X
    void setX(float _x);

    /// @brief
    /// @param _y Nuevo valor de la coordenada Y

    void setY(float _y);

    /// @brief
    /// @param _x Nuevo valor de la coordenada X
    /// @param _y Nuevo valor de la coordenada Y
    void setXY(float _x, float _y);

    /// @brief Recibe un vector como parámetro y se lo suma al vector actual
    /// @param otro Vector sumado a este vector
    void sumar(const Vector2D &otro);
    
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

    /// @brief Devuelve los datos de este vector como un string
    /// @return Un string con formato "(x,y)"
    std::string toString();
};

#endif
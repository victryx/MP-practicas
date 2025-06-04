#ifndef UTILS_H
#define UTILS_H

#include <cmath>

/// @brief Comprueba si dos valores float son iguales teniendo en cuenta una
///        variación (epsilon)
bool inline floatEqual(float a, float b, float epsilon) {
    return fabsf(a - b) <= epsilon;
}

/// @brief Genera un número aleatorio entre min y max
/// @pre min < max
float aleatorio(float min, float max);

#endif
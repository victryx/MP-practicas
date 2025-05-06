#ifndef UTILS_H
#define UTILS_H

#include "Vector2D.h"

/// @brief Genera un número aleatorio entre min y max
/// @param min 
/// @param max 
/// @return Un número generado de forma aleatoria
float aleatorio(float min, float max);

/// @brief 
/// @param minX 
/// @param maxX 
/// @param minY 
/// @param maxY 
/// @return 
Vector2D vectorAleatorio(float minX, float maxX, float minY, float maxY);

/// @brief Devuelve el menor de los dos valores pasados como parámetro
/// @param a 
/// @param b 
/// @return 
float min(float a, float b);

/// @brief Devuelve el mayor de los dos valores pasados como parámetro
/// @param a 
/// @param b 
/// @return 
float max(float a, float b);

/// @brief Ajusta el valor val para que esté en el intervalo definido por
///        limiteInferior y limiteSuperior
/// @param val 
/// @param limiteInferior 
/// @param limiteSuperior 
/// @return 
float ajustarValor(float val, float limiteInferior, float limiteSuperior);

#endif
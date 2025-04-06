#ifndef FUNC_ARRAYS_H
#define FUNC_ARRAYS_H

const int TAM_BLOQUE = 4;

/// @brief Aumenta el tamaño de un array dinámico
/// @param p array a redimensionar
/// @param util cantidad de elementos útiles del array
/// @param tipo 1 - aumenta la capacidad en uno.
///             2 - aumenta la capacidad un número fijo de elementos definido
///                 por la constante TAM_BLOQUE.
///             3 - duplica la capacidad
///             para cualquier otro valor de tipo, el array se redimensiona con
///             la modalidad 1
/// @param cap capacidad del array
void redimensiona(int *&p, int util, int tipo, int &cap);

/// @brief Devuelve la unión de los conjuntos v1 y v2, es decir, todos los
///        elementos de v1 y v2 sin repeticiones
/// @param v1 Array sin elementos repetidos
/// @param v2 Array sin elementos repetidos
/// @param n1 Tamaño de v1
/// @param n2 Tamaño de v2
/// @param unionSize Tamaño del array de unión
/// @return Unión entre v1 y v2
int *unir(const int *v1, const int *v2, int n1, int n2, int &unionSize);

/// @brief Devuelve la intersección entre los conjuntos v1 y v2, es decir,
///        los elementos que estén presentes en ambos conjuntos
/// @param v1 Array sin elementos repetidos
/// @param v2 Array sin elementos repetidos
/// @param n1 Tamaño de v1
/// @param n2 Tamaño de v2
/// @param intersectionSize Tamaño del array intersección
/// @return Intersección entre v1 y v2
int *interseccion(const int *v1, const int *v2, int n1, int n2, int &intersectionSize);

/// @brief Devuelve un array que contiene los múltiplos de nro que aparecen en v
/// @param v Array de enteros
/// @param n Tamaño del array v 
/// @param nro 
/// @param multiplos Array de múltiplos de nro
/// @param multiplosSize Tamaño del array multiplos
void multiplos(const int *v, int n, int nro, int *&multiplos, int &multiplosSize);

#endif
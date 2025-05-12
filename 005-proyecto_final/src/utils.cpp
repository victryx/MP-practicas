#include "utils.h"
#include <cstdlib>
#include <cmath>
#include <cassert>

float aleatorio(float min, float max) {
    assert(min <= max);
    float r = rand() / static_cast<float> (RAND_MAX); // entre 0 y 1?
    float rango = max - min;
    return (r * rango + min);
}

// No hace falta
Vector2D vectorAleatorio(float minX, float maxX, float minY, float maxY) {
    assert(minX <= maxX && minY <= maxY);
    int x = aleatorio(minX, maxX);
    int y = aleatorio(minY, maxY);
    return Vector2D(x,y);
}

float min(float a, float b) {
    return a < b ? a : b;
}

float max(float a, float b) {
    return a > b ? a : b;
}

// En partícula 
float ajustarValor(float val, float limiteInferior, float limiteSuperior) {
    assert(limiteInferior <= limiteSuperior);
    return max(limiteInferior, min(limiteSuperior, val));
}

bool floatEquals(float a, float b, float epsilon) {
    return fabsf(a - b) <= epsilon;
}
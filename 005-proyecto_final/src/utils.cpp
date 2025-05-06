#include "utils.h"
#include <cstdlib>

float aleatorio(float min, float max) {
    float r = rand() / static_cast<float> (RAND_MAX);
    float rango = max - min;
    return (r * rango + min);
}

Vector2D vectorAleatorio(float minX, float maxX, float minY, float maxY) {
    int x = aleatorio(minX, maxX);
    int y = aleatorio(minY, maxY);
    Vector2D v(x,y);
    return v;
}

float min(float a, float b) {
    return a < b ? a : b;
}

float max(float a, float b) {
    return a > b ? a : b;
}

float ajustarValor(float val, float limiteInferior, float limiteSuperior) {
    return max(limiteInferior, min(limiteSuperior, val));
}
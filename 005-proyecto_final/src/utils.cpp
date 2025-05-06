#include "utils.h"

float aleatorio(float min, float max) {
    // TODO: usar rand()
    float r = 0.5; // rand() / static_cast<float> (RAND_MAX);
    float rango = max - min;
    return (r * rango + min);
}

Vector2D vectorAleatorio(float minX, float maxX, float minY, float maxY) {
    int x = aleatorio(minX, maxX);
    int y = aleatorio(minY, maxY);
    Vector2D v(x,y);
    return v;
}
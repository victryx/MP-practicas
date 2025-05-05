#include "utils.h"

float aleatorio(float min, float max) {
    // TODO: usar rand()
    float r = 3.0; // rand() / static_cast<float> (RAND_MAX);
    float rango = max - min;
    return (r * rango + min);
}
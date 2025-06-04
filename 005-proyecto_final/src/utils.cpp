#include "utils.h"

float aleatorio(float min, float max) {
    float r = rand() / static_cast<float> (RAND_MAX); 
    float rango = max - min;
    return (r * rango + min);
}
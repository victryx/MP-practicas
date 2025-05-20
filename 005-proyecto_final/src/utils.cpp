#include "utils.h"
#include <cmath>

bool floatEqual(float a, float b, float epsilon) {
    return fabsf(a - b) <= epsilon;
}
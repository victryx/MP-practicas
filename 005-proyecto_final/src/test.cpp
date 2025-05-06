#include "Particula.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    Particula p;
    Vector2D vec = vectorAleatorio(0, 10, 0, 10);
    std::cout << vec.toString();
}

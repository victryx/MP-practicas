#include "Particula.h"
#include <iostream>
#include <ctime>

int main(int argc, char const *argv[]) {
    srand(time(0));

    Particula p(0);
    Vector2D vec = vectorAleatorio(0, 10, 0, 10);
    std::cout << p.toString() << std::endl;
    std::cout << vec.toString();
}

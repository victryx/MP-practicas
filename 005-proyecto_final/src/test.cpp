#include "Particula.h"
#include <iostream>
#include <ctime>

void vector2D();

int main(int argc, char const *argv[]) {
    srand(time(0));
    vector2D();


    /*
    Particula p(0);
    Vector2D vec = vectorAleatorio(0, 10, 0, 10);
    std::cout << p.toString() << std::endl;
    std::cout << vec.toString();

    Particula *set = nullptr;
    set = new Particula[10];
    for (int i = 0; i < 10; i++) {
        set[i] = Particula();
        std::cout << set[i].toString() << std::endl;
    }
        */
    
}


void vector2D() {
    Vector2D v1(7,8);
    Vector2D v2(5,5);

    std::cout << v1.distancia(v2) << "\n";
}
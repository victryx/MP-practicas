#include "Particula.h"
#include "ConjuntoParticulas.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>

void vector2D();
void utils();

int main(int argc, char const *argv[]) {
    srand(time(0));
    vector2D();
    utils();

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

void utils() {
    std::cout << "TEST: utils.h" << std::endl;

    float a = 0.12345;
    float b = 0.123;
    std::cout << fabsf(b - a) << std::endl;

    assert(floatEquals(a, b, 0.001F));
    assert(b == min(a,b));
    assert(a == max(a,b));

    assert(ajustarValor(10,10,35) == 10);
    assert(ajustarValor(20,10,35) == 20);
    assert(ajustarValor(-99,5,35) == 5);

    // porque falla el de abajo si uso valores double (les quito la F)
    assert(ajustarValor(21,0,15.23) == 15.23F); 

    assert(ajustarValor(10,10,10) == 10);

    std::cout << "TEST: utils.h passed" << std::endl;
}
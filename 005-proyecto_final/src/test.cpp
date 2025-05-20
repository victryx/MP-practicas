#include <iostream>
#include "ConjuntoParticulas.h"
using namespace std;

void txtInputTest();

int main(int argc, char const *argv[]) {
    txtInputTest();
}

void txtInputTest() {
    ConjuntoParticulas conj;

    for (int i = 0; i < 30; i++) {
        Particula p;
    }
    

    cin >> conj;

    cout << "Conjunto introducido: \n" << conj << endl;

}

void inputTest() {
    ConjuntoParticulas c1(0);
    ConjuntoParticulas c2(0);

    Vector2D v1 = Vector2D(12.0004, 13.0004);
    Vector2D v2 = Vector2D(12.0005, 13.0005);

    Particula p1;
    Particula p2;

    Particula p4(v1,v1,v2,0.0004,1);
    Particula p4_2(v2,v2,v2,0.0004,1);

    c1.agregar(p1);
    c1.agregar(p2);
    c1.agregar(p4);

    c2.agregar(p1);
    c2.agregar(p2);
    c2.agregar(p4_2);

    std::cout << c1 << "\n";
    std::cout << c2 << "\n";

    bool b = c1 == c2;
    cout << (c1 == c2); 
    cout << b << endl; 

    Vector2D input;
    cin >> input;
    cout << "Vector introducido: " << input << endl;

    // P: {(240.56,94.00),(-3.91,-3.70),(-0.16,0.29),8.0,1}
    Particula pInput;
    cin >> pInput;
    cout << "Particula introducida: " << pInput << endl;
}
#include <iostream>
using namespace std;

void prueba1() {
    int a = 5, *p;

    a = *p * a;
    if (a == *p)
        cout << "a igual a *p";
    else
        cout << "a igual a *p";
    cout << endl;
}

void prueba2() {
    int a = 5, *p;
    *p = *p * a; // Estamos modificando el valor de un puntero sin asignar. (Eso mal)
    if (a == *p) {
        cout << "a es igual a *p" << endl;
    } else {
        cout << "a es diferente a *p" << endl;
        cout << "*p = " << *p << endl;
    }
}

void prueba3() {
    int a = 5, *p = &a;
    *p = *p * a;
    if (a == *p) {
        cout << "a es igual a *p" << endl;
    } else {
        cout << "a es diferente a *p" << endl;
        cout << "*p = " << *p << endl;
    }
}

void prueba4() {
    int a = 5, *p = &a, **p2 = &p;

    **p2 = *p + (**p2 / a);
}

int main() {
    prueba3();
}
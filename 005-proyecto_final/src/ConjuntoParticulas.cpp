#include "ConjuntoParticulas.h"
#include <cassert>
#include <iostream>

void ConjuntoParticulas::liberaMemoria() {
    capacidad = 0;
    utiles = 0;
    delete [] set;
    set = nullptr;
}

void ConjuntoParticulas::reservaMemoria(int capacidad) {
    if (set != nullptr) {
        liberaMemoria();
    }

    set = new Particula[capacidad];
}

void ConjuntoParticulas::copia(const ConjuntoParticulas &otro) {
    this->capacidad = otro.capacidad; 
    this->utiles = otro.utiles;

    for (int i = 0; i < this->utiles; i++) {
        this->set[i] = otro.set[i];
    }
}

void ConjuntoParticulas::redimensiona(int nuevaCapacidad) {
    Particula *aux = new Particula[nuevaCapacidad];
    for (int i = 0; i < utiles; i++) {
        aux[i] = set[i];
    }

    delete [] set;
    set = aux;
    capacidad = nuevaCapacidad;
}

int ConjuntoParticulas::indexOf(const Particula &part) const {
    int index = -1;
    for (int i = 0; i < utiles && index == -1; i++) {
        if (part == obtener(i)) {
            index = i;
        }
    }
    return index;
}

ConjuntoParticulas::ConjuntoParticulas(int n) {
    utiles = capacidad = 0;
    set = nullptr;
    if (n > 0) {
        capacidad = n;
        reservaMemoria(capacidad);
    }
}

ConjuntoParticulas::ConjuntoParticulas(const ConjuntoParticulas &otro) {
    reservaMemoria(otro.capacidad); 
    copia(otro);
}

ConjuntoParticulas::~ConjuntoParticulas() {
    liberaMemoria();
}

ConjuntoParticulas& ConjuntoParticulas::operator=(const ConjuntoParticulas &otro) {
    if (this != &otro) {
        liberaMemoria();
        reservaMemoria(otro.capacidad);
        copia(otro);
    }
    return *this;
}


bool ConjuntoParticulas::operator==(const ConjuntoParticulas &otro) const {
    bool punterosIguales = this == &otro; // no entra en el bucle si los dos objetos son el mismo

    bool iguales = this->utiles == otro.utiles;

    ConjuntoParticulas aux = otro;

    for (int i = 0; i < utiles && iguales && !punterosIguales; i++) {
        int index = aux.indexOf( set[i] );
        iguales = index > -1;

        if (iguales) {
            aux.borrar(index);
        }
    }

    return punterosIguales || (iguales && aux.utiles == 0);
}

ConjuntoParticulas &ConjuntoParticulas::operator+=(const Particula &p) {
    agregar(p);
    return *this;
}

ConjuntoParticulas &ConjuntoParticulas::operator+=(const ConjuntoParticulas &otro) {
    for (int i = 0; i < otro.utiles; i++) {
        *this += otro.set[i];
    }
    return *this;
}

int ConjuntoParticulas::getUtiles() const {
    return utiles;
}

int ConjuntoParticulas::getCapacidad() const {
    return capacidad;
}

void ConjuntoParticulas::agregar(const Particula &part) {
    if (utiles == capacidad) {
        redimensiona(capacidad + TAM_BLOQUE);
    }
    set[utiles++] = part;
}

void ConjuntoParticulas::borrar(int pos) {
    if (pos >= 0 && pos < utiles) {
        std::swap(set[pos], set[utiles - 1]);
        utiles--;
    
        if (capacidad - utiles > TAM_BLOQUE) {
            redimensiona(utiles);
        }
    }
}

const Particula &ConjuntoParticulas::obtener(int pos) const {
    assert(pos >= 0 && pos < utiles);
    return set[pos];
}

void ConjuntoParticulas::reemplazar(int pos, const Particula &part) {
    if (pos >= 0 && pos < utiles) {
        set[pos] = part;
    }
}

void ConjuntoParticulas::mover(int tipo) {
    for (int i = 0; i < utiles; i++) {
        set[i].mover();
        if (tipo == 1) {
            set[i].rebotar();
        }
        if (tipo == 2) {
            set[i].wrap();
        }
    }
}

void ConjuntoParticulas::gestionarColisiones() {
    for (int i = 0; i < utiles - 1; i++) {
        bool choca = false; 
        for (int j = i+1; j < utiles && !choca; j++) {
            choca = set[i].colision(set[j]);
            if (choca) {
                set[i].choque(set[j]);
            }
        }
    }
}

void ConjuntoParticulas::vaciar() {
    liberaMemoria();
    capacidad = TAM_BLOQUE;
    reservaMemoria(capacidad);
}

std::string ConjuntoParticulas::toString() const {
    std::string out = "Capacidad: " + std::to_string(capacidad) + 
        "\nNúmero de partículas: " + std::to_string(utiles) + "\nParticulas:";
    for (int i = 0; i < utiles; i++) {
        out += "\nP" + std::to_string(i) + ": " + set[i].toString();
    }
    return out;
}

std::ostream &operator<<(std::ostream &flujo, const ConjuntoParticulas &conj) {
    // No uso ConjuntoParticulas::toString() porque el formato requerido es diferente

    int cantidad = conj.getUtiles();
    flujo << "@Particulas: " << cantidad;
    for (int i = 0; i < cantidad; i++) {
        flujo << "\np" << i << ": " << conj.obtener(i);
    }
    return flujo;
}

std::istream &operator>>(std::istream &flujo, ConjuntoParticulas &conj) {
    std::string header;
    int size;

    flujo >> header >> size;

    conj.vaciar();

    for (int i = 0; i < size; i++) {
        Particula part;
        flujo >> part;
        conj.agregar(part);
    }

    return flujo;
}
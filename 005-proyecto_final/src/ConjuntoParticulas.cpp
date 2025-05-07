#include "ConjuntoParticulas.h"
#include "cassert"

void ConjuntoParticulas::reservaMemoria() {
    if (set != nullptr) {
        liberaMemoria();
    }

    set = new Particula[capacidad];
}

void ConjuntoParticulas::liberaMemoria() {
    capacidad = 0;
    utiles = 0;
    delete [] set;
    set = nullptr;
}

void ConjuntoParticulas::redimensiona(int nuevaCapacidad) {
    assert(nuevaCapacidad >= utiles);
    Particula *aux = new Particula[nuevaCapacidad];
    for (int i = 0; i < utiles; i++) {
        aux[i] = set[i];
    }

    delete [] set;
    set = aux;
    capacidad = nuevaCapacidad;
}

ConjuntoParticulas::ConjuntoParticulas(int n) {
    if (n > 0) {
        utiles = capacidad = n;
        reservaMemoria();
    }
}

ConjuntoParticulas::ConjuntoParticulas(const ConjuntoParticulas &otro) {
    this->capacidad = otro.capacidad;
    this->utiles = otro.utiles;

    reservaMemoria();

    for (int i = 0; i < utiles; i++) {
        this->set[i] = otro.set[i];
    }
}

ConjuntoParticulas::~ConjuntoParticulas() {
    liberaMemoria();
}

int ConjuntoParticulas::getUtiles() {
    return utiles;
}

int ConjuntoParticulas::getCapacidad() {
    return capacidad;
}

void ConjuntoParticulas::agregar(const Particula &part) {
    if (utiles == capacidad) {
        redimensiona(capacidad + TAM_BLOQUE);
    }
    set[utiles++] = part;
}

void ConjuntoParticulas::borrar(int pos) {
    assert(pos >= 0 && pos < utiles);
    std::swap(set[pos], set[utiles - 1]);
    utiles--;

    if (capacidad - utiles > TAM_BLOQUE) {
        redimensiona(utiles);
    }
}

Particula &ConjuntoParticulas::obtener(int pos) {
    assert(pos >= 0 && pos < utiles);
    return set[pos];
}

void ConjuntoParticulas::reemplazar(int pos, const Particula &part) {
    assert(pos >= 0 && pos < utiles);
    set[pos] = part;
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

// TODO: no se si esto está bien
void ConjuntoParticulas::gestionarColisiones() {
    for (int i = 0; i < utiles; i++) {
        for (int j = i+1; j < utiles; j++) {
            if (set[i].colision(set[j])) {
                set[i].choque(set[j]);
            }
        }
    }
}

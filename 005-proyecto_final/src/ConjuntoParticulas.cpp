#include "ConjuntoParticulas.h"
#include "cassert"

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

ConjuntoParticulas::ConjuntoParticulas(int n) {
    utiles = capacidad = 0;
    set = nullptr;
    if (n > 0) {
        utiles = capacidad = n;
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
    
        if (capacidad - utiles >= TAM_BLOQUE) {
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

std::string ConjuntoParticulas::toString() {
    std::string out = "Capacidad: " + std::to_string(capacidad) + 
        "\nNúmero de partículas: " + std::to_string(utiles) + "\nParticulas:";
    for (int i = 0; i < utiles; i++) {
        out += "\nP" + std::to_string(i) + ": " + set[i].toString();
    }
    return out;
}
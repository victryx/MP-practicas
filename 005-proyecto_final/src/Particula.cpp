#include "Particula.h"
#include "params.h"
#include "utils.h"
#include "iostream" // testing

Particula::Particula(int tipoPart) {
    std::cout << this->pos.toString(); // TODO remove
    if (tipoPart == 0) {
        pos = vectorAleatorio(0, MAX_X, 0, MAX_Y);
        acel = vectorAleatorio(0, MAX_ACC, 0, MAX_ACC);
        veloc = vectorAleatorio(0, MAX_VEL, 0, MAX_VEL);
        radio = aleatorio(MIN_R, MAX_R);
    } else {
        // Vector2D cero(0,0);
        // pos = acel = veloc = cero;
        radio = MIN_R;
    }
    std::cout << pos.toString(); // TODO remove
    Vector2D
}

Particula::Particula(const Vector2D &_pos, const Vector2D &_acel, const Vector2D &_veloc, float _radio, int _tipo)
    : pos(_pos), acel(_acel), veloc(_veloc), radio(radio), tipo(tipo) {}

Vector2D Particula::getPos() const {
    return pos;
}

Vector2D Particula::getAcel() const {
    return acel;
}

Vector2D Particula::getVeloc() const {
    return veloc;
}

float Particula::getRadio() const {
    return radio;
}

void Particula::setPos(const Vector2D &_pos) {
    this->pos = _pos; // asginación por defecto copia campo a campo
}

void Particula::setAcel(const Vector2D &_acel) {
    this->acel = _acel;
}

void Particula::setVeloc(const Vector2D &_veloc) {
    this->veloc = _veloc;
}

int min(int a, int b) {
    return a < b ? a : b; // el ternario es medio guarrillo, se puede usar??
}

// Se asegura de que los vectores estén dentro de los límites
void checkOutOfBounds() {
    
}

// Duda: no habría que usar getters y setters?
// pero entonces se complica más el código, porque los getters
// no están devolviendo referencias, ¿deberían devolver Ve
void Particula::mover() {
    // 1. Sumar la aceleración a la velocidad
    veloc.sumar(acel);

    // 2. 
    veloc.setX(min(veloc.getX(), MAX_VEL));
    veloc.setY(min(veloc.getY(), MAX_VEL));

    // 3. Sumar velocidad a posición
    pos.sumar(veloc);
    // TODO: comprobar que la posición este dentro de los límites
    // ¿esto lo hace rebotar, verdad?
    rebotar();
}
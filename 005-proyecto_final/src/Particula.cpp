#include "Particula.h"
#include "params.h"
#include "utils.h"

Particula::Particula(int tipoPart) {
    if (tipoPart == 0) {
        pos = vectorAleatorio(0, MAX_X, 0, MAX_Y);
        acel = vectorAleatorio(0, MAX_ACC, 0, MAX_ACC);
        veloc = vectorAleatorio(0, MAX_VEL, 0, MAX_VEL);
        radio = aleatorio(MIN_R, MAX_R);
    } else {
        pos = Vector2D(0,0);
        acel = Vector2D(0,0);
        veloc = Vector2D(0,0);
        radio = MIN_R;
    }

    tipo = tipoPart;
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

void Particula::mover() {
    veloc.sumar(acel);
    ajustarVelocidad();

    pos.sumar(veloc);
    ajustarPosicion();
}

void Particula::rebotar() {
    bool norte = pos.getY() - radio <= 0;
    bool sur = pos.getY() + radio >= MAX_Y;
    bool este = pos.getX() + radio >= MAX_X;
    bool oeste = pos.getX() - radio <= 0;

    if (norte || sur) {
        veloc.setY(veloc.getY() * -1);
    }

    if (este || oeste) {
        veloc.setX(veloc.getX() * -1);
    }
}

bool Particula::colision(const Particula &otro) {
    return pos.distancia(otro.getPos()) <= radio + otro.getRadio();
}

void Particula::choque(Particula &otro) {
    std::swap(veloc, otro.veloc);
    std::swap(acel, otro.acel);
}

void Particula::wrap() {
    bool norte = pos.getY() - radio <= 0;
    bool sur = pos.getY() + radio >= MAX_Y;
    bool este = pos.getX() + radio >= MAX_X;
    bool oeste = pos.getX() - radio <= 0;

    if (norte) {
        pos.setY(MAX_Y - radio - 0.1);
    } 
    if (sur) {
        pos.setY(0 + radio + 0.1);
    }
    if (este) {
        pos.setX(MAX_X - radio - 0.1);
    }
    if (oeste) {
        pos.setX(0 + radio + 0.1);
    }
}

std::string Particula::toString() const {
    return "{" + pos.toString() + ", " + veloc.toString() + ", " + acel.toString() 
        + ", " + std::to_string(radio) + ", " + std::to_string(tipo) + "}";
    
}

void Particula::ajustarPosicion() {
    float maximoX = MAX_X - radio;
    float minimoX = radio;

    float maximoY = MAX_Y - radio;
    float minimoY = radio;

    pos.setX(ajustarValor(pos.getX(), minimoX, maximoX));
    pos.setY(ajustarValor(pos.getY(), minimoY, maximoY));
}

void Particula::ajustarVelocidad() {
    veloc.setX( ajustarValor(veloc.getX(), -MAX_VEL, MAX_VEL) );
    veloc.setY( ajustarValor(veloc.getY(), -MAX_VEL, MAX_VEL) );
}
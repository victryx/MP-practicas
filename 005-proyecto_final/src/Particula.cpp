#include "Particula.h"
#include "params.h"
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>

bool Particula::chocaNorte() {
    return pos.getY() - radio <= 0;
}

bool Particula::chocaSur() {
    return pos.getY() + radio >= MAX_Y;
}

bool Particula::chocaEste() {
    return pos.getX() + radio >= MAX_X;
}

bool Particula::chocaOeste() {
    return pos.getX() - radio <= 0;
}

float Particula::aleatorio(float min, float max) {
    float r = rand() / static_cast<float> (RAND_MAX); 
    float rango = max - min;
    return (r * rango + min);
}

float Particula::ajustarValor(float val, float limiteInferior, float limiteSuperior) {
    return fmaxf(limiteInferior, fminf(limiteSuperior, val));
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

Particula::Particula(int tipoPart) {
    if (tipoPart == 0) {
        pos = Vector2D(aleatorio(0, MAX_X), aleatorio(0, MAX_Y)); 
        acel = Vector2D(aleatorio(-MAX_ACC, MAX_ACC), aleatorio(-MAX_ACC, MAX_ACC)); 
        veloc = Vector2D(aleatorio(-MAX_VEL, MAX_VEL), aleatorio(-MAX_VEL, MAX_VEL)); 
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
    this->pos = _pos; 
}

void Particula::setAcel(const Vector2D &_acel) {
    this->acel = _acel;
}

void Particula::setVeloc(const Vector2D &_veloc) {
    this->veloc = _veloc;
}

void Particula::setRadio(int _radio) {
    this->radio = _radio;
}

void Particula::mover() {
    veloc.sumar(acel);
    ajustarVelocidad();

    pos.sumar(veloc);
    ajustarPosicion();
}

void Particula::rebotar() {
    if (chocaNorte() || chocaSur()) {
        veloc.setY(-veloc.getY());
        acel.setY(-acel.getY());
    }

    if (chocaEste() || chocaOeste()) {
        veloc.setX(-veloc.getX());
        acel.setX(-acel.getX());
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
    float ajuste = 1;
    if (chocaNorte()) {
        pos.setY(MAX_Y - radio - ajuste);
    } 
    if (chocaSur()) {
        pos.setY(radio + ajuste);
    }
    if (chocaEste()) {
        pos.setX(radio + ajuste);
    }
    if (chocaOeste()) {
        pos.setX(MAX_X - radio - ajuste);
    }
}

std::string Particula::toString() const {
    return "{" + pos.toString() + ", " + veloc.toString() + ", " + acel.toString() 
        + ", " + std::to_string(radio) + ", " + std::to_string(tipo) + "}";
}

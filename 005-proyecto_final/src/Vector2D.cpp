#include "Vector2D.h"
#include <cmath>
#include <string>

Vector2D::Vector2D(float _x, float _y) {
    this->x = _x;
    this->y = _y;
}

float Vector2D::getX() const {
    return x;
}

float Vector2D::getY() const {
    return y;
}

void Vector2D::setX(float _x) {
    this->x = _x;
}

void Vector2D::setY(float _y) {
    this->y = _y;
}

void Vector2D::setXY(float _x, float _y) {
    setX(_x);
    setY(_y);
}

void Vector2D::sumar(const Vector2D &otro) {
    setXY(this->x + otro.x, this->y + otro.y);
}

void Vector2D::escalar(float val) {
    setXY(x * val, y * val);
}

float Vector2D::modulo() const {
    return sqrtf(powf(x, 2) + powf(y, 2));
}

void Vector2D::normalizar() {
    float mod = modulo();
    setXY(x / mod, y / mod);
}

float Vector2D::distancia(const Vector2D &otro) const {
    return Vector2D(this->x - otro.x, this->y - otro.y).modulo();
}

std::string Vector2D::toString() const {
    return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}
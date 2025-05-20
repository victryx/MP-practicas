#include "Vector2D.h"
#include "params.h"
#include "utils.h"
#include <cmath>
#include <string>
#include <iostream>

Vector2D::Vector2D(float _x, float _y) {
    this->x = _x;
    this->y = _y;
}

bool Vector2D::operator==(const Vector2D &otro) const {
    return floatEqual(x,otro.x, EPSILON) && floatEqual(y, otro.y, EPSILON);
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

std::ostream &operator<<(std::ostream &flujo, const Vector2D &vector) {
   return flujo << vector.toString(); 
}

std::istream &operator>>(std::istream &flujo, Vector2D &vector) {
    char ch;
    float x, y;

    flujo >> ch >> x >> ch >> y >> ch;
    vector.setXY(x,y);
    
    return flujo;
}
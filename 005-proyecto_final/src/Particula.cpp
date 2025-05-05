#include "Particula.h"

Particula::Particula(const Vector2D &_pos, const Vector2D &_acel, const Vector2D &_veloc, float _radio, int _tipo)
    : pos(_pos), acel(_acel), veloc(_veloc), radio(radio), tipo(tipo) {}
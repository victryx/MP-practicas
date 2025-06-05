#ifndef PARAMS_H
#define PARAMS_H

const int MAX_X = 600;
const int MAX_Y = 600;

const int   MAX_VEL = 7;
const float MAX_ACC = 2.0;

const float RADIO = 3.0;
const float MIN_R = 3.0;
const float MAX_R = 7.0;

const float EPSILON = 0.01;

/* Parámetros del minijuego */

const int   PLAYER_LIVES            = 5;
const float PLAYER_VELOCITY         = 8;

const float BULLET_VELOCITY         = -8;
const float BULLET_RADIUS           = 2;

const float ENEMY_MAX_VELOCITY_X    = 1.5;
const float ENEMY_MIN_VELOCITY_X    = -1.5;
const float ENEMY_MAX_VELOCITY_Y    = 3;
const float ENEMY_MIN_VELOCITY_Y    = 1;
const float ENEMY_SPAWN_OFFSET_Y    = 10;
const float ENEMY_RADIUS            = 7;

const float SHOOT_COOLDOWN          = .35;
const float ENEMY_SPAWN_COOLDOWN    = 3.5;

#endif
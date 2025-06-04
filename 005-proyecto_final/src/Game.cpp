#include "Game.h"

/* Métodos privados */

float Game::getElapsedTime() {
    std::chrono::time_point<std::chrono::high_resolution_clock> now;
    now = std::chrono::high_resolution_clock::now();
    unsigned long time = std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime).count();
    return time / 1000.f;
}

void Game::updatePlayer(float movement) {
    Vector2D newPos = player.getPos();
    newPos.sumarX(movement);
    player.setPos(newPos);
    player.wrap();  // cuando alcanza el borde derecho, aparece por el izquierdo (y viceversa)
}

bool bulletOutOfBounds(const Particula &bullet) {
    return bullet.getPos().getY() - bullet.getRadio() <= 0;
}

void Game::removeOutOfBoundsBullets() {
    for (int i = bullets.getUtiles() - 1; i >= 0; i--) {
        if (bulletOutOfBounds(bullets.obtener(i))) {
            bullets.borrar(i);
        }
    }
}

void Game::updateBullets() {
    bullets.mover(0);
    removeOutOfBoundsBullets();
}

bool Game::enemyReachedGoal(const Particula &enemy) {
    return enemy.getPos().getY() >= screenHeight - 10.f;
}

void Game::updateEnemies() {
    enemies.mover(1);
    enemies.gestionarColisiones();
    
    for (int i = enemies.getUtiles() - 1; i >= 0; i--) {
        if (enemyReachedGoal(enemies.obtener(i))) { // cuando un enemigo alcanza el final del mundo
            enemies.borrar(i);                      // se elimina al enemigo del juego
            playerLives--;                          // se resta una vida al jugador

            active = playerLives != 0;              // si las vidas se quedan a cero, termina el juego :(
        }
    }
}

void Game::spawnEnemy() {
    if (getElapsedTime() - lastSpawned > enemySpawnCooldown) {
        Vector2D pos(
            aleatorio(0, screenWidth),
            ENEMY_SPAWN_OFFSET_Y
        );
        Vector2D acel(0,0);
        Vector2D vel(
            aleatorio(enemyMinVelocityX, enemyMaxVelocityX),
            aleatorio(enemyMinVelocityY, enemyMaxVelocityY)
        );

        Particula e(pos, acel, vel, enemyRadius, 1);
        enemies.agregar(e);
        lastSpawned = getElapsedTime();
    }
}

void Game::manageCollisions() {
    for (int i = bullets.getUtiles() - 1; i >= 0; i--) {
        Particula curBullet = bullets.obtener(i);
        bool collision = false;
        for (int j = 0; j < enemies.getUtiles() && !collision; j++) {
            collision = curBullet.colision(enemies.obtener(j));

            if (collision) {                // Cuando una bala colisiona con un enemigo
                enemies.borrar(j);          // Se elimina el enemigo
                bullets.borrar(i);          // Se elimina la bala
                onEnemyDestroyed();
            }
        }
    }
}

void Game::onEnemyDestroyed() {
    enemySpawnCooldown *= 0.95;  // Aumenta la frecuencia de aparición de enemigos
    playerPoints++;              // +1 punto :)

    if (playerPoints == 20) {    // Al alcanzar los 20 puntos
        shootCooldown *= 0.3;    // Aumenta la frecuencia de disparo
    }
}

void Game::fireBullet() {
    if (getElapsedTime() - lastShot > shootCooldown) {
        Vector2D acel = Vector2D(0,0);
        Vector2D veloc = Vector2D(0, bulletVelocity);
        Vector2D pos = player.getPos();
        Particula bullet = Particula(player.getPos(), acel, veloc, bulletRadius, 1);
        bullets.agregar(bullet);
        lastShot = getElapsedTime();
    }
}

/* Métodos públicos */

Game::Game(int _screenWidth, int _screenHeight) 
    : screenWidth(_screenWidth), screenHeight(_screenHeight) {
    // el constructor por defecto asigna los parámetros de params.h

    playerLives = PLAYER_LIVES;
    playerVelocity = PLAYER_VELOCITY;
    bulletVelocity = BULLET_VELOCITY;
    bulletRadius = BULLET_RADIUS;

    enemyMaxVelocityX = ENEMY_MAX_VELOCITY_X;
    enemyMinVelocityX = ENEMY_MIN_VELOCITY_X;
    enemyMaxVelocityY = ENEMY_MAX_VELOCITY_Y;
    enemyMinVelocityY = ENEMY_MIN_VELOCITY_Y;
    enemySpawnOffsetY = ENEMY_SPAWN_OFFSET_Y;
    enemyRadius = ENEMY_RADIUS;

    shootCooldown = SHOOT_COOLDOWN;
    enemySpawnCooldown = ENEMY_SPAWN_COOLDOWN;

    playerSpawnPoint = Vector2D(screenWidth / 2.f, screenHeight - 40.f);
    player.setPos(playerSpawnPoint);
    startTime = std::chrono::high_resolution_clock::now();
}

const ConjuntoParticulas &Game::getEnemies() const {
    return enemies;
}

const ConjuntoParticulas &Game::getBullets() const {
    return bullets;
}

const Particula &Game::getPlayer() const  {
    return player;
}

bool Game::isActive() const {
    return active;
}

int Game::countBullets() const {
    return bullets.getUtiles();
}

int Game::countEnemies() const {
    return enemies.getUtiles();
}

int Game::getLives() const {
    return playerLives;
}

int Game::getPlayerPoints() const {
    return playerPoints;
}

void Game::update(int inputDirection, bool inputFire) {
    updatePlayer(inputDirection * playerVelocity);

    if (inputFire) {
        fireBullet();
    }

    updateBullets();
    updateEnemies();
    manageCollisions();
    spawnEnemy();
}

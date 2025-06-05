#ifndef GAME_H
#define GAME_H

#include "ConjuntoParticulas.h"
#include "params.h"
#include "utils.h"
#include <ctime>
#include <chrono>

class Game {
private:
    bool active = true;         // 'true' mientras el juego esté activo

    ConjuntoParticulas enemies; // Conjunto de enemigos (naves)
    ConjuntoParticulas bullets; // Conjunto de proyectiles (disparos)
    Particula player;           // Partícula jugador (base)
    Vector2D playerSpawnPoint;  // Posición de aparición del jugador (calculada en el constructor según dimensiones de la pantalla)

    int screenWidth;            // Anchura de la pantalla
    int screenHeight;           // Altura de la pantalla

    int playerPoints = 0;       // Puntos del jugador
    int playerLives;            // Número de vidas del jugador
    float playerVelocity;       // Velocidad de movimiento del jugador

    float bulletVelocity;       // Velocidad de movimiento de las balas
    float bulletRadius;         // Radio de las balas

    /* La velocidad de los enemigos se elige de forma aleatoria según los siguientes parámetros */
    float enemyMinVelocityX;    // Valor mínimo para la velocidad en X
    float enemyMaxVelocityX;    // Valor máximo para la velocidad en X
    float enemyMinVelocityY;    // Valor mínimo para la velocidad en Y
    float enemyMaxVelocityY;    // Valor máximo para la velocidad en Y
    float enemySpawnOffsetY;    // Ajuste de posición de aparición (para evitar que aparezcan en el borde superior de la pantalla)
    float enemyRadius;          // Radio de los enemigos

    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    float shootCooldown;        // Intervalo entre disparos
    float enemySpawnCooldown;   // Intervalo de aparición de enemigos

    float lastShotTime = 0;         // Momento en el que se realizó el ultimo disparo
    float lastSpawnedTime = 0;      // Momento en el que apareció el último enemigo

    /// @brief Tiempo transcurrido en segundos desde la creación de este objeto
    float getElapsedTime() const;

    /// @brief Actualiza la posición del jugador según la entrada recibida
    void updatePlayer(float movement);

    /// @brief Elimina las balas que han abandonado la zona visible
    void removeOutOfBoundsBullets();

    /// @brief Actualiza la posición de las balas y elimina las que han
    ///        abandonado la zona visible
    void updateBullets();

    /// @brief Comprueba si un enemigo ha alcanzado su objetivo 
    ///        (la parte inferior del mundo)
    bool enemyReachedGoal(const Particula &enemy);

    /// @brief Gestiona el movimiento y el rebote de los enemigos. Si uno de los
    ///        enemigos alcanza la zona inferior del mundo, se resta una vida al
    ///        jugador
    void updateEnemies();

    /// @brief Genera un nuevo enemigo SI ha transcurrido el tiempo de enfriamiento
    void spawnEnemy();

    /// @brief Controla las colisiones entre balas y enemigos
    void manageCollisions();

    /// @brief Dispara una bala
    void fireBullet();

    /// @brief Cuando se destruye un enemigo, aumenta los puntos, aumenta la
    ///        velocidad de aparición de enemigos
    void onEnemyDestroyed();

public:

    /// @brief Constructor por defecto, inicia los parámetros del juego a las 
    ///        constantes definidas en params.h
    Game(int _screenWidth = MAX_X, int _screenHeight = MAX_Y);

    /// @brief Reinicia el estado del juego
    void restart();

    /// @brief Devuelve una referencia constante al conjunto de enemigos
    const ConjuntoParticulas &getEnemies() const;
    
    /// @brief Devuelve una referencia constante al conjunto de balas
    const ConjuntoParticulas &getBullets() const;
    
    /// @brief Devuelve una referencia constante a la partícula jugador
    const Particula &getPlayer() const;
    
    /// @brief Devuelve true si el juego está en curso, false si ya ha terminado
    bool isActive() const;
    
    /// @brief Cantidad de balas en el minijuego
    int countBullets() const;
    
    /// @brief Cantidad de enemigos en el minijuego
    int countEnemies() const;

    /// @brief Cantidad de vidas del jugador
    int getLives() const;

    /// @brief Cantidad de puntos del jugador
    int getPlayerPoints() const;
    
    /// @brief Procesa la lectura de las teclas y actualiza el estado de los objetos,
    ///        se ejecuta una vez en cada frame
    void update(int inputDirection, bool inputFire);

};

#endif

#include "raylib.h"
#include "Vector2D.h"
#include "Particula.h"
#include "Game.h"
#include <iostream>


void pintarParticula(const Particula &p, Color c);
void pintarParticulas(const ConjuntoParticulas &conj, Color col);
void drawPlayer(const Particula &player, Color c);
void drawUI(const Game &game);

int main(int argc, char const *argv[]) {
    const int screenWidth = MAX_X;
    const int screenHeight = MAX_Y;

    InitWindow(screenWidth, screenHeight, "MI VIDEOGUEJO :D");

    SetTargetFPS(30);

    Game game(screenWidth, screenHeight);

    while (!WindowShouldClose() && game.isActive()) {

        int inputDirection = 0;

        if (IsKeyDown(KEY_LEFT)) {
            inputDirection = -1;
        }

        if (IsKeyDown(KEY_RIGHT)) {
            inputDirection = 1;
        }

        bool fire = IsKeyDown(KEY_SPACE);

        game.update(inputDirection, fire);

        // PINTAR
        BeginDrawing();

        ClearBackground(RAYWHITE);
        drawUI(game);

        drawPlayer(game.getPlayer(), GREEN);
        pintarParticulas(game.getEnemies(), RED);
        pintarParticulas(game.getBullets(), BLACK);
        EndDrawing();
    }

    while (!game.isActive() && !WindowShouldClose()) {
        ClearBackground(RED);
        BeginDrawing();
        DrawText("HAS PERDIDO\nAHAHAHAHHAJAÑHJALK", 30, 20, 20, BLACK);
        std::string pointsLabel = "PERO....\nHas conseguido " + std::to_string(game.getPlayerPoints()) + " Puntos";

        DrawText(pointsLabel.c_str(), 30, 70, 20, BLACK);
        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context
    return 0;
}

void pintarParticula(const Particula &p, Color c) {
    DrawCircle(p.getPos().getX(), p.getPos().getY(), p.getRadio(), c);
}

void pintarParticulas(const ConjuntoParticulas &conj, Color col) {
    int size = conj.getUtiles();
    for (size_t i = 0; i < size; i++) {
        pintarParticula(conj.obtener(i), col);
    }
}

void drawPlayer(const Particula &player, Color c) {
    Vector2 center, top, left, right;
    center.x = player.getPos().getX();
    center.y = player.getPos().getY();
    top.x = center.x;
    top.y = center.y - 10;
    left.x = center.x - 7;
    left.y = center.y + 5;
    right.x = center.x + 7;
    right.y = center.y + 5;
    DrawTriangle(top, left, right, c);
}

void drawUI(const Game &game) {

    std::string livesLabel = "Vidas: ";

    for (int i = 0; i < game.getLives(); i++) {
        livesLabel += "* ";
    }

    std::string pointsLabel = "Puntos: " + std::to_string(game.getPlayerPoints());

    DrawText("MI VIDEOGÜEJO: COME MIEDA", 10, 10, 20, BLACK);
    DrawText(livesLabel.c_str(), 10, 30, 20, BLACK);
    DrawText(pointsLabel.c_str(), 10, 50, 20, BLACK);
}
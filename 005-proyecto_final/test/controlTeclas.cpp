// ejemplo para ilustrar el uso de las teclas

#include "raylib.h"

struct Pos{
    float x, y;
};

void pintar(const Pos & p, Color c) {
    DrawCircle(p.x, p.y, 7, c);
}

const float VELOC = 5.5;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Mueve el circulo con las teclas de flecha. Pulsa la barra para borrar");

    Pos posicInicio = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    Pos despInicio = { 5.0f, 4.0f };
    Pos posic = posicInicio;
    Pos desp = despInicio;

    bool limpiar = false;

    SetTargetFPS(30);

    while (!WindowShouldClose())
    {
        desp = {0.0, 0.0};


        // el código para la barra es KEY_SPACE

        if (IsKeyDown(KEY_UP))
            desp.y = -VELOC;

        else if (IsKeyDown(KEY_DOWN))
            desp.y = VELOC;

        else if (IsKeyDown(KEY_LEFT))
            desp.x = -VELOC;

        else if (IsKeyDown(KEY_RIGHT))
            desp.x = VELOC;

        else if (IsKeyDown(KEY_SPACE)){
            posic = posicInicio;
            limpiar = true;
        }


        posic.x += desp.x;
        posic.y += desp.y;

        // PINTAR
        BeginDrawing();
        if (limpiar){
            ClearBackground(BLACK);
            limpiar = false;
        }
         pintar(posic, MAROON);
        EndDrawing();

    }
    CloseWindow();        // Close window and OpenGL context
    return 0;
}

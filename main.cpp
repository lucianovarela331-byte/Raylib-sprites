#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"

struct Sprite {
    Vector2 posicion;
    Vector2 velocidad;
    float escala;
    Color color;
    float rotacion;
};

int main(void)
{
    InitWindow(1024, 768, "Sprites");
    SetTargetFPS(60);

    Texture2D textura = LoadTexture("slime.png");


    SetTextureFilter(textura, TEXTURE_FILTER_BILINEAR);
   

    Sprite sprite1 = { {150, 250}, {200, 0}, 0.15f, BLUE, 0.0f };
    
    Sprite sprite2 = { {550, 400}, {-150, 0}, 0.25f, GREEN, 0.0f };

    float velocidad = 200.0f;

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        if (IsKeyDown(KEY_RIGHT))
            sprite1.posicion.x += velocidad * deltaTime;

        if (IsKeyDown(KEY_LEFT))
            sprite1.posicion.x -= velocidad * deltaTime;
    
        if (IsKeyDown(KEY_UP))
            sprite1.posicion.y -= velocidad * deltaTime;

        if (IsKeyDown(KEY_DOWN))
            sprite1.posicion.y += velocidad * deltaTime;
 

        if (IsKeyDown(KEY_D))
            sprite2.posicion.x += velocidad * deltaTime;

        if (IsKeyDown(KEY_A))
            sprite2.posicion.x -= velocidad * deltaTime;

        if (IsKeyDown(KEY_W))
            sprite2.posicion.y -= velocidad * deltaTime;

        if (IsKeyDown(KEY_S))
            sprite2.posicion.y += velocidad * deltaTime;

        if (IsKeyPressed(KEY_SPACE))
        {
            float escalaTemp = sprite1.escala;
            sprite1.escala = sprite2.escala;
            sprite2.escala = escalaTemp;

            Color colorTemp = sprite1.color;
            sprite1.color = sprite2.color;
            sprite2.color = colorTemp;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Sprites", 30, 30, 30, BLACK);

        DrawText("Flechas: Mover slime 1", 30, 80, 20, DARKGRAY);
        DrawText("WASD: Mover slime 2", 300, 80, 20, DARKGRAY);
        DrawText("Espacio: intercambiar propiedades", 30, 110, 20, DARKGRAY);

        DrawTextureEx(textura, sprite1.posicion, sprite1.rotacion, sprite1.escala, sprite1.color);
        
        DrawTextureEx(textura, sprite2.posicion, sprite2.rotacion, sprite2.escala, sprite2.color);

        DrawText(TextFormat("Sprite 1 - pos: (%.0f, %.0f) Escala: %.2f Color RGB: (%d, %d, %d)", sprite1.posicion.x, sprite1.posicion.y, sprite1.escala, sprite1.color.r, sprite1.color.g, sprite1.color.b), 30, 600, 18, BLACK);


        DrawText(
            TextFormat("Sprite 2 - Pos: (%.0f, %.0f) Escala: %.2f Color RGB: (%d, %d, %d)",
                sprite2.posicion.x, sprite2.posicion.y,
                sprite2.escala,
                sprite2.color.r, sprite2.color.g, sprite2.color.b),
            30, 640, 18, BLACK
        );

        EndDrawing();
    }

    UnloadTexture(textura);

    CloseWindow();

    return 0;
}

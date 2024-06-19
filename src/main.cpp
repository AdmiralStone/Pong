#include "raylib.h"
#include "GameMenu.h"
#include "Ball.h"
#include "Paddle.h"
#include <iostream>

int main() {
    // Initilize Window(w,h,title)
    InitWindow(800, 600, "Pong");

    // FPS CAP
    SetWindowState(FLAG_VSYNC_HINT);

    GameMenu menu;

    Ball ball;

    Paddle lPaddle(50, GetScreenHeight() / 2);
    Paddle rPaddle(GetScreenWidth() - 50, GetScreenHeight() / 2);

    const char* winnerText = nullptr;

    while (!WindowShouldClose()) {
        if(menu.selectedMode == GameMenu::NONE){
            BeginDrawing();
                menu.Draw();
            EndDrawing();
            menu.HandleInput();

        }else{
            // Ball Move Logic
        ball.x += ball.speedX * GetFrameTime();
        ball.y += ball.speedY * GetFrameTime();

        if (ball.x < 0) {
            winnerText = "Left Player Wins";
        }

        if (ball.x > GetScreenWidth()) {
            winnerText = "Right Player Wins";
        }

        if (ball.y > GetScreenHeight()) {
            ball.y = GetScreenHeight();
            ball.speedY *= -1;
        }

        if (ball.y < 0) {
            ball.y = 0;
            ball.speedY *= -1;
        }

        // Check If Key is pressed and held
        if (IsKeyDown(KEY_W) && lPaddle.y > 0) {
            lPaddle.y -= lPaddle.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_S) && lPaddle.y < GetScreenHeight() - 100) {
            lPaddle.y += lPaddle.speed * GetFrameTime();
        }

        if(menu.selectedMode == GameMenu::MULTI_PLAYER){
            if (IsKeyDown(KEY_UP) && rPaddle.y > 0) {
                rPaddle.y -= rPaddle.speed * GetFrameTime();
            }
            if (IsKeyDown(KEY_DOWN) && rPaddle.y < GetScreenHeight() - 100) {
                rPaddle.y += rPaddle.speed * GetFrameTime();
            }
        }else if(menu.selectedMode == GameMenu::SINGLE_PLAYER && !winnerText){
            rPaddle.AutoMove(ball.y,GetFrameTime());
        }

        

        // Check Collision with left paddle
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, lPaddle.getRect())) {
            if (ball.speedX < 0) {
                ball.speedX *= -1.1f;
                ball.speedY = (ball.y - lPaddle.y) / (lPaddle.height / 2) * ball.speedX;
            }
        }

        // Check Collision with right paddle
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, rPaddle.getRect())) {
            if (ball.speedX > 0) {
                ball.speedX *= -1.1f;
                ball.speedY = (ball.y - rPaddle.y) / (rPaddle.height / 2) * abs(ball.speedX);
            }
        }

        // Begin the rendering process
        BeginDrawing();
        ClearBackground(BLACK);

        ball.Draw();
        lPaddle.Draw();
        rPaddle.Draw();

        if (winnerText) {
            int textWidth = MeasureText(winnerText, 60);
            DrawText(winnerText, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - 30, 60, YELLOW);
        }

        if (winnerText && IsKeyPressed(KEY_SPACE)) {
            ball.Reset();
            winnerText = nullptr;
        }

        DrawFPS(10, 10);
        EndDrawing();

        }
    }

    CloseWindow();

    return 0;
}

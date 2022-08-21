#include "raylib.h"

int main(){
    // Initilize Window(w,h,title)
    InitWindow(800,600,"Pong");

    // FPS CAP
    SetWindowState(FLAG_VSYNC_HINT);

    float ballX = GetScreenWidth()/2.0f;
    float ballY = GetScreenHeight()/2.0f;
    float ballRadius = 5;
    float ballSpeedX = 300;
    float ballSpeedY = 300;

    while(!WindowShouldClose()){

        // Ball Move Logic
        ballX+=ballSpeedX* GetFrameTime();
        ballY+=ballSpeedY* GetFrameTime();
        
        
        if(ballY > GetScreenHeight()){
            ballY = GetScreenHeight();
            ballSpeedY*=-1;
        }

        if(ballY < 0){
            ballY = 0;
            ballSpeedY*=-1;
        }

        if(ballX<0){
            ballX = 0;
            ballSpeedX *= -1;
        }

        if(ballX > GetScreenWidth()){
            ballX = GetScreenWidth();
            ballSpeedX*=-1;
        }
        
        // Begin the rendering process
        BeginDrawing();
            // Clear the background and make it black
            ClearBackground(BLACK);

            // Draw a Circle (The Ball)
            DrawCircle(ballX,ballY,ballRadius,WHITE);

            // Draw the left paddle
            DrawRectangle(50,GetScreenHeight()/2-50,10,100,WHITE);

            // Draw the Right paddle
            DrawRectangle(750,GetScreenHeight()/2-50,10,100,WHITE);



            // Show FPS(w,h)
            DrawFPS(10,10);
        // End the rendering handle events
        EndDrawing();
    }
    // Close the window
    CloseWindow();
    return 0;

}
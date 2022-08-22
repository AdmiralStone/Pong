#include "raylib.h"

struct Ball{
    float x,y;
    float speedX,speedY;
    float radius;

    void Draw(){
        DrawCircle((int)x,(int)y,radius,WHITE);
    }
};


struct Paddle{
    float x,y;
    float speed;
    float height,width;

    void Draw(){
        DrawRectangle((int)x,(int)y,(int)width,(int)height,WHITE);
    }

};
int main(){
    // Initilize Window(w,h,title)
    InitWindow(800,600,"Pong");

    // FPS CAP
    SetWindowState(FLAG_VSYNC_HINT);

    // Instantiate a new Ball struct object
    Ball ball;
    ball.x = GetScreenWidth()/2.0f;
    ball.y = GetScreenHeight()/2.0f;
    ball.radius = 5;
    ball.speedX = 300;
    ball.speedY = 300;

    // Instantiate a new paddle struct object
    Paddle lPaddle;
    lPaddle.x = 50;
    lPaddle.y = GetScreenHeight()/2-50;
    lPaddle.width = 10;
    lPaddle.height = 100;
    lPaddle.speed = 500;

    Paddle rPaddle;
    rPaddle.x = GetScreenWidth()-50-10;
    rPaddle.y = GetScreenHeight()/2-50;
    rPaddle.width = 10;
    rPaddle.height = 100;
    rPaddle.speed = 500;

    while(!WindowShouldClose()){

        // Ball Move Logic
        ball.x+=ball.speedX* GetFrameTime();
        ball.y+=ball.speedY* GetFrameTime();
        
        
        if(ball.y > GetScreenHeight()){
            ball.y = GetScreenHeight();
            ball.speedY*=-1;
        }

        if(ball.y < 0){
            ball.y = 0;
            ball.speedY*=-1;
        }

        if(ball.x<0){
            ball.x = 0;
            ball.speedX *= -1;
        }

        if(ball.x > GetScreenWidth()){
            ball.x = GetScreenWidth();
            ball.speedX*=-1;
        }
        
        // Begin the rendering process
        BeginDrawing();
            // Clear the background and make it black
            ClearBackground(BLACK);

            // Draw a Circle (The Ball)
            ball.Draw();

            // Draw the left paddle
            lPaddle.Draw();

            // Draw the Right paddle
            rPaddle.Draw();



            // Show FPS(w,h)
            DrawFPS(10,10);
        // End the rendering handle events
        EndDrawing();
    }
    // Close the window
    CloseWindow();
    return 0;

}
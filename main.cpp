#include "raylib.h"
#include <iostream>

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

    Rectangle getRect(){
        return Rectangle{
            x - width / 2 , y-height/2,10,100
        };
    }

    void Draw(){
        DrawRectangleRec(getRect(),WHITE);
    }

    

};

void reset(Ball* ball){
    ball->x = GetScreenWidth()/2.0f;
    ball->y = GetScreenHeight()/2.0f;
    ball->radius = 5;
    ball->speedX = 300;
    ball->speedY = 300;
}

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
    lPaddle.y = GetScreenHeight()/2;
    lPaddle.width = 10;
    lPaddle.height = 100;
    lPaddle.speed = 500;

    Paddle rPaddle;
    rPaddle.x = GetScreenWidth()-50;
    rPaddle.y = GetScreenHeight()/2;
    rPaddle.width = 10;
    rPaddle.height = 100;
    rPaddle.speed = 500;

    const char* winnerText = nullptr;

    while(!WindowShouldClose()){

        // Ball Move Logic
        ball.x+=ball.speedX* GetFrameTime();
        ball.y+=ball.speedY* GetFrameTime();
        
        if(ball.x < 0){
            winnerText = "Left Player Wins";
        }

        if(ball.x > GetScreenWidth()){
            winnerText = "Right Player Wins";
        }

        if(ball.y > GetScreenHeight()){
            ball.y = GetScreenHeight();
            ball.speedY*=-1;
        }

        if(ball.y < 0){
            ball.y = 0;
            ball.speedY*=-1;
        }

        // Check If Key is pressed and held
        // Dont move paddle if at edge of screen height
        if(IsKeyDown(KEY_W)){
            if (lPaddle.y >50){
                lPaddle.y -= lPaddle.speed*GetFrameTime();
            }
        }
        if(IsKeyDown(KEY_S)){
            if(lPaddle.y< GetScreenHeight()-50){
                lPaddle.y += lPaddle.speed*GetFrameTime();
            }
        }

        if(IsKeyDown(KEY_UP)){
            if(rPaddle.y > 50){
                rPaddle.y -= rPaddle.speed*GetFrameTime();
            }
        }
        if(IsKeyDown(KEY_DOWN)){
            if(rPaddle.y < GetScreenHeight()-50){
                rPaddle.y += rPaddle.speed*GetFrameTime();
            }
        }
        
        // Check Collision with left paddle
        if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,lPaddle.getRect())){
            if(ball.speedX < 0){
                ball.speedX *=-1.1f;
                ball.speedY = (ball.y - lPaddle.y) / (lPaddle.height / 2) * ball.speedX;
            }
        }

        // Check Collision with right paddle
        if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,rPaddle.getRect())){
            if(ball.speedX > 0){
                ball.speedX *=-1.1f;
                ball.speedY = (ball.y - rPaddle.y) / (rPaddle.height / 2) * abs(ball.speedX);
            }
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


            // WInner Text
            if(winnerText){
                
                int textWidth = MeasureText(winnerText,60);

                DrawText(winnerText,GetScreenWidth()/2 - textWidth / 2,GetScreenHeight()/2-30,60,YELLOW);
                
            }

            if(winnerText && IsKeyPressed(KEY_SPACE)){
                reset(&ball);
                winnerText = nullptr;
            }
            // Show FPS(w,h)
            DrawFPS(10,10);
        // End the rendering handle events
        EndDrawing();
    }
    // Close the window
    CloseWindow();
    
    return 0;

}
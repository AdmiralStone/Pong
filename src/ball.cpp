#include "Ball.h"

Ball::Ball(){
    Reset();
}

void Ball::Draw(){
        DrawCircle((int)x,(int)y,radius,WHITE);
    }

void Ball::Reset(){
    x = GetScreenWidth()/2.0f;
    y = GetScreenHeight()/2.0f;
    radius = 5;
    speedX = 300.0f;
    speedY = 300.0f;
}
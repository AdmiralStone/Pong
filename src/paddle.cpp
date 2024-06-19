#include "Paddle.h"

Paddle::Paddle(float startX, float startY){
    x = startX;
    y = startY;
    width = 10;
    height = 100;
    speed = 500;
}

Rectangle Paddle::getRect(){
    return Rectangle{
        x - width/2, y-width/2,width,height
    };
}

void Paddle::Draw(){
    DrawRectangleRec(getRect(),WHITE);
}
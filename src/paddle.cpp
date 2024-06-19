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

//Method to allow the AI player to move the paddle
void Paddle::AutoMove(float targetY, float deltaTime){
    //Calculate the distance to the new paddle position
    //Slowly increase or decrease paddle movement speed depending on the distance
    //This eliminates any jitter while paddle movement by AI

    float distance = targetY - y;
    float speedModifier = 1.0f;
    float adjustedSpeed = speed * speedModifier * deltaTime;

    if (fabs(distance) > height / 4) {  // fabs ensures the distance is positive
        if (distance > 0 && (y < GetScreenHeight() - height)) {
            y += adjustedSpeed;
        } else if(distance < 0 && (y > 0)){
            y -= adjustedSpeed;
        }
    }
}
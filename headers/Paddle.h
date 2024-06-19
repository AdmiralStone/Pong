#ifndef PADDLE_H
#define PADDLE_H

#include "raylib.h"

class Paddle{
    public:
        float x,y;
        float speed;
        float height,width;

        Paddle(float startX, float startY);
        Rectangle getRect();
        void Draw();

};


#endif
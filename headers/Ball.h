#ifndef BALL_H
#define BALL_H

#include "raylib.h"

class Ball{
    public:
        float x,y;
        float speedX, speedY;
        float radius;

        Ball();
        void Draw();
        void Reset();
};

#endif
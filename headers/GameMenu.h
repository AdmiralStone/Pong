#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "raylib.h"

class GameMenu{
    public:
        enum GameMode{NONE,SINGLE_PLAYER, MULTI_PLAYER};
        GameMode selectedMode;

        GameMenu();
        void Draw();
        void HandleInput();

};

#endif
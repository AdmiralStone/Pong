#include "GameMenu.h"

GameMenu::GameMenu() : selectedMode(NONE){}

void GameMenu::Draw(){
    ClearBackground(BLACK);
    const char* titleText = "Pong";
    const char* singlePlayerText = "1. Single Player";
    const char* multiPlayerText = "2. Multi Player ";

    DrawText(titleText,GetScreenWidth()/2 - MeasureText(titleText,50)/2 , 100, 50 , WHITE);
    DrawText(singlePlayerText,GetScreenWidth()/2 - MeasureText(singlePlayerText,30)/2 , 200, 30 , WHITE);
    DrawText(multiPlayerText,GetScreenWidth()/2 - MeasureText(multiPlayerText,30)/2 , 300, 30 , WHITE);
}

void GameMenu::HandleInput(){
    if(IsKeyPressed(KEY_ONE)){
        selectedMode = SINGLE_PLAYER;
    }

    if(IsKeyPressed(KEY_TWO)){
        selectedMode = MULTI_PLAYER;
    }
}


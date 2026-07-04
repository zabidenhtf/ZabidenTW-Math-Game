/* Copyright (C) 2026 Mykyta Polishyk */
/* This project is licensed under the MIT license. */
/* See the LICENSE file for details. */
#include <time.h>
#include <stdlib.h>
// TODO: Add modern C++ libraries

#include "MainMenu.hpp"
#include "Types.hpp"
#include "GameCore.hpp"

// TODO: In next update add working server leaderboard

BestScore Scores[8];

CMainMenu MainMenu;
CGameCore GameCore;

constexpr char CurrentVersion[12] = "1.1.0";

int main()
{
    srand(time(NULL));
    int IsRunning = 1;

    while(IsRunning == 1){
        IsRunning = MainMenu.Run();
    }
    return 0;
}

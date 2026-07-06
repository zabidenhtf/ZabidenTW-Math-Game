/* Copyright (C) 2026 Mykyta Polishyk */
/* This project is licensed under the MIT license. */
/* See the LICENSE file for details. */
#include "MainMenu.hpp"
#include "GameCore.hpp"
#include "Types.hpp"
#include <stdio.h>

extern SaveFile CurrentSave;
extern CGameCore GameCore;
extern void LoadSaveFile();

constexpr char CurrentVersion[12] = "1.1.0-trunk";
int CMainMenu::Run(){
        LoadSaveFile();
        printf("|-------------------------------------|\n");
        printf("|        -=ZabidenTW Math Game=-      |\n");
        printf("|-------------------------------------|\n");
        printf("|1.) Play; 2.) About; 3.) Best scores;|\n");
        printf("|4.) Exit                             |\n");
        printf("|-------------------------------------|\n\n");
        printf("Your option:");
        scanf("%d", &Selector);
        switch(Selector){
        default:
            printf("|------------------------------|\n");
            printf("|   This option didn't exist   |\n");
            printf("|------------------------------|\n");
            return 1;
        case 1:
            GameCore.Run();
            return 1;
        case 2:
            printf("|------------------------------------------------------------|\n");
            printf("|                      -= About =-                           |\n");
            printf("|------------------------------------------------------------|\n");
            printf("|This program made by Mykyta Polishyk also known as ZABIDENTW|\n");
            printf("|And this program licensed under MIT license                 |\n");
            printf("|Current version: %-11s                                |\n", CurrentVersion);
            printf("|------------------------------------------------------------|\n");
            return 1;
        case 3:
            printf("|------------------------------------------------------|\n");
            printf("|                  -= Best scores =-                   |\n");
            printf("|------------------------------------------------------|\n");
            printf("| %-5s | %-24s | %-7s | %-7s |\n", "Place", "Player name", "Score", "Round");

            for (int i = 0; i < 8; i++){
                printf("| %-5d | %-24s | %-7d | %-7d |\n",
                       i + 1,
                       CurrentSave.Scores[i].Name,
                       CurrentSave.Scores[i].Score,
                       CurrentSave.Scores[i].Round);
            }
            printf("|------------------------------------------------------|\n");
            return 1;
        case 4:
            printf("|-----------------------------------------------------------|\n");
            printf("|Are you sure to quit? All of your progress will reset (Y/N)|\n");
            printf("|-----------------------------------------------------------|\n");
            printf("Your option:");
            scanf(" %c", &QuitSelector);
            if (QuitSelector == 'Y' || QuitSelector == 'y'){
                return 0;
            }
            else{
                return 1;
            }
        }
}
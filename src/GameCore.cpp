/* Copyright (C) 2026 Mykyta Polishyk */
/* This project is licensed under the MIT license. */
/* See the LICENSE file for details. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "GameCore.hpp"
#include "Types.hpp"

extern SaveFile CurrentSave;
extern void SaveSaveFile();

void CGameCore::Run(){
    MaxNumber = 10;
    CurrentRound = 1;
    TypeCounter = 0;
    Type = false;
    Lives = 5;
    Score = 0;
    struct timespec start, end;
    while (Lives > 0){
        if (TypeCounter == 3){
            if (Type == true){
                Type = false;
            }
            else{
                Type = true;
            }
            TypeCounter = 0;
        }
        Num1 = rand() % MaxNumber;
        Num2 = rand() % MaxNumber;
        clock_gettime(CLOCK_MONOTONIC, &start);
        printf("-------------------------------\n");
        printf("Lives: %d; Score: %d; Round: %d  \n", Lives, Score, CurrentRound);
        printf("-------------------------------\n");
        if (Type == true){
            printf("%d + %d = ?\n", Num1, Num2);
        }
        else{
            printf("%d - %d = ?\n", Num1, Num2);
        }
        printf("-------------------------------\n");
        scanf("%d", &Answer);
        if (Type == true){
            CorrectAnswer = Num1 + Num2;
        }
        else{
            CorrectAnswer = Num1 - Num2;
        }
        if (Answer == CorrectAnswer){
            clock_gettime(CLOCK_MONOTONIC, &end);

            double elapsed = 1 + (end.tv_sec - start.tv_sec) +
                            (end.tv_nsec - start.tv_nsec) / 1000000000.0;
            printf("Correct!");
            Score += 1000/elapsed;
            MaxNumber++;
            TypeCounter++;
        }
        else{
            printf("Wrong, try again\n");
            printf("%d\n", CorrectAnswer);
            Lives--;
        }
        CurrentRound++;
    }
    char PlayersName[32];
    printf("Write your name\n");
    scanf("%s", &PlayersName);
    if (Score > CurrentSave.Scores[7].Score) {
        strcpy(CurrentSave.Scores[7].Name, PlayersName);
        CurrentSave.Scores[7].Score = Score;
        CurrentSave.Scores[7].Round = CurrentRound - 1;
    }

    for (int i = 0; i < 8 - 1; i++) {
        for (int j = 0; j < 8 - i - 1; j++) {
            if (CurrentSave.Scores[j].Score < CurrentSave.Scores[j + 1].Score) {
                struct BestScore temp = CurrentSave.Scores[j];
                CurrentSave.Scores[j] = CurrentSave.Scores[j + 1];
                CurrentSave.Scores[j + 1] = temp;
            }
        }
    }
    printf("Score saved!\n");
    SaveSaveFile();
}
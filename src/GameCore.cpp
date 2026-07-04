/* Copyright (C) 2026 Mykyta Polishyk */
/* This project is licensed under the MIT license. */
/* See the LICENSE file for details. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "GameCore.hpp"
#include "Types.hpp"

extern BestScore Scores[8];

void CGameCore::Run(){
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
    if (Score > Scores[7].Score) {
        strcpy(Scores[7].Name, PlayersName);
        Scores[7].Score = Score;
        Scores[7].Round = CurrentRound - 1;
    }

    for (int i = 0; i < 8 - 1; i++) {
        for (int j = 0; j < 8 - i - 1; j++) {
            if (Scores[j].Score < Scores[j + 1].Score) {
                struct BestScore temp = Scores[j];
                Scores[j] = Scores[j + 1];
                Scores[j + 1] = temp;
            }
        }
    }
    printf("Score saved!\n");
}
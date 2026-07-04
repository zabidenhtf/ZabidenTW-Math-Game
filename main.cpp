/* Copyright (C) 2026 Mykyta Polishyk */
/* This project is licensed under the MIT license. */
/* See the LICENSE file for details. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// TODO: In next update add working server leaderboard

struct BestScore{
    char Name[32] = "No name";
    int Score = 0;
    int Round = 0;
};

BestScore Scores[8];

void StartNewGame(){
    struct timespec start, end;
    int MaxNumber = 10;
    int CurrentRound = 1;
    int TypeCounter = 0;
    bool Type = false;
    int Num1, Num2;
    int Answer;
    int CorrectAnswer;
    int Lives = 5;
    int Score = 0;
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
            printf("Correct!, time:%d\n", TypeCounter);
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

int MainMenu(){
    int Selector;
    char QuitSelector;
    printf("ZabiDenTW Math Game\n");
    printf("------------------------------------\n");
    printf("1.) Play; 2.) About; 3.) Best scores;\n");
    printf("4.) Exit\n");
    printf("------------------------------------\n");
    printf("Your option:");
    scanf("%d", &Selector);
    switch(Selector){
    default:
        printf("------------------------------\n");
        printf("This option didn't exist\n");
        printf("------------------------------\n");
        return 1;
    case 1:
        StartNewGame();
        return 1;
    case 2:
        printf("------------------------------------------------------------\n");
        printf("This program made by Mykyta Polishyk also known as ZABIDENTW\n");
        printf("And this program licensed under MIT license\n");
        printf("Current version: 1.0.0\n");
        printf("------------------------------------------------------------\n");
        return 1;
    case 3:
        printf("-------------------------------\n");
        printf("           Best scores\n");
        printf("-------------------------------\n");
        printf("[Player name][Score][Round]\n");
        for (int i = 0; i < 8; i++){
            printf("[%s][%d][%d]\n", Scores[i].Name, Scores[i].Score, Scores[i].Round);
        }
        printf("-------------------------------\n");
        return 1;
    case 4:
        printf("Are you sure to quit? All of your progress will reset (Y/N)\n");
        printf("------------------------------------\n");
        scanf(" %c", &QuitSelector);
        if (QuitSelector == 'Y' || QuitSelector == 'y'){
            return 0;
        }
        else{
            return 1;
        }
    }
}

int main()
{
    srand(time(NULL));
    int IsRunning = 1;

    while(IsRunning == 1){
        IsRunning = MainMenu();
    }
    return 0;
}

/* Copyright (C) 2026 Mykyta Polishyk */
/* This project is licensed under the MIT license. */
/* See the LICENSE file for details. */
#pragma once

class CGameCore{
public:
    CGameCore() = default;
    void Run();
private:
    int MaxNumber = 10;
    int CurrentRound = 1;
    int TypeCounter = 0;
    bool Type = false;
    int Num1, Num2;
    int Answer;
    int CorrectAnswer;
    int Lives = 5;
    int Score = 0;
};
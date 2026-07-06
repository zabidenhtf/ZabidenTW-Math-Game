/* Copyright (C) 2026 Mykyta Polishyk */
/* This project is licensed under the MIT license. */
/* See the LICENSE file for details. */
#pragma once

struct BestScore{
    char Name[32];
    int Score;
    int Round;
};

struct SaveFile{
	BestScore Scores[8];
};
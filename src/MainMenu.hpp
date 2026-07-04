/* Copyright (C) 2026 Mykyta Polishyk */
/* This project is licensed under the MIT license. */
/* See the LICENSE file for details. */
#pragma once

class CMainMenu{
public:
    CMainMenu() = default;
    int Run();
private:
    int Selector;
    char QuitSelector;
};
/* Copyright (C) 2026 Mykyta Polishyk */
/* This project is licensed under the MIT license. */
/* See the LICENSE file for details. */
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
// TODO: Start using modern C++ libraries
#include "MainMenu.hpp"
#include "Types.hpp"
#include "GameCore.hpp"


CMainMenu MainMenu;
CGameCore GameCore;
SaveFile CurrentSave;
int IsRunning = 1;

void SaveSaveFile(){
	// Writing save into file
    std::ofstream outFile("save.dat", std::ios::binary);
    outFile.write(reinterpret_cast<const char*>(&CurrentSave), sizeof(CurrentSave));
    outFile.close();
}

void LoadSaveFile(){
	std::ifstream inFile("save.dat", std::ios::binary);
    
    if (inFile.is_open()) {
    	// Reading data inside file and writing into CurrentSave structure
        inFile.read(reinterpret_cast<char*>(&CurrentSave), sizeof(CurrentSave));
        inFile.close();
    } else {
        std::cerr << "Cant load save file, maybe save file doesnt exist!" << std::endl;
        SaveSaveFile();
    }
}

int main()
{
    srand(time(NULL));

    while(IsRunning == 1){
        IsRunning = MainMenu.Run();
    }
    return 0;
}

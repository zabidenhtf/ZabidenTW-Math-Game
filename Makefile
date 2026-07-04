SOURCES = src/GameCore.cpp src/MainMenu.cpp src/Main.cpp 

ifeq ($(OS),Windows_NT)
	CFLAGS = -ffunction-sections -fdata-sections -Os -static -static-libgcc -static-libstdc++
	OUT = ./bin/Release/zabimg.exe
else
	CFLAGS = -ffunction-sections -fdata-sections -Os
	OUT = ./bin/Release/zabimg
endif

all:
	g++ $(SOURCES) $(CFLAGS) -o $(OUT)

SOURCES = src/GameCore.cpp src/MainMenu.cpp src/Main.cpp 

ifeq ($(OS),Windows_NT)
	CFLAGS = -ffunction-sections -fdata-sections -Os -static -static-libgcc -static-libstdc++
	OUT = ./bin/zabimg.exe
else
	CFLAGS = -ffunction-sections -fdata-sections -Os
	OUT = ./bin/zabimg
endif

all:
	mkdir bin
	g++ $(SOURCES) $(CFLAGS) -o $(OUT)

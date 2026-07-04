all:
	g++ main.cpp -ffunction-sections -fdata-sections -static -static-libgcc -static-libstdc++ -Os -o ./bin/Release/zabimg

echo Building Project

g++ main.cpp src/utils.cpp src/button.cpp src/generic_game.cpp -lSDL2 -lSDL2_ttf -o main

echo running the project

./main

echo removing the executable

rm ./main

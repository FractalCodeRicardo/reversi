g++ *.cpp -o reversi $(pkg-config --cflags --libs sdl2 SDL2_ttf)

./reversi

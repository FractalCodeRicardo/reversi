```sh
#Ubuntu
#Install sdl
sudo yum install SDL2-devel

#run
g++ file.cpp -w -lSDL2 -o file


#Arch
sudo pacman -S gcc

sudo pacman -S sdl2
sudo pacman -S sdl2_ttf

g++ *.cpp -o myprogram $(pkg-config --cflags --libs sdl2 SDL2_ttf)
```


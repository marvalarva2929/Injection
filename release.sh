g++ -c src/*.cpp -std=c++14 -m64 -O3 -Wall -I include && g++ *.o -o bin/release/main -s -lSDL2main -lSDL2 -lSDL2_image && ./bin/release/main

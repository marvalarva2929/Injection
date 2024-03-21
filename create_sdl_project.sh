mkdir include src res bin
mkdir bin/debug mkdir bin/release
touch LICENCE
touch README.md
touch include/RenderWindow.hpp
touch src/RenderWindow.cpp

echo "std=c++11\n-I./../include" > src/compile-flags.txt
echo "g++ -c src/*.cpp -std=c++14 -m64 -O3 -Wall -I include && g++ *.o -o bin/release/main -s -lSDL2main -lSDL2 -lSDL2_image && ./bin/release/main" > release.sh
echo "g++ -c src/*.cpp -std=c++14 -m64 -g -Wall -I include && g++ *.o -o bin/debug/main -lSDL2main -lSDL2 -lSDL2_image && ./bin/debug/main" > debug.sh



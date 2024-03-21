#include "Object.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

Object::Object(std::string filename) {
    std::ifstream file; 
    file.open(filename);
    std::cout << file.fail() << " " << filename << std::endl; 
    while (!file.eof()) {
        std::string c;
        std::getline(file, c);
        if (c[0] == 'v') {
            std::string vert = c.substr(1);
            std::stringstream ss; ss << vert;  
            float one, two, three;
            ss >> one >> two >> three;
            Points.emplace_back(one * 0.02f, two * 0.02f, three * 0.02f); 
        } else if (c[0] == 'f') {
            std::string face = c.substr(1);
            std::stringstream ss; ss << face;
            int last = -1; 
            while (!ss.eof()) {
                int ind; ss >> ind; ind--;
                if (last != -1)
                    Edges.emplace_back(last, ind);
                last = ind;
            }
        }
    }
    //std::string next = " ";
    //while (true) {
    //    while (next[0] != 'v') file >> next, std::cout << next << std::endl;
    //    float one, two, three;
    //    file >> one >> two >> three;
    //    std::cout << one << " " << two << " " << three << std::endl;
    //}
}

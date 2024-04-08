#include <iostream>

#include "Elementa/Engine.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Elementa::initEngine("test", 800, 600);
    Elementa::startEngine();
    return 0;
}

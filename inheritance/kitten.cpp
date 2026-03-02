#include "kitten.hpp"
#include <iostream>

Kitten::Kitten() : GameObject(0, 0, 10, 5, "kitten") {}

Kitten::Kitten(int x, int y) : GameObject(x, y, 10, 5, "kitten") {}

Kitten::~Kitten() {}

void Kitten::onCollision(const GameObject&) {
    std::cout << "MEWWWW" << std::endl;
}

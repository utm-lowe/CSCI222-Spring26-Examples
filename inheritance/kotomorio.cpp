#include "kotomorio.hpp"

Kotomorio::Kotomorio() : GameObject(0, 0, 12, 12, "kotomorio") {}

Kotomorio::Kotomorio(int x, int y) : GameObject(x, y, 12, 12, "kotomorio") {}

Kotomorio::~Kotomorio() {}

void Kotomorio::onCollision(const GameObject& other) {
    if(other.getWidth() <= getWidth() && other.getHeight() <= getHeight()) {
        setWidth(getWidth() + other.getWidth());
        setHeight(getHeight() + other.getHeight());
    }
}

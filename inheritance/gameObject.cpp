#include "gameObject.hpp"

GameObject::GameObject() : x(0), y(0), w(0), h(0), category("unknown") {}

GameObject::GameObject(int x, int y, int w, int h, std::string category)
    : x(x), y(y), w(w), h(h), category(category) {}

GameObject::~GameObject() {}

int GameObject::getX() const {
    return x;
}

int GameObject::getY() const {
    return y;
}

int GameObject::getWidth() const {
    return w;
}

int GameObject::getHeight() const {
    return h;
}

std::string GameObject::getCategory() const {
    return category;
}

void GameObject::setX(int x) {
    this->x = x;
}

void GameObject::setY(int y) {
    this->y = y;
}

void GameObject::setWidth(int w) {
    this->w = w;
}

void GameObject::setHeight(int h) {
    this->h = h;
}

void GameObject::setCategory(std::string category) {
    this->category = category;
}

bool GameObject::isColliding(const GameObject& other) const {
    return x < other.x + other.w &&
           x + w > other.x &&
           y < other.y + other.h &&
           y + h > other.y;
}

void GameObject::onCollision(const GameObject& other) {
    // Default collision response: do nothing
}

#ifndef KITTEN_H
#define KITTEN_H
#include "gameObject.hpp"

class Kitten : public GameObject {
public:
    Kitten();
    Kitten(int x, int y);

    virtual ~Kitten();

    virtual void onCollision(const GameObject& other) override;
};

#endif

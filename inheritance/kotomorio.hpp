#ifndef KOTOMORIO_H
#define KOTOMORIO_H
#include "gameObject.hpp"

class Kotomorio : public GameObject {
public:
    Kotomorio();
    Kotomorio(int x, int y);

    virtual ~Kotomorio();

    virtual void onCollision(const GameObject& other) override;
};

#endif
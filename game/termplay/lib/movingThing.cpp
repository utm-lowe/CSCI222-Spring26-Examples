/**
 * @file movingThing.cpp
 * @brief Implementation of MovingThing which extends Thing with velocity
 */
#include "movingThing.h"

// Constructor: forward to Thing and set velocities
MovingThing::MovingThing(double x, double y, double width, double height, double vx, double vy)
    : Thing(x, y, width, height), vx(vx), vy(vy)
{
}

// Destructor
MovingThing::~MovingThing() {}

// Update: move by velocity
void MovingThing::update()
{
    double vx = getVx();
    double vy = getVy();

    // erase ourselves if we are moving
    if (vx != 0 || vy != 0)
        erase();

    // x and y are protected in Thing, so modify directly
    setPosition(getX()+vx, getY()+vy);
}

// Velocity accessors
double MovingThing::getVx() const { return vx; }
double MovingThing::getVy() const { return vy; }

void MovingThing::setVelocity(double newVx, double newVy)
{
    vx = newVx;
    vy = newVy;
}

// Resolve overlap with another thing.
void MovingThing::resolveOverlap(const Thing* other)
{
    // Simple AABB collision resolution
    while(isCollidingWith(other))
    {
        Thing::Collision dir = collisionDirection(other);
        switch(dir)
        {
            case Thing::LEFT:
                x=other->getX() + other->getWidth();
                break;
            case Thing::RIGHT:
                x--;
                x=other->getX() - getWidth();
                break;
            case Thing::TOP:
                y=other->getY() + other->getHeight();
                break;
            case Thing::BOTTOM:
                y=other->getY() - getHeight();
                break;
            default:
                // No collision or unknown direction, break to avoid infinite loop
                return;
        }
    }
}
/**
 * @file ball.h
 * @author your name (you@domain.com)
 * @brief A bouncing ball.
 * @version 0.1
 * @date 2026-03-09
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef BALL_H
#define BALL_H
#include <termplay.h>

class Ball : public MovingThing {
public:
    Ball(double x, double y);
    virtual ~Ball();

    virtual void draw() const override;
};

#endif // BALL_H
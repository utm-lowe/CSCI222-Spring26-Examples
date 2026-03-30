#include <ball.h>
#include <termplay.h>
#include <iostream>

Ball::Ball(double x, double y) : MovingThing(x, y, 1, 1, 0, 0)
{
    // nothing to do here
}

Ball::~Ball()
{
    // nothing to do here
}

void Ball::draw() const
{
    // Draw the ball as a single character (e.g., 'O') at its current position.
    // You can customize this to use different characters or colors if desired.
    setCursorPosition(static_cast<int>(x), static_cast<int>(y));
    setForeground(fgColor);
    setBackground(bgColor);
    std::cout << "*"; // Represent the ball with 'O'
}
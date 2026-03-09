/**
 * @file thing.cpp
 * @brief Implementation for Thing base class
 */
#include "thing.h"
#include "terminal.h"
#include <cmath>
#include <iostream>


// Constructor
Thing::Thing(double x, double y, double width, double height)
    : x(x), y(y), width(width), height(height)
{
}

// Virtual destructor
Thing::~Thing() {}

// Getters
double Thing::getX() const { return x; }
double Thing::getY() const { return y; }
double Thing::getWidth() const { return width; }
double Thing::getHeight() const { return height; }

// Setters
void Thing::setPosition(double newX, double newY)
{
    x = newX;
    y = newY;
}

void Thing::setSize(double newWidth, double newHeight)
{
    width = newWidth;
    height = newHeight;
}

// Color accessors
void Thing::setForeground(Color color) { fgColor = color; }
void Thing::setBackground(Color color) { bgColor = color; }
Color Thing::getForeground() const { return fgColor; }
Color Thing::getBackground() const { return bgColor; }

// Erase by painting spaces over the bounding box using terminal helpers.
void Thing::erase() const
{
    double ix = getX();
    double iy = getY();
    double iw = std::max(0, (int)getWidth());
    double ih = std::max(0, (int)getHeight());

    if (iw <= 0 || ih <= 0) return;

    // Ensure 1-based positions
    if (ix < 1) ix = 1;
    if (iy < 1) iy = 1;

    Color fg = fgColor;
    Color bg = bgColor;

    if (bg != DEFAULT) setBackgroundColor(bg);
    if (fg != DEFAULT) setTextColor(fg);

    // print out a block of blanks.
    std::string blanks(iw, ' ');
    for (int row = 0; row < ih; ++row) {
        cursorPosition(ix, iy + row);
        std::cout << blanks;
    }
}

// Axis-Aligned Bounding Box (AABB) intersection check
bool Thing::isCollidingWith(const Thing *other)
{
    double leftA = getX();
    double rightA = getX() + getWidth();
    double topA = getY();
    double bottomA = getY() + getHeight();

    double leftB = other->getX();
    double rightB = other->getX() + other->getWidth();
    double topB = other->getY();
    double bottomB = other->getY() + other->getHeight();

    // No overlap cases
    if (rightA <= leftB)
        return false;
    if (leftA >= rightB)
        return false;
    if (bottomA <= topB)
        return false;
    if (topA >= bottomB)
        return false;

    return true;
}

// Determine collision direction of `other` relative to `this`.
Thing::Collision Thing::collisionDirection(const Thing *other)
{
    if (!isCollidingWith(other))
        return NONE;

    // Compute centers
    double cxA = getX() + getWidth() / 2.0;
    double cyA = getY() + getHeight() / 2.0;
    double cxB = other->getX() + other->getWidth() / 2.0;
    double cyB = other->getY() + other->getHeight() / 2.0;

    // Compute half extents
    double halfW = (getWidth() + other->getWidth()) / 2.0;
    double halfH = (getHeight() + other->getHeight()) / 2.0;

    // Compute difference between centers
    double dx = cxB - cxA;
    double dy = cyB - cyA;

    // Compute overlap on both axes
    double overlapX = halfW - std::abs(dx);
    double overlapY = halfH - std::abs(dy);

    // The smaller overlap is the axis of least penetration -> collision side
    if (overlapX < overlapY)
    {
        // Collision is on left or right of A
        if (dx > 0)
        {
            return RIGHT; // B is to the right of A -> collision on A's right side
        }
        else
        {
            return LEFT;
        }
    }
    else
    {
        // Collision is on top or bottom of A
        if (dy > 0)
        {
            return BOTTOM; // B is below A -> collision on A's bottom side
        }
        else
        {
            return TOP;
        }
    }
}

// handle key events
void Thing::handleKey(const std::string &key)
{
    // nothing to do in general
}

// Handle collisions with other object.
void Thing::handleCollision(Thing *other)
{
    // nothing to do in general
}
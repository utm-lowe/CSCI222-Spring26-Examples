/**
 * @file thing.h
 * @author Bob Lowe <rlowe8@utm.edU>
 * @brief A drawable thing in the game.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef THING_H
#define THING_H

#include <string>
#include "terminal.h"

class Thing
{
public:
    /**
     * @brief Construct a new Thing object
     * 
     * @param x 
     * @param y 
     * @param width 
     * @param height 
     */
    Thing(double x, double y, double width, double height);

    /**
     * @brief Destroy the Thing object
     * 
     */
    virtual ~Thing();

    /**
     * @brief Draw the thing on the screen.
     * 
     */
    virtual void draw() const = 0;

    /**
     * @brief Update the thing's state.
     * 
     */
    virtual void update() = 0;    

    /**
     * @brief Determines if this thing is colliding with another thing.
     * @return Collision
     */
    virtual bool isCollidingWith(const Thing* other);

    /**
     * @brief Collision codes
     * 
     */
    enum Collision { NONE=0, TOP, BOTTOM, LEFT, RIGHT};

    /**
     * @brief Get the direction of the collision with another thing.
     * @param other The other thing to check for collision.
     * @return Collision The direction of the collision.
     */
    virtual Collision collisionDirection(const Thing* other);

    /**
     * @brief Erase this thing by painting spaces over its bounding box.
     */
    virtual void erase() const;

    /**
     * @brief Get the x-coordinate of the thing.
     * 
     * @return double 
     */
    virtual double getX() const;

    /**
     * @brief Get the y-coordinate of the thing.
     * 
     * @return double 
     */
    virtual double getY() const;

    /**
     * @brief Get the Width of the thing.
     * 
     * @return double 
     */
    virtual double getWidth() const;

    /**
     * @brief Get the Height of the thing.
     * 
     * @return double 
     */
    virtual double getHeight() const;

    /**
     * @brief Set the Position of the thing.
     * 
     * @param newX 
     * @param newY 
     */
    virtual void setPosition(double newX, double newY);

    /**
     * @brief Set the Size of the thing.
     * 
     * @param newWidth 
     * @param newHeight 
     */
    virtual void setSize(double newWidth, double newHeight);

    // Color support (optional). Use terminal Color enum values; DEFAULT means no change.
    virtual void setForeground(Color color);
    virtual void setBackground(Color color);
    virtual Color getForeground() const;
    virtual Color getBackground() const;

    /**
     * @brief Handle key press events.
     * 
     * @param key 
     */
    virtual void handleKey(const std::string &key);

    /**
     * @brief Handle collisions with other object.
     * 
     * @param other 
     */
    virtual void handleCollision(Thing *other);

protected:
    double x;
    double y;
    double width;
    double height;
    // Foreground/background colors (use terminal Color values). DEFAULT means no change.
    Color fgColor = DEFAULT;
    Color bgColor = DEFAULT;
};

#endif // THING_H
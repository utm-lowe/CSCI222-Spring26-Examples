/**
 * @file movingThing.h
 * @author Class definition for a moving thing.
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef MOVINGTHING_H
#define MOVINGTHING_H
#include "thing.h"

class MovingThing : public Thing
{
public:
    /**
     * @brief Construct a new Moving Thing object   
     * 
     * @param x 
     * @param y 
     * @param width 
     * @param height 
     * @param vx - X velocity (default 0)
     * @param vy - Y velocity (default 0)
     */
    MovingThing(double x, double y, double width, double height, double vx=0, double vy=0);

    /**
     * @brief Destroy the Moving Thing object
     * 
     */
    virtual ~MovingThing();

    /**
     * @brief Update the position of the moving thing
     * 
     */
    virtual void update();

    /**
     * @brief Get the x velocity of the object
     * 
     * @return double 
     */
    virtual double getVx() const;

    /**
     * @brief Get the y velocity of the object
     * 
     * @return double 
     */
    virtual double getVy() const;

    /**
     * @brief Set the Velocity object   
     * 
     * @param newVx 
     * @param newVy 
     */
    virtual void setVelocity(double newVx, double newVy);

    /**
     * @brief Resolve overlap with another thing.
     * 
     * @param other 
     */
    virtual void resolveOverlap(const Thing* other);
protected:
    double vx; // Velocity in x direction
    double vy; // Velocity in y direction
};
#endif
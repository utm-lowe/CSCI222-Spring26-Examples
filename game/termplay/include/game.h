/**
 * @file game.h
 * @author Bob Lowe <rlowe8@utm.edu>
 * @brief This is the base class of a generic game.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef GAME_H
#define GAME_H
#include <vector>
#include "thing.h"

class Game
{
public:
    /**
     * @brief Construct a new Game object
     * 
     */
    Game();

    /**
     * @brief Destroy the Game object
     * 
     */
    virtual ~Game();

    /**
     * @brief Add a thing to the game
     * 
     * @param thing 
     */
    virtual void add(Thing *thing);

    /**
     * @brief Stop the game from running.
     * 
     */
    virtual void stop();

    /**
     * @brief Run the game loop.
     * 
     */
    virtual void run();
    
    /**
     * @brief The number of things in the game.
     * 
     * @return int 
     */
    virtual int size();

    /**
     * @brief Index operator for the game's things.
     * 
     * @param i 
     * @return Thing* 
     */
    virtual Thing* operator[](int i);

    /**
     * @brief Handle the end of each frame. (Hook for derived object logic.)
     * 
     */
    virtual void handleFrame();

    /**
     * @brief Get the current frame count.
     * 
     * @return int 
     */
    virtual int getFrame();

    /**
     * @brief Set the frames per second.
     * 
     * @param fps 
     */
    virtual void setFps(int fps);

    /**
     * @brief Get the frames per second.
     * 
     * @return int
     */
    virtual int getFps();

protected:
    /**
     * @brief The collection of things.
     * 
     */
    std::vector<Thing *> things;

    /** 
     * @brief True if the game is running, false otherwise.
     */
    bool running;

    /**
     * @brief The games frame counter.
     * 
     */
    int frame;

    /**
     * @brief The inter-frame delay in microseconds.
     * 
     */
    int delay;
};

#endif
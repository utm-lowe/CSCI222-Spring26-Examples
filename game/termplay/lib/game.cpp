#include <iostream>
#include <string>
#include <unistd.h>
#include "terminal.h"
#include "keyboard.h"
#include "movingThing.h"
#include "thing.h"
#include "game.h"

//////////////////////////////////////////
// Static Helpers
//////////////////////////////////////////

void broadcastKey(const std::string &key, std::vector<Thing *> &things)
{
    for(Thing *t : things) {
        t->handleKey(key);
    }
}

void updateThings(std::vector<Thing *> &things)
{
    for(Thing *t : things) {
        t->update();
    }
}


void drawThings(std::vector<Thing *> &things)
{
    for(Thing *t : things) {
        t->draw();
    }
}

static bool isMovingThing(Thing *t) {
    return dynamic_cast<MovingThing*>(t) != nullptr;
}

void resolveCollisions(std::vector<Thing *> &things) 
{
    for(Thing *t : things) {
        // check only the aggressors in the collisions
        if(!isMovingThing(t)) continue; 

        for(Thing *other : things) {
            // no self collision
            if(t == other) continue;

            if(t->isCollidingWith(other)) {
                t->handleCollision(other);
                // handle the reverse direction for non-moving things
                if(!isMovingThing(other)) {
                    other->handleCollision(t);
                }
            }
        }
    }
}

void enterGameMode()
{
    clearScreen();
    initKeyboard();
    hideCursor();
}

void leaveGameMode()
{
    closeKeyboard();
    reset();
    clearScreen();
}

/**
 * @brief Construct a new Game object
 *
 */
Game::Game()
{
    // default to 20fps
    setFps(20);
}

/**
 * @brief Destroy the Game object
 *
 */
Game::~Game()
{
    leaveGameMode();
}

/**
 * @brief Add a thing to the game
 *
 * @param thing
 */
void Game::add(Thing *thing)
{
    things.push_back(thing);
}

/**
 * @brief Stop the game from running.
 *
 */
void Game::stop()
{
    running = false;
}

/**
 * @brief Run the game loop.
 *
 */
void Game::run()
{
    std::string key;
    running = true;

    enterGameMode();
    do {
        key = getKey();
        if(key == "esc") {
            stop();
            continue;
        }

        broadcastKey(key, things);
        updateThings(things);
        resolveCollisions(things);
        drawThings(things);
        std::cout.flush();
        handleFrame();
        usleep(delay);
    } while(key != "esc");
    leaveGameMode();
}

/**
 * @brief The number of things in the game.
 *
 * @return int
 */
int Game::size()
{
    return things.size();;
}

/**
 * @brief Index operator for the game's things.
 *
 * @param i
 * @return Thing*
 */
Thing* Game::operator[](int i)
{
    return things[i];
}

/**
 * @brief Handle the end of each frame. (Hook for derived object logic.)
 *
 */
void Game::handleFrame()
{
    // nothing to do for the general object.
}

/**
 * @brief Get the current frame count.
 *
 * @return int
 */
int Game::getFrame()
{
    return frame;
}

/**
 * @brief Set the frames per second.
 *
 * @param fps
 */
void Game::setFps(int fps)
{
   delay = 1000000/fps;
}

/**
 * @brief Get the frames per second.
 *
 * @return int
 */
int Game::getFps()
{
    return 1000000/delay;
}

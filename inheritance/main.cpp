#include <iostream>
#include <vector>
#include "gameObject.hpp"
#include "kotomorio.hpp"
#include "kitten.hpp"

using namespace std;

// handle collisions between game objects
void handleCollisions(vector<GameObject*>& gameObjects) {
    for(size_t i = 0; i < gameObjects.size(); ++i) {
        for(size_t j = i + 1; j < gameObjects.size(); ++j
        ) {
            if(gameObjects[i]->isColliding(*gameObjects[j])) {
                gameObjects[i]->onCollision(*gameObjects[j]);
                gameObjects[j]->onCollision(*gameObjects[i]);
            }
        }
    }
}

int main()
{
    Kitten kitten1;
    Kitten kitten2(100, 200);
    Kotomorio kotomorio1(50, 50);
    vector<GameObject*> gameObjects = {&kitten1, &kitten2, &kotomorio1};


    // create a game loop where the player specifies x and y coordinates and
    // then it handles collisions. x and y affect the kotomorio
    while(true) {
        int x, y;
        cout << "Enter x and y coordinates for the kotomorio (or -1 to quit): ";
        cin >> x >> y;
        if(x == -1 || y == -1) {
            break;
        }
        kotomorio1.setX(x);
        kotomorio1.setY(y);
        handleCollisions(gameObjects);
    }

    return 0;
}
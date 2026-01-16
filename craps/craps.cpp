/**
 * @file craps.cpp
 * @brief A simple simulation of the street craps game.
 * @author GitHub Copilot
 * @date January 16, 2026
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * @brief Simulates rolling two dice and returns the sum.
 * @return The sum of two dice rolls (2-12).
 */
int rollDice() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

/**
 * @brief Plays a single game of craps with pass/no-pass betting.
 */
void playCraps() {
    int point = 0;
    char bet;
    cout << "Welcome to Street Craps!\n";
    cout << "Do you want to bet on Pass (P) or No Pass (N)? ";
    cin >> bet;

    int roll = rollDice();
    cout << "You rolled: " << roll << endl;

    // Check for natural win (7 or 11) or craps (2, 3, or 12) on the come-out roll
    if (roll == 7 || roll == 11) {
        if (bet == 'P' || bet == 'p') {
            cout << "You win!\n";
        } else {
            cout << "You lose!\n";
        }
    } else if (roll == 2 || roll == 3 || roll == 12) {
        if (bet == 'N' || bet == 'n') {
            cout << "You win!\n";
        } else {
            cout << "You lose!\n";
        }
    } else {
        // Establish the point and continue rolling
        point = roll;
        cout << "Point is set to: " << point << endl;
        while (true) {
            roll = rollDice();
            cout << "You rolled: " << roll << endl;
            if (roll == point) {
                if (bet == 'P' || bet == 'p') {
                    cout << "You win!\n";
                } else {
                    cout << "You lose!\n";
                }
                break;
            } else if (roll == 7) {
                if (bet == 'N' || bet == 'n') {
                    cout << "You win!\n";
                } else {
                    cout << "You lose!\n";
                }
                break;
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    playCraps();
    return 0;
}
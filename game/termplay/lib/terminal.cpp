/**
 * @file terminal.cpp
 * @author Bob Lowe <rlowe8@utm.edu>
 * @brief A collection of functions for nifty terminal things.
 * @version 0.1
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include <cmath>
#include <algorithm>
#include "terminal.h"


// Clear the screen.
void clearScreen()
{
    std::cout << "\033[2J\033[H" << std::flush;
}

// Clear the current line.
void clearLine()
{
    std::cout << "\033[2K\r" << std::flush;
}

 // Hide the cursor
void hideCursor()
{
    std::cout << "\033[?25l" << std::flush;
}

// Show the cursor
void showCursor()
{
    std::cout << "\033[?25h" << std::flush;
}

// Set the cursor position.
void cursorPosition(double x, double y)
{
    int cx = std::max(1.0, std::round(x));
    int cy = std::max(1.0, std::round(y));
    std::cout << "\033[" << cy << ";" << cx << "H";
}

// Set the text color.
void setTextColor(Color color)
{
    std::cout << "\033[3" << color << "m";
}

// Set the background color.
void setBackgroundColor(Color color)
{
    std::cout << "\033[4" << color << "m";
}

// Reset the terminal to all defaults.
void reset()
{
    showCursor();
    setTextColor(DEFAULT);
    setBackgroundColor(DEFAULT);
}
/**
 * @file terminal.h
 * @author Bob Lowe <rlowe8@utm.edu>
 * @brief A collection of functions for nifty terminal things.
 * @version 0.1
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef TERMINAL_HPP
#define TERMINAL_HPP

enum Color {
    BLACK = 0,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
    DEFAULT = 9
};

/**
 * @brief Clear the screen.
 * 
 */
void clearScreen();

/**
 * @brief Clear the current line.
 * 
 */
void clearLine();

/**
 * @brief Hide the cursor
 * 
 */
void hideCursor();

/**
 * @brief Show the cursor
 * 
 */
void showCursor();

/**
 * @brief Set the cursor position.
 * 
 * @param x The x position (left most column is 1)
 * @param y The y position (top most row is 1)
 */
void cursorPosition(double x, double y);

/**
 * @brief Set the text color.
 * 
 * @param color The color to set the text to.
 */
void setTextColor(Color color);

/**
 * @brief Set the background color.
 * 
 * @param color The color to set the background to.
 */
void setBackgroundColor(Color color);

/** 
 * @brief Reset the terminal to all defaults.
 * 
 */
void reset();
#endif
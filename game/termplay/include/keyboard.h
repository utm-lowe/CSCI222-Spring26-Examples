/**
 * @file keyboard.h
 * @author Bob Lowe <rlowe8@utm.edu>
 * @brief A set of functions for raw keyboard support.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <string>
#include <iostream>

/**
 * @brief Put keyboad in raw mode.
 * 
 */
void initKeyboard();

/**
 * @brief Restore keyboard to normal mode.
 * 
 */
void closeKeyboard();

/**
 * @brief Get a key from the keyboard.
 * This is non-blocking. The result will be as follows:
 *  - If no key was pressed, an empty string is returned.
 *  - If a printable key was pressed, that key is returned as 1 character string. 
 *  - Cursor keys: "up", "down", "left", "right"
 *  - Escape key: "esc"
 * @return std::string The key that was pressed.
 */
std::string getKey();

#endif
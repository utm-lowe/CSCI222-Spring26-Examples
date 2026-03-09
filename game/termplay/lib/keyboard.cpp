/**
 * @file keyboard.h
 * @author Bob Lowe <rlowe8@utm.edu>
 * @brief A set of functions for raw keyboard support.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "keyboard.h"
#include "terminal.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <cstdio>
#include <cstdlib>

static struct termios initial_settings;
static int initial_flags=-1;
static bool keyboard_active = false;

static void restoreTty()
{
    if (isatty(STDIN_FILENO) && keyboard_active) {
        tcsetattr(STDIN_FILENO, TCSANOW, &initial_settings);
        if (initial_flags != -1) fcntl(STDIN_FILENO, F_SETFL, initial_flags);
    }
    keyboard_active=false;
}

static void onSignal(int sig)
{
    restoreTty();
    reset();
    signal(sig, SIG_DFL);   // restore default
    raise(sig);             // re-raise
}

// Set terminal to raw mode
void initKeyboard()
{
    if(!isatty(STDIN_FILENO) || keyboard_active) return;

    initial_flags = fcntl(0, F_GETFL, 0); // get the initial stdin flags

    // Get initial settings for later restoration
    if (tcgetattr(STDIN_FILENO, &initial_settings) == -1) { perror("tcgetattr"); return; }
    initial_flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    if (initial_flags == -1) { perror("fcntl(F_GETFL)"); }

    // set up raw mode
    struct termios raw = initial_settings;
    raw.c_lflag &= ~(ICANON | ECHO);
    raw.c_cc[VMIN]  = 0;
    raw.c_cc[VTIME] = 0;

    // apply raw mode settings
    if (tcsetattr(STDIN_FILENO, TCSANOW, &raw) == -1) { perror("tcsetattr"); }

    // turn on non-blocking mode
    if (initial_flags != -1 &&
        fcntl(STDIN_FILENO, F_SETFL, initial_flags | O_NONBLOCK) == -1) {
        perror("fcntl(F_SETFL)");
    }

    // the keyboard is now in operation
    keyboard_active = true;

    // make sure we always restore
    std::atexit(restoreTty);
    struct sigaction sa{};
    sa.sa_handler = onSignal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sigaction(SIGINT,  &sa, nullptr);
    sigaction(SIGTERM, &sa, nullptr);
    sigaction(SIGHUP,  &sa, nullptr);
    sigaction(SIGQUIT, &sa, nullptr);
}


// Restore keyboard to normal mode.
void closeKeyboard()
{
    restoreTty();
}


/**
 * @brief Get a key from the keyboard.
 * This is non-blocking. The result will be as follows:
 *  - If no key was pressed, an empty string is returned.
 *  - If a printable key was pressed, that key is returned as 1 character string. 
 *  - Cursor keys: "up", "down", "left", "right"
 *  - Escape key: "esc"
 * @return std::string The key that was pressed.
 */
std::string getKey()
{
    char ch;
    std::string result;

    // Try to read a character
    ssize_t n = read(0, &ch, 1);

    if (n == 1) {
        // If we read a character, check if it's part of an escape sequence
        if (ch == '\033') { // Escape character
            char seq[2];
            if (read(0, &seq[0], 1) == 1 && read(0, &seq[1], 1) == 1) {
                if (seq[0] == '[') {
                    switch (seq[1]) {
                        case 'A':
                            result = "up";
                            break;
                        case 'B':
                            result = "down";
                            break;
                        case 'C':
                            result = "right";
                            break;
                        case 'D':
                            result = "left";
                            break;
                        default:
                            result = "";
                            break;
                    }
                }
            } else {
                result = "esc"; // Just the escape key
            }
        } else if (isprint(ch) || ch == '\n') {
            result = std::string(1, ch); // Printable character or newline
        } else {
            result = ""; // Non-printable character
        }
    } else {
        result = ""; // No key pressed
    }


    return result;
}
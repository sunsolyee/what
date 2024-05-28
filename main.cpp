#include <ncurses.h>
#include "snake.h"

int main() {
    initscr();            // Initialize the window
    cbreak();             // Disable line buffering
    noecho();             // Don't echo() while we do getch
    curs_set(0);          // Hide the cursor
    keypad(stdscr, TRUE); // Enable F1, F2 etc...
    timeout(100);         // Set a delay for getch()

    SnakeGame game;
    game.run();

    endwin();             // End curses mode
    return 0;
}
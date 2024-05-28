#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <ncurses.h>

class SnakeGame {
public:
    SnakeGame();
    void run();

private:
    struct Point {
        int x, y;
    };

    void draw();
    void input();
    void logic();

    std::deque<Point> snake;
    Point fruit;
    int score;
    int width, height;
    bool gameOver;
    int direction; // 0: left, 1: right, 2: up, 3: down
};

#endif
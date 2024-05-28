#include "snake.h"
#include <cstdlib>

SnakeGame::SnakeGame() : score(0), gameOver(false), direction(1), width(50), height(25) {
    // Initialize the snake
    snake.push_back({ width / 2, height / 2 });
    snake.push_back({ width / 2 - 1, height / 2 });
    // Initialize the fruit
    fruit.x = rand() % width;
    fruit.y = rand() % height;
}

void SnakeGame::run() {
    while (!gameOver) {
        draw();
        input();
        logic();
    }
}

void SnakeGame::draw() {
    clear();
    // Draw the border
    for (int i = 0; i < width; ++i) {
        mvprintw(0, i, "#");
        mvprintw(height - 1, i, "#");
    }
    for (int i = 0; i < height; ++i) {
        mvprintw(i, 0, "#");
        mvprintw(i, width - 1, "#");
    }
    // Draw the snake
    for (auto& s : snake) {
        mvprintw(s.y, s.x, "O");
    }
    // Draw the fruit
    mvprintw(fruit.y, fruit.x, "F");
    // Draw the score
    mvprintw(height, 0, "Score: %d", score);
    refresh();
}

void SnakeGame::input() {
    int ch = getch();
    switch (ch) {
    case KEY_LEFT:
        if (direction != 1) direction = 0;
        break;
    case KEY_RIGHT:
        if (direction != 0) direction = 1;
        break;
    case KEY_UP:
        if (direction != 3) direction = 2;
        break;
    case KEY_DOWN:
        if (direction != 2) direction = 3;
        break;
    }
}


void SnakeGame::logic() {
    // Move the snake
    Point newHead = snake.front();
    switch (direction) {
    case 0: newHead.x--; break;
    case 1: newHead.x++; break;
    case 2: newHead.y--; break;
    case 3: newHead.y++; break;

        snake.push_front(newHead);

        // Check for collision with the wall
        if (newHead.x <= 0 || newHead.x >= width - 1 || newHead.y <= 0 || newHead.y >= height - 1) {
            gameOver = true;
        }
        // Check for collision with itself
        for (size_t i = 1; i < snake.size(); ++i) {
            if (snake[i].x == newHead.x && snake[i].y == newHead.y) {
                gameOver = true;
            }
        }
        // Check for eating the fruit
        if (newHead.x == fruit.x && newHead.y == fruit.y) {
            score += 10;
            fruit.x = rand() % width;
            fruit.y = rand() % height;
        }
        else {
            snake.pop_back();
        }
    }
}
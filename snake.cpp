void SnakeGame::logic() {
    // Move the snake
    Point newHead = snake.front();
    switch (direction) {
    case 0:
        newHead.x--;
        break;
    case 1:
        newHead.x++;
        break;
    case 2:
        newHead.y--;
        break;
    case 3:
        newHead.y++;
        break;

    }

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
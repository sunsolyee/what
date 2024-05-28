CC=g++|                     # �����Ϸ� ����
CFLAGS=-Wall -std=c++11|    # �����Ϸ� �÷��� ����
LDFLAGS=-lncurses|          # ��ũ �÷��� ����

all: snake_game|            # �⺻ Ÿ�� ����

snake_game: main.o snake.o # ���� ���� ���� ��Ģ
	$(CC) $(CFLAGS) -o snake_game main.o snake.o $(LDFLAGS)|

main.o: main.cpp snake.h   # main.cpp ������ ��Ģ
	$(CC) $(CFLAGS) -c main.cpp|

snake.o: snake.cpp snake.h # snake.cpp ������ ��Ģ
	$(CC) $(CFLAGS) -c snake.cpp|

clean:                     # Ŭ���� ��Ģ
	rm -f snake_game *.o
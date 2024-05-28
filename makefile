CC=g++|                     # 컴파일러 지정
CFLAGS=-Wall -std=c++11|    # 컴파일러 플래그 지정
LDFLAGS=-lncurses|          # 링크 플래그 지정

all: snake_game|            # 기본 타겟 지정

snake_game: main.o snake.o # 실행 파일 생성 규칙
	$(CC) $(CFLAGS) -o snake_game main.o snake.o $(LDFLAGS)|

main.o: main.cpp snake.h   # main.cpp 컴파일 규칙
	$(CC) $(CFLAGS) -c main.cpp|

snake.o: snake.cpp snake.h # snake.cpp 컴파일 규칙
	$(CC) $(CFLAGS) -c snake.cpp|

clean:                     # 클린업 규칙
	rm -f snake_game *.o
asteroids: src/main.c
	$(CC) src/main.c -o build/asteroids.out -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Wextra -pedantic -std=c99
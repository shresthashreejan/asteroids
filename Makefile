CC = gcc
CFLAGS = -I./include -I./other_includes -Wall -Wextra -pedantic -std=c99
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

BUILD_DIR = build
OBJ = ${BUILD_DIR}/main.o ${BUILD_DIR}/asteroid.o
OUT = ${BUILD_DIR}/asteroids.out

$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT) $(LDFLAGS)

${BUILD_DIR}/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o ${BUILD_DIR}/main.o

${BUILD_DIR}/asteroid.o: src/asteroid.c
	$(CC) $(CFLAGS) -c src/asteroid.c -o ${BUILD_DIR}/asteroid.o

clean:
	rm -f $(OBJ) $(OUT)
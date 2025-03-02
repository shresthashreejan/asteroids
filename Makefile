CC = gcc
CFLAGS = -I./include -I./other_includes -Wall -Wextra -pedantic -std=c99
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

BUILD_DIR = build
OBJ = ${BUILD_DIR}/main.o ${BUILD_DIR}/asteroid.o ${BUILD_DIR}/raygui.o ${BUILD_DIR}/debug.o ${BUILD_DIR}/player.o ${BUILD_DIR}/projectile.o ${BUILD_DIR}/collision.o ${BUILD_DIR}/screen.o
OUT = ${BUILD_DIR}/asteroids.out

$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT) $(LDFLAGS)

${BUILD_DIR}/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o ${BUILD_DIR}/main.o

${BUILD_DIR}/asteroid.o: src/asteroid.c
	$(CC) $(CFLAGS) -c src/asteroid.c -o ${BUILD_DIR}/asteroid.o

${BUILD_DIR}/raygui.o: src/raygui.c
	$(CC) $(CFLAGS) -c src/raygui.c -o ${BUILD_DIR}/raygui.o

${BUILD_DIR}/debug.o: src/debug.c
	$(CC) $(CFLAGS) -c src/debug.c -o ${BUILD_DIR}/debug.o

${BUILD_DIR}/player.o: src/player.c
	$(CC) $(CFLAGS) -c src/player.c -o ${BUILD_DIR}/player.o

${BUILD_DIR}/projectile.o: src/projectile.c
	$(CC) $(CFLAGS) -c src/projectile.c -o ${BUILD_DIR}/projectile.o

${BUILD_DIR}/collision.o: src/collision.c
	$(CC) $(CFLAGS) -c src/collision.c -o ${BUILD_DIR}/collision.o

${BUILD_DIR}/screen.o: src/screen.c
	$(CC) $(CFLAGS) -c src/screen.c -o ${BUILD_DIR}/screen.o

clean:
	rm -f $(OBJ) $(OUT)
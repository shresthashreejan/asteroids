#include <stdlib.h>
#include <time.h>

#include "raylib.h"

#include "asteroid.h"
#include "constants.h"
#include "screen.h"
#include "texture.h"

static Asteroid asteroids[MAX_ASTEROIDS] = {0};

void UpdateDrawFrame(void);

int main() {
	srand(time(0));
	SetTargetFPS(240);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
	LoadAllTextures();
	while(!WindowShouldClose()) {
		UpdateDrawFrame();
	}
	UnloadTextures();
	CloseWindow();
	return 0;
}

void UpdateDrawFrame(void) {
	BeginDrawing();
		ScreenController(asteroids);
	EndDrawing();
}
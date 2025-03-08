#include <stdlib.h>
#include <time.h>

#include "raylib.h"

#include "asteroid.h"
#include "constants.h"
#include "screen.h"
#include "texture.h"
#include "sounds.h"

static Asteroid asteroids[MAX_ASTEROIDS] = {0};

void UpdateDrawFrame(void);

int main() {
	srand(time(0));
	SetTargetFPS(240);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
	SoundController();
	LoadAllTextures();
	SetExitKey(KEY_NULL); // Prevents esc key from closing the game window
	while(!WindowShouldClose()) {
		UpdateDrawFrame();
	}
	UnloadAllSounds();
	UnloadTextures();
	CloseWindow();
	return 0;
}

void UpdateDrawFrame(void) {
	UpdateLoopingSound();
	BeginDrawing();
		ScreenController(asteroids);
	EndDrawing();
}
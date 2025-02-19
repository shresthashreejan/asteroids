#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "raymath.h"
#include "raygui.h"

#include "asteroid.h"
#include "constants.h"
#include "debug.h"
#include "player.h"

static Asteroid _asteroids[MAX_ASTEROIDS] = {0};

void UpdateDrawFrame(void);

int main() {
	srand(time(0));
	SetTargetFPS(240);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ASTEROIDS");
	while(!WindowShouldClose()) {
		UpdateDrawFrame();
	}
	CloseWindow();
	return 0;
}

void UpdateDrawFrame(void) {
	FrameUpdateAsteroid(_asteroids);
	BeginDrawing();
		ClearBackground(NEARBLACK);
		PlayerController();
		DebugController(_asteroids);
		for(int i = 0; i < MAX_ASTEROIDS; i++) {
			DrawAsteroid(_asteroids[i]);
		}
	EndDrawing();
}
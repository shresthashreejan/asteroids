#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "raymath.h"
#include "raygui.h"

#include "asteroid.h"
#include "constants.h"
#include "debug.h"
#include "player.h"
#include "projectile.h"

static Asteroid _asteroids[MAX_ASTEROIDS] = {0};

void UpdateDrawFrame(void);

int main() {
	srand(time(0));
	SetTargetFPS(240);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ASTEROIDS");
	LoadSpaceshipTexture();
	while(!WindowShouldClose()) {
		UpdateDrawFrame();
	}
	UnloadResources();
	CloseWindow();
	return 0;
}

void UpdateDrawFrame(void) {
	BeginDrawing();
		ClearBackground(NEARBLACK);
		DrawFPS(SCREEN_WIDTH - 100, 10);
		AsteroidController(_asteroids);
		PlayerController();
		ProjectileController();
		DebugController(_asteroids);
	EndDrawing();
}
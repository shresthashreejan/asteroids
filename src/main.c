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
#include "collision.h"

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
	Rectangle playerRectangle = { playerPosition.x - spaceshipTexture.width / 2, playerPosition.y - spaceshipTexture.height / 2, spaceshipTexture.width, spaceshipTexture.height };
	BeginDrawing();
		ClearBackground(NEARBLACK);
		DrawFPS(SCREEN_WIDTH - 100, 10);
		AsteroidController(_asteroids);
		PlayerController();
		ProjectileController();
		DebugController(_asteroids);
		CollisionController(playerRectangle, _asteroids);
	EndDrawing();
}
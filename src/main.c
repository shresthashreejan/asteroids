#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "raymath.h"
#include "raygui.h"

#include "asteroid.h"
#include "constants.h"
#include "debug.h"

static Asteroid _asteroids[MAX_ASTEROIDS] = {0};
static AsteroidSize _sizes[] = {ASTEROID_SMALL, ASTEROID_MEDIUM, ASTEROID_LARGE};
static float _lastAsteroidCreationTime = -1.0f;

void UpdateDrawFrame(void);
void AddAsteroid(Vector2 position, AsteroidSize size);

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
	float frametime = GetFrameTime();
	float time = GetTime();
	for(int i = 0; i < MAX_ASTEROIDS; i++) {
		UpdateAsteroid(_asteroids + i, frametime, time);
	}

	if(time > _lastAsteroidCreationTime + ASTEROID_DELAY) {
		AddAsteroid(GetNextAsteroidPosition(), _sizes[GetRandomValue(0, 2)]);
		_lastAsteroidCreationTime = time;
	}

	BeginDrawing();
		ClearBackground(NEARBLACK);
		DebugController(_asteroids);
		for(int i = 0; i < MAX_ASTEROIDS; i++) {
			DrawAsteroid(_asteroids[i]);
		}
	EndDrawing();
}

void AddAsteroid(Vector2 position, AsteroidSize size) {
	bool created = false;
	Vector2 velocity = Vector2Subtract(SCREEN_CENTER, position);
	velocity = Vector2Scale(Vector2Normalize(velocity), GetRandomValue(ASTEROID_SPEED_MIN, ASTEROID_SPEED_MAX));

	DrawAngleCone(position, velocity);

	velocity = Vector2Rotate(velocity, (float)GetRandomValue(-ASTEROID_RANDOM_ANGLE, ASTEROID_RANDOM_ANGLE));

	for(int i = 0; i < MAX_ASTEROIDS; i++) {
		if(_asteroids[i].active) {
			continue;
		}

		_asteroids[i] = CreateAsteroid(position, velocity, size);
		created = true;
		break;
	}

	if(!created) {
		TraceLog(LOG_ERROR, "Asteroid creation failed due to no active spot in the array.");
	}
}
#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "raymath.h"

#include "asteroid.h"

const int screenWidth = 1000;
const int screenHeight = 800;
const Vector2 screenSize = {screenWidth, screenHeight};

#define NEARBLACK CLITERAL(Color){15, 15, 15, 255}

#define MAX_ASTEROIDS 64
static Asteroid _asteroids[MAX_ASTEROIDS] = {0};
static AsteroidSize _sizes[] = {ASTEROID_SMALL, ASTEROID_MEDIUM, ASTEROID_LARGE};

void UpdateDrawFrame(void);
void AddAsteroid(Vector2 position, Vector2 velocity, AsteroidSize size);

int main() {
	srand(time(0));
	InitWindow(screenWidth, screenHeight, "Asteroids");

	while(!WindowShouldClose()) {
		UpdateDrawFrame();
	}
	CloseWindow();
	return 0;
}

void UpdateDrawFrame(void) {
	float frametime = GetFrameTime();
	for(int i = 0; i < MAX_ASTEROIDS; i++) {
		UpdateAsteroid(_asteroids + i, frametime);
	}

	if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		AddAsteroid(GetMousePosition(), (Vector2){200, 0}, _sizes[GetRandomValue(0, 3)]);
	}

	BeginDrawing();
		ClearBackground(NEARBLACK);
		for(int i = 0; i < MAX_ASTEROIDS; i++) {
			DrawAsteroid(_asteroids[i]);
		}
	EndDrawing();
}

void AddAsteroid(Vector2 position, Vector2 velocity, AsteroidSize size) {
	bool created = false;
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
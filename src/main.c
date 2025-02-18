#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "raymath.h"
#include "raygui.h"

#include "asteroid.h"

const int screenWidth = 600;
const int screenHeight = 600;
const Vector2 screenCenter = {screenWidth / 2, screenHeight / 2};

#define NEARBLACK CLITERAL(Color){15, 15, 15, 255}

#define MAX_ASTEROIDS 64
#define ASTEROID_RANDOM_ANGLE 20 * DEG2RAD
#define ASTEROID_DELAY 0.75f

static Asteroid _asteroids[MAX_ASTEROIDS] = {0};
static AsteroidSize _sizes[] = {ASTEROID_SMALL, ASTEROID_MEDIUM, ASTEROID_LARGE};
static float _lastAsteroidCreationTime = -1.0f;

// DEBUG
bool _showDebugMenu = false;
bool _showAngleCone = false;
bool _showAsteroidCount = false;
Vector2 line0[2];
Vector2 line1[2];

void UpdateDrawFrame(void);
void AddAsteroid(Vector2 position, AsteroidSize size);
Vector2 GetNextAsteroidPosition(void);

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
	float time = GetTime();
	for(int i = 0; i < MAX_ASTEROIDS; i++) {
		UpdateAsteroid(_asteroids + i, frametime, time);
	}

	if(time > _lastAsteroidCreationTime + ASTEROID_DELAY) {
		AddAsteroid(GetNextAsteroidPosition(), _sizes[GetRandomValue(0, 2)]);
		_lastAsteroidCreationTime = time;
	}

	if(IsKeyPressed(KEY_GRAVE)) {
		_showDebugMenu = !_showDebugMenu;
	}

	BeginDrawing();
		ClearBackground(NEARBLACK);
		for(int i = 0; i < MAX_ASTEROIDS; i++) {
			DrawAsteroid(_asteroids[i]);
		}
		if(_showAngleCone) {
			DrawLineV(line0[0], line0[1], RED);
			DrawLineV(line1[0], line1[1], BLUE);
		}

		if(_showAsteroidCount) {
			int count = 0;
			for(int i = 0; i < MAX_ASTEROIDS; i++) {
				if(_asteroids[i].active) {
					count++;
				}
			}
			DrawRectangle(10, 10, 100, 52, Fade(NEARBLACK, 0.6f));
			DrawText(TextFormat("ASTEROIDS: %d", count), 20, 20, 32, WHITE);
		}

		if(_showDebugMenu) {
			Rectangle r = {10, screenHeight - 40, 140, 20};
			if (GuiButton(r, "Toggle Asteroid Count")) {
				_showAsteroidCount = !_showAsteroidCount;
			}
			r.x += 140 + 10;
			if (GuiButton(r, "Toggle Angle Cone")) {
				_showAngleCone = !_showAngleCone;
			}
		}
	EndDrawing();
}

void AddAsteroid(Vector2 position, AsteroidSize size) {
	bool created = false;
	Vector2 velocity = Vector2Subtract(screenCenter, position);
	velocity = Vector2Scale(Vector2Normalize(velocity), GetRandomValue(ASTEROID_SPEED_MIN, ASTEROID_SPEED_MAX));

	if(_showAngleCone) {
		line0[0] = position;
		line1[0] = position;
		line0[1] = Vector2Add(position, Vector2Rotate(Vector2Scale(velocity, 10), -ASTEROID_RANDOM_ANGLE));
		line1[1] = Vector2Add(position, Vector2Rotate(Vector2Scale(velocity, 10), ASTEROID_RANDOM_ANGLE));
	}

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

Vector2 GetNextAsteroidPosition(void) {
	int padding = 128;
	Vector2 result = {-padding, padding};

	if(GetRandomValue(0, 1)) {
		if(GetRandomValue(0, 1)){
			result.y = screenHeight + padding;
		}
		result.x = GetRandomValue(-padding, screenWidth + padding);
	} else {
		if(GetRandomValue(0, 1)){
			result.x = screenWidth + padding;
		}
		result.y = GetRandomValue(-padding, screenHeight + padding);
	}
	return result;
}
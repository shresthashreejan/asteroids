#include "raylib.h"
#include "raymath.h"

#include "asteroid.h"
#include "constants.h"
#include "debug.h"
#include "score.h"
#include "sounds.h"

static AsteroidSize sizes[] = {ASTEROID_SMALL, ASTEROID_MEDIUM, ASTEROID_LARGE};
static float lastAsteroidCreationTime = -1.0f;
float asteroidDelay = 0.75f;

void UpdateAsteroidDelay(void) {
	int score = GetCurrentScore();
	if(score > 25) {
		asteroidDelay = 0.5f;
	} else if(score > 50) {
		asteroidDelay = 0.25f;
	} else if(score > 75) {
		asteroidDelay = 0.125f;
	} else if(score > 100) {
		asteroidDelay = 0.05f;
	}
}

void FrameUpdateAsteroid(Asteroid *asteroid) {
    float frametime = GetFrameTime();
	float time = GetTime();
	for(int i = 0; i < MAX_ASTEROIDS; i++) {
		UpdateAsteroid(asteroid + i, frametime, time);
	}

	if(time > lastAsteroidCreationTime + asteroidDelay) {
		AddAsteroid(GetNextAsteroidPosition(), sizes[GetRandomValue(0, 2)], asteroid);
		lastAsteroidCreationTime = time;
	}
}

void AddAsteroid(Vector2 position, AsteroidSize size, Asteroid *asteroid) {
	bool created = false;
	Vector2 velocity = Vector2Subtract(SCREEN_CENTER, position);
	velocity = Vector2Scale(Vector2Normalize(velocity), GetRandomValue(ASTEROID_SPEED_MIN, ASTEROID_SPEED_MAX));

	DrawAngleCone(position, velocity);

	velocity = Vector2Rotate(velocity, (float)GetRandomValue(-ASTEROID_RANDOM_ANGLE, ASTEROID_RANDOM_ANGLE));

	for(int i = 0; i < MAX_ASTEROIDS; i++) {
		if(asteroid[i].active) {
			continue;
		}

		asteroid[i] = CreateAsteroid(position, velocity, size);
		created = true;
		break;
	}

	if(!created) {
		TraceLog(LOG_ERROR, "Asteroid creation failed due to no active spot in the array.");
	}
}

Asteroid CreateAsteroid(Vector2 position, Vector2 velocity, AsteroidSize size) {
    return(Asteroid) {
        .active = true,
        .position = position,
        .velocity = velocity,
        .size = size,
        .rotation = 0,
        .rotationSpeed = 0,
        .creationTime = GetTime()
    };
}

void DrawAsteroid(Asteroid asteroid) {
    if(!asteroid.active) {
        return;
    }
	Rectangle rectangle = { asteroid.position.x, asteroid.position.y, 16 * (asteroid.size), 16 * (asteroid.size) };
	DrawRectanglePro(rectangle, (Vector2){rectangle.width / 2, rectangle.height / 2}, asteroid.rotation, BLUE);
}

void UpdateAsteroid(Asteroid *asteroid, float frametime, float time) {
    if(!asteroid->active) {
        return;
    }

    if(time > asteroid->creationTime + ASTEROID_LIFE) {
        asteroid->active = false;
        return;
    }

    asteroid->position = Vector2Add(asteroid->position, Vector2Scale(asteroid->velocity, frametime));
    asteroid->rotation += asteroid->rotationSpeed * frametime;
}

Vector2 GetNextAsteroidPosition(void) {
	int padding = 128;
	Vector2 result = {-padding, padding};

	if(GetRandomValue(0, 1)) {
		if(GetRandomValue(0, 1)){
			result.y = SCREEN_HEIGHT + padding;
		}
		result.x = GetRandomValue(-padding, SCREEN_WIDTH + padding);
	} else {
		if(GetRandomValue(0, 1)){
			result.x = SCREEN_WIDTH + padding;
		}
		result.y = GetRandomValue(-padding, SCREEN_HEIGHT + padding);
	}
	return result;
}

void DestroyAsteroid(Asteroid *asteroid) {
	asteroid->active = false;
	if(asteroid->size == 1) {
		UpdateScore();
	}
	UpdateScore();
	PlayExplosionSound();
}

void AsteroidController(Asteroid *asteroid) {
	UpdateAsteroidDelay();
	FrameUpdateAsteroid(asteroid);
	for(int i = 0; i < MAX_ASTEROIDS; i++) {
		DrawAsteroid(asteroid[i]);
	}
}
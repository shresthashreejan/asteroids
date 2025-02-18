#include "raymath.h"

#include "asteroid.h"
#include "constants.h"
#include "debug.h"

Asteroid CreateAsteroid(Vector2 position, Vector2 velocity, AsteroidSize size) {
    return(Asteroid) {
        .active = true,
        .position = position,
        .velocity = velocity,
        .size = size,
        .rotation = GetRandomValue(0, 360),
        .rotationSpeed = GetRandomValue(ASTEROID_ROT_SPEED_MIN, ASTEROID_ROT_SPEED_MAX),
        .creationTime = GetTime()
    };
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

void DrawAsteroid(Asteroid asteroid) {
    if(!asteroid.active) {
        return;
    }
    DrawPolyLines(asteroid.position, 3, 16 * (int)(asteroid.size), asteroid.rotation, WHITE);
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
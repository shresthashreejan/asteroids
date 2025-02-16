#include "asteroid.h"
#include "raymath.h"

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
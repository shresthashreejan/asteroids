#ifndef ASTEROID_H_
#define ASTEROID_H_

#include "raylib.h"

#define ASTEROID_ROT_SPEED_MIN 5
#define ASTEROID_ROT_SPEED_MAX 240

#define ASTEROID_SPEED_MIN 100
#define ASTEROID_SPEED_MAX 300

#define ASTEROID_LIFE 10.0f

typedef enum AsteroidSize {
    ASTEROID_SMALL = 1,
    ASTEROID_MEDIUM = 2,
    ASTEROID_LARGE = 4,
} AsteroidSize;

typedef struct Asteroid {
    bool active;
    Vector2 position;
    Vector2 velocity;
    AsteroidSize size;
    float rotation;
    float rotationSpeed;
    float creationTime;
} Asteroid;

Asteroid CreateAsteroid(Vector2 position, Vector2 velocity, AsteroidSize size);
void UpdateAsteroid(Asteroid *asteroid, float frametime, float time);
void DrawAsteroid(Asteroid asteroid);

#endif
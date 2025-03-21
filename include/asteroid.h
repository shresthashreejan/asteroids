#ifndef ASTEROID_H_
#define ASTEROID_H_

#include "raylib.h"

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

void UpdateAsteroidDelay(void);
void FrameUpdateAsteroid(Asteroid *asteroid);
void AddAsteroid(Vector2 position, AsteroidSize size, Asteroid *asteroid);
Asteroid CreateAsteroid(Vector2 position, Vector2 velocity, AsteroidSize size);
void DrawAsteroid(Asteroid asteroid);
void UpdateAsteroid(Asteroid *asteroid, float frametime, float time);
Vector2 GetNextAsteroidPosition(void);
void AsteroidController(Asteroid *asteroid);
void DestroyAsteroid(Asteroid *asteroid);

#endif
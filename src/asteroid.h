#ifndef ASTEROID_H_
#define ASTEROID_H_

#include "raylib.h"

typedef enum AsteroidSize
{
    ASTEROID_SMALL = 1,
    ASTEROID_MEDIUM = 2,
    ASTEROID_LARGE = 4,
} AsteroidSize;

typedef struct Asteroid
{
    Vector2 position;
    float rotation;
    float rotationSpeed;
    Vector2 velocity;
} Asteroid;

#endif
#include <stdio.h>

#include "raylib.h"

#include "asteroid.h"
#include "constants.h"

void CheckPlayerCollision(Rectangle playerRectangle, Rectangle asteroidRectangle) {
    bool collisionActive = CheckCollisionRecs(playerRectangle, asteroidRectangle);
    if(collisionActive) {
        printf("Game Over!");
    }
}

void CollisionController(Rectangle playerRectangle, Asteroid *asteroids) {
    for(int i = 0; i < MAX_ASTEROIDS; i++) {
		Rectangle asteroidRect = { asteroids[i].position.x, asteroids[i].position.y, 16 * (asteroids[i].size), 16 * (asteroids[i].size) };
        CheckCollision(playerRectangle, asteroidRect);
	}
}
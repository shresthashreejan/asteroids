#include <stdio.h>

#include "raylib.h"

#include "asteroid.h"
#include "constants.h"
#include "player.h"
#include "screen.h"
#include "texture.h"

void CheckPlayerCollision(Rectangle playerRectangle, Rectangle asteroidRectangle) {
    bool collisionActive = CheckCollisionRecs(playerRectangle, asteroidRectangle);
    if(collisionActive) {
        gameOver = true;
    }
}

bool CheckAsteroidCollision(Rectangle projectileRectangle, Rectangle asteroidRectangle) {
    return CheckCollisionRecs(projectileRectangle, asteroidRectangle);
}

void CollisionController(Asteroid *asteroids, Rectangle projectileRectangle) {
    Rectangle playerRectangle = GetCurrentPlayerBoundingBox();
    for(int i = 0; i < MAX_ASTEROIDS; i++) {
		Rectangle asteroidRect = { asteroids[i].position.x - (8 * asteroids[i].size), asteroids[i].position.y - (8 * asteroids[i].size), 16 * (asteroids[i].size), 16 * (asteroids[i].size) };
        CheckPlayerCollision(playerRectangle, asteroidRect);
        if (projectileRectangle.width > 0 && projectileRectangle.height > 0) {
            if(CheckAsteroidCollision(projectileRectangle, asteroidRect)) {
                DestroyAsteroid(&asteroids[i]);
            }
        }
	}
}
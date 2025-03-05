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

void CheckAsteroidCollision(Rectangle projectileRectangle, Asteroid *asteroids) {
    for(int i = 0; i < MAX_ASTEROIDS; i++) {
		Rectangle asteroidRect = { asteroids[i].position.x, asteroids[i].position.y, 16 * (asteroids[i].size), 16 * (asteroids[i].size) };
        bool collisionActive = CheckCollisionRecs(projectileRectangle, asteroidRect);
        if(collisionActive) {
            DestroyAsteroid(&asteroids[i]);
        }
    }
}

void CollisionController(Asteroid *asteroids) {
    /*
    Current implementation: Constructing player bounding rectangle each frame based on player.h's external variables
    TODO: Implement a better solution
    */
    Texture2D spaceshipTexture = GetSpaceshipTexture();
    Rectangle playerRectangle = { playerPosition.x - (spaceshipTexture.width - 8) / 2, playerPosition.y - (spaceshipTexture.height - 8) / 2, spaceshipTexture.width - 8, spaceshipTexture.height - 8 };
    for(int i = 0; i < MAX_ASTEROIDS; i++) {
		Rectangle asteroidRect = { asteroids[i].position.x - (8 * asteroids[i].size), asteroids[i].position.y - (8 * asteroids[i].size), 16 * (asteroids[i].size), 16 * (asteroids[i].size) };
        // DrawRectangleLines(asteroidRect.x, asteroidRect.y, asteroidRect.width, asteroidRect.height, BLUE);
        CheckPlayerCollision(playerRectangle, asteroidRect);
	}
}
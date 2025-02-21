#include "raylib.h"

#include "constants.h"

static int screenBorderPadding = 15;

Vector2 playerPosition = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2};
Texture2D spaceshipTexture;

void LoadSpaceshipTexture(void) {
	spaceshipTexture = LoadTexture("./assets/images/spaceship.png");
}

void UnloadResources(void) {
	UnloadTexture(spaceshipTexture);
}

void PlayerController(void) {
    if(IsKeyDown(KEY_RIGHT)) {
		if(playerPosition.x <= (SCREEN_WIDTH - screenBorderPadding)) {
			playerPosition.x += 2.0f;
		}
	}
	if(IsKeyDown(KEY_LEFT)) {
		if(playerPosition.x >= 0 + screenBorderPadding) {
			playerPosition.x -= 2.0f;
		}
	}
	if(IsKeyDown(KEY_DOWN)) {
		if(playerPosition.y <= SCREEN_HEIGHT - screenBorderPadding) {
			playerPosition.y += 2.0f;
		}
	}
	if(IsKeyDown(KEY_UP)) {
		if(playerPosition.y >= 0 + screenBorderPadding) {
			playerPosition.y -= 2.0f;
		}
	}
	
	DrawTexture(spaceshipTexture, playerPosition.x - spaceshipTexture.width / 2, playerPosition.y - spaceshipTexture.height / 2, WHITE);
    
}
#include "raylib.h"

#include "constants.h"
#include "texture.h"

Vector2 playerPosition = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2};

Rectangle GetCurrentPlayerBoundingBox(void);

void PlayerController(void) {
	Texture2D spaceshipTexture = GetSpaceshipTexture();
    if(IsKeyDown(KEY_RIGHT)) {
		if(playerPosition.x <= (SCREEN_WIDTH - SCREEN_BORDER_PADDING)) {
			playerPosition.x += 2.0f;
		}
	}
	if(IsKeyDown(KEY_LEFT)) {
		if(playerPosition.x >= 0 + SCREEN_BORDER_PADDING) {
			playerPosition.x -= 2.0f;
		}
	}
	if(IsKeyDown(KEY_DOWN)) {
		if(playerPosition.y <= SCREEN_HEIGHT - SCREEN_BORDER_PADDING) {
			playerPosition.y += 2.0f;
		}
	}
	if(IsKeyDown(KEY_UP)) {
		if(playerPosition.y >= 0 + SCREEN_BORDER_PADDING) {
			playerPosition.y -= 2.0f;
		}
	}	
	DrawTexture(spaceshipTexture, playerPosition.x - spaceshipTexture.width / 2, playerPosition.y - spaceshipTexture.height / 2, WHITE);
}

Vector2 GetCurrentPlayerPosition(void) {
	return playerPosition;
}

void ResetPlayer(void) {
	playerPosition = (Vector2){(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2};
}

Rectangle GetCurrentPlayerBoundingBox(void) {
	Texture2D spaceshipTexture = GetSpaceshipTexture();
	Rectangle rectangle = { playerPosition.x - (spaceshipTexture.width - 8) / 2, playerPosition.y - (spaceshipTexture.height - 8) / 2, spaceshipTexture.width - 8, spaceshipTexture.height - 8 };
	return rectangle;
}
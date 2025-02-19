#include "raylib.h"

#include "constants.h"

Vector2 playerPosition = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2};

void PlayerController(void) {
    if(IsKeyDown(KEY_RIGHT)) playerPosition.x += 2.0f;
	if(IsKeyDown(KEY_LEFT)) playerPosition.x -= 2.0f;
	if(IsKeyDown(KEY_DOWN)) playerPosition.y += 2.0f;
	if(IsKeyDown(KEY_UP)) playerPosition.y -= 2.0f;
    DrawCircleV(playerPosition, 10, WHITE);
}
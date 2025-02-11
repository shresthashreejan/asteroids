#include "raylib.h"

int main(void) {
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Hello raylib");

	SetTargetFPS(60);

	while(!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("Hello raylib", 0, 0, 40, BLACK);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
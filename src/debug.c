#include "raylib.h"
#include "raymath.h"
#include "raygui.h"

#include "asteroid.h"
#include "constants.h"

bool _showDebugMenu = false;
bool _showAngleCone = false;
bool _showAsteroidCount = false;
Vector2 line0[2];
Vector2 line1[2];

void ToggleShowDebugMenu(void) {
    _showDebugMenu = !_showDebugMenu;
}

void ShowDebugMenu(void) {
    if(_showDebugMenu) {
        Rectangle r = {10, SCREEN_HEIGHT - 40, 140, 20};
        if (GuiButton(r, "Toggle Asteroid Count")) {
            _showAsteroidCount = !_showAsteroidCount;
        }
        r.x += 140 + 10;
        if (GuiButton(r, "Toggle Angle Cone")) {
            _showAngleCone = !_showAngleCone;
        }
    }
}

void DrawAngleCone(Vector2 position, Vector2 velocity) {
    if(_showAngleCone) {
		line0[0] = position;
		line1[0] = position;
		line0[1] = Vector2Add(position, Vector2Rotate(Vector2Scale(velocity, 10), -ASTEROID_RANDOM_ANGLE));
		line1[1] = Vector2Add(position, Vector2Rotate(Vector2Scale(velocity, 10), ASTEROID_RANDOM_ANGLE));
	}
}

void ShowAngleCone(void) {
    if(_showAngleCone) {
        DrawLineV(line0[0], line0[1], RED);
        DrawLineV(line1[0], line1[1], BLUE);
    }
}

void ShowAsteroidCount(Asteroid *asteroids) {
    if(_showAsteroidCount) {
        int count = 0;
        for(int i = 0; i < MAX_ASTEROIDS; i++) {
            if(asteroids[i].active) {
                count++;
            }
        }
        DrawRectangle(10, 10, 100, 52, Fade(NEARBLACK, 0.6f));
        DrawText(TextFormat("ASTEROIDS: %d", count), 20, 20, 32, WHITE);
    }
}
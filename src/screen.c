#include "raylib.h"

#include "asteroid.h"
#include "constants.h"
#include "debug.h"
#include "player.h"
#include "projectile.h"
#include "collision.h"

bool paused = false;
bool gameOver = false;

void ScreenController(Asteroid *asteroids) {
    if(IsKeyPressed(KEY_P)) {
        paused = !paused;
    }
    if(!gameOver) {
        if(!paused) {
            ClearBackground(NEARBLACK);
            DrawFPS(SCREEN_WIDTH - 100, 10);
            AsteroidController(asteroids);
            PlayerController();
            ProjectileController(asteroids);
            DebugController(asteroids);
            CollisionController(asteroids);	
        } else {
            DrawText("PAUSED", (SCREEN_WIDTH - MeasureText("PAUSED", 40)) / 2, (SCREEN_HEIGHT - 40) / 2, 40, WHITE);
        }
    } else {
        DrawText("GAME OVER", (SCREEN_WIDTH - MeasureText("GAME OVER", 40)) / 2, (SCREEN_HEIGHT - 40) / 2, 40, WHITE);
    }
}
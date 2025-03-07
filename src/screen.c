#include "raylib.h"

#include "asteroid.h"
#include "constants.h"
#include "debug.h"
#include "player.h"
#include "projectile.h"
#include "collision.h"
#include "score.h"

bool paused = false;
bool gameOver = false;

void Reset(Asteroid *asteroids);

void ScreenController(Asteroid *asteroids) {
    if(!gameOver) {
        if(IsKeyPressed(KEY_P)) {
            paused = !paused;
        }
        if(!paused) {
            ClearBackground(NEARBLACK);
            DrawFPS(SCREEN_WIDTH - 100, 10);
            AsteroidController(asteroids);
            PlayerController();
            ProjectileController(asteroids);
            ScoreController();
            DebugController(asteroids);
        } else {
            DrawRectangle(0, (SCREEN_HEIGHT - 100) / 2, SCREEN_WIDTH, 100, WHITE);
            DrawText("PAUSED", (SCREEN_WIDTH - MeasureText("PAUSED", 40)) / 2, (SCREEN_HEIGHT - 40) / 2, 40, NEARBLACK);
        }
    } else {
        DrawRectangle(0, (SCREEN_HEIGHT - 100) / 2, SCREEN_WIDTH, 100, WHITE);
        DrawText("GAME OVER", (SCREEN_WIDTH - MeasureText("GAME OVER", 40)) / 2, (SCREEN_HEIGHT - 80) / 2, 40, NEARBLACK);
        DrawText("PRESS R TO RESTART", (SCREEN_WIDTH - MeasureText("PRESS R TO RESTART", 40)) / 2, (SCREEN_HEIGHT) / 2, 40, NEARBLACK);
        if(IsKeyPressed(KEY_R)) {
            Reset(asteroids);
        }
    }
}

void Reset(Asteroid *asteroids) {
    ClearBackground(NEARBLACK);
    for(int i = 0; i < MAX_ASTEROIDS; i++) {
        asteroids[i].active = false;
    }
    ResetPlayer();
    ResetScore();
    gameOver = false;
}
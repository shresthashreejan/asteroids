#include "raylib.h"
#include "raygui.h"

int score = 0;

void UpdateScore(void) {
    score++;
}

void ResetScore(void) {
    score = 0;
}

void ScoreController(void) {
    DrawText(TextFormat("SCORE: %d", score), 20, 20, 32, WHITE);
}
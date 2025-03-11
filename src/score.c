#include <stdio.h>

#include "raylib.h"
#include "raygui.h"
#include "constants.h"

int score = 0;
int highScore = 0;

int LoadHighScore() {
    FILE *file = fopen(SCORE_FILE, "r");
    if(file != NULL) {
        fscanf(file, "%d", &highScore);
        fclose(file);
    }
    return highScore;
}

void SaveHighScore(int newScore) {
    FILE *file = fopen(SCORE_FILE, "w");
    if(file != NULL) {
        fprintf(file, "%d", newScore);
        fclose(file);
    }
}

void UpdateScore(void) {
    score++;
    if(score > highScore) SaveHighScore(score);
}

void ResetScore(void) {
    score = 0;
}

void ScoreController(void) {
    DrawText(TextFormat("SCORE: %d", score), 20, 20, 32, WHITE);
    DrawText(TextFormat("HIGH SCORE: %d", LoadHighScore()), 20, 60, 16, WHITE);
}

int GetCurrentScore(void) {
    return score;
}
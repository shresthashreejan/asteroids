#include "raylib.h"

Texture2D spaceshipTexture;

void LoadSpaceshipTexture(void) {
    spaceshipTexture = LoadTexture("./assets/images/spaceship.png");
}

void UnloadTextures(void) {
	UnloadTexture(spaceshipTexture);
}

void LoadAllTextures(void) {
    LoadSpaceshipTexture();
}

Texture2D GetSpaceshipTexture(void) {
    return spaceshipTexture;
}
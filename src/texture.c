#include "raylib.h"

Texture2D spaceshipTexture;

void LoadSpaceshipTexture(void) {
    spaceshipTexture = LoadTexture("./assets/images/spaceship.png");
}

void LoadAllTextures(void) {
    LoadSpaceshipTexture();
}

void UnloadTextures(void) {
	UnloadTexture(spaceshipTexture);
}

Texture2D GetSpaceshipTexture(void) {
    return spaceshipTexture;
}
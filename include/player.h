#ifndef PLAYER_H_
#define PLAYER_H_

extern Vector2 playerPosition;
extern Texture2D spaceshipTexture;

void PlayerController();
void LoadSpaceshipTexture();
void UnloadResources();

#endif
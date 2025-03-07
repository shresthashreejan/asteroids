#ifndef DEBUG_H_
#define DEBUG_H_

void DebugController(Asteroid *asteroids);
void ShowDebugMenu();
void DrawAngleCone(Vector2 position, Vector2 velocity);
void ShowAngleCone();
void ShowAsteroidCount(Asteroid *asteroids);
void ShowPlayerBoundingBox();

#endif
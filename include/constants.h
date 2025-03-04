#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define GAME_TITLE "ASTEROIDS"
#define ASTEROID_ROT_SPEED_MIN 5
#define ASTEROID_ROT_SPEED_MAX 240
#define ASTEROID_SPEED_MIN 100
#define ASTEROID_SPEED_MAX 300
#define ASTEROID_LIFE 10.0f
#define NEARBLACK CLITERAL(Color){15, 15, 15, 255}
#define MAX_ASTEROIDS 64
#define ASTEROID_RANDOM_ANGLE 20 * DEG2RAD
#define ASTEROID_DELAY 0.75f
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define SCREEN_CENTER (Vector2){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2}
#define MAX_PROJECTILES 64
#define SCREEN_BORDER_PADDING 15

#endif
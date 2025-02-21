#include "raylib.h"
#include "raymath.h"

#include "constants.h"
#include "player.h"

typedef struct Projectile {
    Vector2 position;
    Vector2 velocity;
    bool active;
} Projectile;

Projectile projectile;

void DrawProjectile(void) {
    if(projectile.active) {
        DrawRectangle(projectile.position.x - 2, projectile.position.y - 10, 4, 20, RED);
    }
}

void FireProjectile(void) {
    projectile.position = playerPosition;
    projectile.velocity = (Vector2){0, -3};
    projectile.active = true;
}

void UpdateProjectile(void) {
    if(projectile.active) {
        projectile.position.x += projectile.velocity.x;
        projectile.position.y += projectile.velocity.y;
        DrawProjectile();
    }
    
    if(projectile.position.x < 0 || projectile.position.x >= SCREEN_WIDTH || projectile.position.y < 0 || projectile.position.y >= SCREEN_HEIGHT) {
        projectile.active = false;
    }
}

void ProjectileController() {
    if (IsKeyPressed(KEY_SPACE)) {
        FireProjectile();
    }
    UpdateProjectile();
}
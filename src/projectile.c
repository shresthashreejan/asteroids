#include "raylib.h"
#include "raymath.h"

#include "constants.h"
#include "player.h"
#include "asteroid.h"

typedef struct Projectile {
    Vector2 position;
    Vector2 velocity;
    bool active;
} Projectile;

static Projectile projectiles[MAX_PROJECTILES] = {0};

void DrawProjectile(Projectile projectile) {
    if(projectile.active) {
        DrawRectangle(projectile.position.x - 2, projectile.position.y - 10, 4, 20, RED);
    }
}

void FireProjectile(void) {
    Projectile projectile;
    projectile.position = playerPosition;
    projectile.velocity = (Vector2){0, -3};
    projectile.active = true;
    for(int i = 0; i <= MAX_PROJECTILES; i++) {
        if(projectiles[i].active) {
            continue;
        }
        projectiles[i] = projectile;
        break;
    }
}

void UpdateProjectile(Asteroid *asteroids) {
    for(int i = 0; i <= MAX_PROJECTILES; i++) {
        if(projectiles[i].active) {
            projectiles[i].position.x += projectiles[i].velocity.x;
            projectiles[i].position.y += projectiles[i].velocity.y;
            DrawProjectile(projectiles[i]);
            Rectangle projectileRectangle = { projectiles[i].position.x - 2, projectiles[i].position.y - 10, 4, 20 };
            CheckAsteroidCollision(projectileRectangle, asteroids);
        }
        
        if(projectiles[i].position.x < 0 || projectiles[i].position.x >= SCREEN_WIDTH || projectiles[i].position.y < 0 || projectiles[i].position.y >= SCREEN_HEIGHT) {
            projectiles[i].active = false;
        }
    }
}

void ProjectileController(Asteroid *asteroids) {
    if(IsKeyPressed(KEY_F)) {
        FireProjectile();
    }
    UpdateProjectile(asteroids);
}
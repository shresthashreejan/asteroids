#include "raylib.h"
#include "raymath.h"

#include "constants.h"
#include "player.h"

typedef struct Projectile {
    Vector2 position;
    Vector2 velocity;
    bool active;
} Projectile;

static Projectile _projectiles[MAX_PROJECTILES] = {0};

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
        if(_projectiles[i].active) {
            continue;
        }
        _projectiles[i] = projectile;
        break;
    }
}

void UpdateProjectile(void) {
    for(int i = 0; i <= MAX_PROJECTILES; i++) {
        if(_projectiles[i].active) {
            _projectiles[i].position.x += _projectiles[i].velocity.x;
            _projectiles[i].position.y += _projectiles[i].velocity.y;
            DrawProjectile(_projectiles[i]);
        }
        
        if(_projectiles[i].position.x < 0 || _projectiles[i].position.x >= SCREEN_WIDTH || _projectiles[i].position.y < 0 || _projectiles[i].position.y >= SCREEN_HEIGHT) {
            _projectiles[i].active = false;
        }
    }
}

void ProjectileController() {
    if(IsKeyPressed(KEY_F)) {
        FireProjectile();
    }
    UpdateProjectile();
}
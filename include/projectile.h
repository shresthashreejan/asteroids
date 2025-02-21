#ifndef PROJECTILE_H_
#define PROJECTILE_H_

typedef struct Projectile {
    Vector2 position;
    Vector2 velocity;
    bool active;
} Projectile;

void FireProjectile();
void UpdateProjectile();
void DrawProjectile(Projectile projectile);
void ProjectileController();

#endif
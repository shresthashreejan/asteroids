#ifndef PROJECTILE_H_
#define PROJECTILE_H_

typedef struct Projectile {
    Vector2 position;
    Vector2 velocity;
    bool active;
} Projectile;

void FireProjectile();
void UpdateProjectile(Asteroid *asteroids);
void DrawProjectile(Projectile projectile);
void ProjectileController(Asteroid *asteroids);

#endif
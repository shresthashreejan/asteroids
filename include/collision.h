#ifndef COLLISION_H_
#define COLLISION_H_

void CheckPlayerCollision(Rectangle playerRectangle, Rectangle asteroidRectangle);
void CheckAsteroidCollision(Rectangle projectileRectangle, Asteroid *asteroids);
void CollisionController(Asteroid *asteroids);

#endif
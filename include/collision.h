#ifndef COLLISION_H_
#define COLLISION_H_

void CheckPlayerCollision(Rectangle playerRectangle, Rectangle asteroidRectangle);
bool CheckAsteroidCollision(Rectangle projectileRectangle, Rectangle asteroidRectangle);
void CollisionController(Asteroid *asteroids, Rectangle projectileRectangle);

#endif
#ifndef COLLISION_H_
#define COLLISION_H_

void CheckPlayerCollision(Rectangle playerRectangle, Rectangle asteroidRectangle);
void CollisionController(Rectangle playerRectangle, Asteroid *asteroids);

#endif
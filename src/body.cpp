#include <destructure/body.hpp>

#include <raylib.h>

void Body::update() noexcept
{
  const Vector2 velocity = this->velocity();
  const float dt = GetFrameTime();

  last_position = position;
  position += velocity + acceleration * dt * dt;

  acceleration = Vector2Zero();
}

void Body::draw() noexcept {}
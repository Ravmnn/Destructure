#include <destructure/body.hpp>

#include <raylib.h>

void Body::update() noexcept
{
  const Vector2 velocity = this->velocity();
  const float delta_time = GetFrameTime();

  last_position = position;
  position += velocity + acceleration * delta_time * delta_time;

  acceleration = Vector2Zero();
}

void Body::draw() noexcept
{
}

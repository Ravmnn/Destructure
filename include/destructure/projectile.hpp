#pragma once

#include <destructure/circle_body.hpp>

class Projectile : public CircleBody
{
public:
  float base_damage;

  Projectile(const Vector2& position, float radius, float base_damage,
             Color color = WHITE)
      : CircleBody(position, radius, color)
  {
  }

  float calculate_current_damage() const noexcept { return base_damage * momentum(); }
};
#pragma once

#include <destructure/body.hpp>

class CircleBody : public Body
{
public:
  Color color;
  float radius;

  CircleBody(const Vector2& position, float radius, Color color = WHITE) noexcept
      : Body(position), radius(radius), color(color)
  {
  }

  void draw() noexcept override;
};
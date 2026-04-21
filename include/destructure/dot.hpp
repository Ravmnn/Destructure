#pragma once

#include <destructure/body.hpp>

class Dot : public Body
{
public:
  static constexpr float RADIUS = 3;
  Color color;

  Dot(const Vector2& position, Color color = WHITE) noexcept : Body(position), color(color) {}

  void update() noexcept override;

  void draw() noexcept override;
};

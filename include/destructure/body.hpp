#pragma once

#include <raylib.h>
#include <raymath.h>

#include <destructure/drawable.hpp>
#include <destructure/updateable.hpp>

class Body : public Updateable, public Drawable
{
public:
  Vector2 last_position;
  Vector2 position;
  Vector2 acceleration = {};

  float mass = 0;

  explicit Body(const Vector2& position) noexcept
      : last_position(position), position(position)
  {
  }

  virtual ~Body() = default;

  void update() noexcept override;
  void draw() noexcept override;

  Vector2 velocity() const noexcept { return position - last_position; }
  float momentum() const noexcept { return Vector2Length(velocity()) * mass; }

  void apply_force(Vector2 force) noexcept { acceleration += force; }
};

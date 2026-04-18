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
  Vector2 acceleration;

  float mass;

  void update() noexcept override;
  void draw() noexcept override;

  Vector2 velocity() const noexcept { return last_position - position; }
  float momentum() const noexcept { return Vector2Length(velocity()) * mass; }

  void apply_force(Vector2 force) noexcept { acceleration += force; }
};
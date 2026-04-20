#pragma once

#include <raylib.h>
#include <raymath.h>

#include <destructure/updateable.hpp>
#include <destructure/drawable.hpp>




class Body : public Updateable, public Drawable
{
public:
  Vector2 last_position;
  Vector2 position;
  Vector2 acceleration;

  float mass;




  void update() noexcept override;
  void draw() noexcept override;


  Vector2 calculate_velocity() const noexcept { return Vector2Subtract(position, last_position); }
  float calculate_momentum() const noexcept { return Vector2Length(calculate_velocity()) * mass; }


  void apply_force(Vector2 force) noexcept { acceleration = Vector2Add(acceleration, force); }
};

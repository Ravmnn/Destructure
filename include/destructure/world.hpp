#pragma once

#include <memory>
#include <vector>

#include <raylib.h>

#include <destructure/drawable.hpp>
#include <destructure/updateable.hpp>

class Body;

class World : public Updateable, public Drawable
{
private:
  std::vector<std::unique_ptr<Body>> _bodies;

public:
  float drag;
  Vector2 gravity;

  void update() noexcept override;
  void draw() noexcept override;

  Body *add_body(Body &body);

private:
  void apply_world_forces_to_body(Body &body);
};
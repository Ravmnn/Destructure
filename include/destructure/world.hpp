#pragma once

#include <memory>
#include <vector>

#include <raylib.h>

#include <destructure/drawable.hpp>
#include <destructure/updateable.hpp>

class Body;
class Slingshot;

class World : public Updateable, public Drawable
{
public:
  std::vector<std::unique_ptr<Body>> bodies;
  std::unique_ptr<Slingshot> slingshot;

  Vector2 gravity = {};
  float drag = 0;

  virtual ~World() = default;

  void update() noexcept override;
  void draw() noexcept override;

private:
  void apply_world_forces_to_body(Body& body);
};
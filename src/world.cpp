#include <destructure/world.hpp>

#include <destructure/body.hpp>

void World::update() noexcept
{
  for (auto &body : _bodies)
  {
    apply_world_forces_to_body(*body);
    body->update();
  }
}

void World::apply_world_forces_to_body(Body &body)
{
  float final_drag = drag / 100.0f;
  Vector2 final_gravity = gravity / 100.0f;

  Vector2 acceleration_percentage = body.acceleration * final_drag;
  body.acceleration -= acceleration_percentage;
  body.acceleration += final_gravity;
}

void World::draw() noexcept
{
  for (auto &body : _bodies)
    body->draw();
}

Body *World::add_body(Body &body)
{
  _bodies.push_back(std::make_unique<Body>(body));

  return _bodies.back().get();
}
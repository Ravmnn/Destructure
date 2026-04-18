#include <destructure/world.hpp>

#include <destructure/body.hpp>
#include <destructure/slingshot.hpp>

void World::update() noexcept
{
  for (auto& body : bodies)
  {
    apply_world_forces_to_body(*body);
    body->update();
  }

  slingshot->update();
}

void World::apply_world_forces_to_body(Body& body)
{
  float final_drag = drag / 100.0f;
  Vector2 final_gravity = gravity / 100.0f;

  Vector2 velocity_percentage = body.velocity() * final_drag;
  body.acceleration -= velocity_percentage;
  body.acceleration += final_gravity;
}

void World::draw() noexcept
{
  for (auto& body : bodies)
    body->draw();

  slingshot->draw();
}
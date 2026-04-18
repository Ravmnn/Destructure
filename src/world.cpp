#include <destructure/world.hpp>

#include <destructure/body.hpp>




void World::update() noexcept
{
  for (auto& body : _bodies)
  {
    apply_world_forces_to_body(*body);
    body->update();
  }
}


void World::apply_world_forces_to_body(Body& body)
{
  Vector2 acceleration_percentage = Vector2Multiply(body.acceleration, Vector2 { drag, drag });
  body.acceleration = Vector2Subtract(body.acceleration, acceleration_percentage);
  body.acceleration = Vector2Add(body.acceleration, gravity);
}




void World::draw() noexcept
{
  for (auto& body : _bodies)
    body->draw();
}




Body* World::add_body(Body& body)
{
  _bodies.push_back(std::make_unique<Body>(body));

  return _bodies.back().get();
}
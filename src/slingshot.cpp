#include <destructure/slingshot.hpp>
#include <destructure/dot.hpp>
#include <destructure/world.hpp>

void Slingshot::update() noexcept
{
  placeholder->position = position;

  update_aim_state();

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    throw_projectile();
}

void Slingshot::update_aim_state() noexcept
{
  Vector2 mouse_position = GetMousePosition();
  Vector2 direction = Vector2Normalize(mouse_position - position);
  float distance = Vector2Distance(position, mouse_position);
  float force = strength * distance / 100.0f;

  current_direction = direction;
  current_force = force;
}

Dot* Slingshot::throw_projectile() noexcept
{
  auto projectile = projectile_factory->create(position);
  projectile->apply_force(force_vector());

  world.bodies.push_back(std::move(projectile));
  Body* const body = world.bodies.back().get();

  return dynamic_cast<Dot*>(body);
}

void Slingshot::draw() noexcept
{
  placeholder->draw();
}

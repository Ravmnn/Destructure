#pragma once

#include <memory>

#include <destructure/projectile.hpp>
#include <destructure/projectile_factory.hpp>

class World;

class Slingshot : public Updateable, public Drawable
{
private:
  std::unique_ptr<Projectile> _placeholder;

  Vector2 _current_direction = {};
  float _current_force = 0;

public:
  World& world;
  Vector2 position;
  float strength;

  std::unique_ptr<ProjectileFactory> projectile_factory;

  Slingshot(World& world, const Vector2& position, const ProjectileFactory& factory, float strength) :
      world(world), position(position), strength(strength)
  {
    projectile_factory = std::make_unique<ProjectileFactory>(factory);
    _placeholder = projectile_factory->create(position);
  }

  virtual ~Slingshot() = default;

  void update() noexcept override;
  void draw() noexcept override;

  Projectile* throw_projectile() noexcept;

private:
  void update_aim_state() noexcept;

  Vector2 force_vector() const noexcept { return _current_direction * _current_force; }
};
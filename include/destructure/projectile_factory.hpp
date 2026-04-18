#pragma once

#include <memory>

#include <destructure/projectile.hpp>

class ProjectileFactory
{
public:
  float default_radius;
  Color default_color;
  float default_mass;
  float default_damage;

  ProjectileFactory(float default_radius, Color default_color, float default_mass, float default_damage) :
      default_radius(default_radius), default_color(default_color), default_mass(default_mass),
      default_damage(default_damage)
  {
  }

  virtual ~ProjectileFactory() = default;

  virtual std::unique_ptr<Projectile> create(const Vector2& position) const noexcept
  {
    return std::make_unique<Projectile>(position, default_radius, default_damage, default_color);
  }
};
#include <destructure/circle_body.hpp>

void CircleBody::draw() noexcept
{
  DrawCircleV(position, radius, color);
}
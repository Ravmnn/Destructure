#pragma once

class Destroyable
{
public:
  float total_durability;
  float min_durability;
  float durability;

  bool is_destroied() noexcept { return (durability <= 0); }
};

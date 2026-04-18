#pragma once

class Updateable
{
public:
  virtual ~Updateable() = default;

  virtual void update() = 0;
};
#include <iostream>

#include <raylib.h>

#include <destructure/world.hpp>
#include <destructure/slingshot.hpp>

static void initialize_window();

int main()
{
  initialize_window();

  World world;
  world.drag = 5.0f;

  ProjectileFactory factory(20, WHITE, 10, 10);
  world.slingshot = std::make_unique<Slingshot>(world, Vector2 { 200, 200 }, factory, 1000);

  while (!WindowShouldClose())
  {
    world.update();

    BeginDrawing();
    ClearBackground(BLACK);

    world.draw();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}

static void initialize_window()
{
  SetConfigFlags(FLAG_FULLSCREEN_MODE);
  int monitor = GetCurrentMonitor();
  InitWindow(GetMonitorWidth(monitor), GetMonitorHeight(monitor),
             "Destructure");

  SetTargetFPS(60);
}
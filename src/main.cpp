#include <iostream>

#include <raylib.h>

#include <destructure/world.hpp>




int main()
{
  SetConfigFlags(FLAG_FULLSCREEN_MODE);
  int monitor = GetCurrentMonitor();
  InitWindow(GetMonitorWidth(monitor), GetMonitorHeight(monitor), "Destructure");

  SetTargetFPS(60);


  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawCircleV(GetMousePosition(), 10.0f, WHITE);

    EndDrawing();
  }


  CloseWindow();

  return 0;
}
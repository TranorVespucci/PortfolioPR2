#include <cstdlib>

#include "raylib.h"

#include "config.h"

#include "TileMap/Map.h"

#include <memory>

#include "Inventory/Inventory.h"

int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here
    // ...
    // ...
    std::unique_ptr<Map> tilemap = std::make_unique<Map>();

    // Camera settings
    //--------------------------------------------------------------------------------------------
    Camera2D camera = { 0 };
    camera.target   = Vector2 { Game::ScreenWidth/ 2.0f - 280, Game::ScreenHeight / 2.0f - 170};
    camera.offset   = Vector2 { Game::ScreenWidth / 2.0f, Game::ScreenHeight / 2.0f };
    camera.zoom     = 2.0f;
    //---------------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // ...
        // ...

        //NOW IF THAT ISN'T A CLEAN AND UNTOUCHED MAIN.CPP
        // AT LEAST I KEEP MY PROMISE TO NOT MAKE IT LOOK LIKE PROJECT 2
        BeginDrawing();

        BeginMode2D(camera);

            tilemap->DrawMap();
            ClearBackground(DARKGREEN);

        EndDrawing();
    } // Main game loop end

    // De-initialization here
    // ...
    // ...

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}


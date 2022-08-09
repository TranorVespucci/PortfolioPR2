#include <cstdlib>

#include "raylib.h"

#include "config.h"

//#include "Player/PC.h"

#include "TileMap/Map.h"

#include <memory>

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
    std::unique_ptr<Char> pc = std::make_unique<PC>();

    // Camera settings
    //--------------------------------------------------------------------------------------------
    //Camera2D camera = { 0 };
    //camera.target   = Vector2 { static_cast<float>(pc->GetXPosition()), static_cast<float>(pc->GetYPosition())};
   //camera.offset   = Vector2 { Game::ScreenWidth / 2.0f, Game::ScreenHeight / 2.0f };
    //camera.zoom     = 2.0f;
    //---------------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // ...
        // ...

        BeginDrawing();

        //beginMode2D(camera);

            tilemap->DrawMap();
            ClearBackground(WHITE);

        EndDrawing();
    } // Main game loop end

    // De-initialization here
    // ...
    // ...

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}


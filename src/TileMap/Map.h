//
// Created by goerk on 08.08.2022.
//
#include "raylib.h"
#include <vector>
#include "../Player/PC.h"
#include "../Item/Water.h"
#include <memory>

class Map {
public:

    //Constructor
    Map();
    std::unique_ptr<Char> pc = std::make_unique<PC>();
    std::shared_ptr<Water> water = std::make_shared<Water>();
    std::vector<std::shared_ptr<Water>> i_water;
    //Inside the Load Map is what is drawn in it
    void LoadMap(int arr[20][25]);
    //Calling this Method to draw the Map
    void DrawMap();
    Rectangle s_rec = {};
    Vector2 s_start = {};


private:
    //x and y position for the Arrays
    int x{}, y{};

    //First one is how many Arrays (20 Arrays) we can create with 25 Elements stored inside of it.
    int map[20][25]{};
    //The Texture of the Tile Map
    Texture2D T_map = LoadTexture("assets/graphics/tiles_packed.png");

    //T_Framerec is the Path One
    Rectangle T_frameRec = {0, 32, 16, 16};
    int currentFrame = 1;
    //T_Start Rec for the start item
    Rectangle T_StartRec = {0, 32, 32, 16};
    int currentStartFrame = 5;

    Rectangle border1 = {0, 320, 400, 16};

};

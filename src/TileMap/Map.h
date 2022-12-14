//
// Created by goerk on 08.08.2022.
//
#pragma once
#include "raylib.h"
#include <vector>
#include "../Player/PC.h"
#include "../Item/Water.h"
#include "../Item/Chilli.h"
#include "../Item/Milk.h"
#include "../Item/Spamton.h"
#include "../Inventory/Inventory.h"
#include "../Enums/Enums.h"
#include <memory>
#include <iostream>

class Map {
public:

    //Constructor
    Map();
    //And here are the shared pointers and the Unique ones (BADUM TCH!!!)
    std::unique_ptr<Char> pc = std::make_unique<PC>();
    std::shared_ptr<Water> water = std::make_shared<Water>();
    std::shared_ptr<Chilli> chilli = std::make_shared<Chilli>();
    std::shared_ptr<Milk> milk = std::make_shared<Milk>();
    std::shared_ptr<Pudding> pudding = std::make_shared<Pudding>();
    std::shared_ptr<Spamton> spamton = std::make_shared<Spamton>();
    //Inside the Load Map is what is drawn in it
    void LoadMap(int arr[20][25]);
    //Calling this Method to draw the Map
    void DrawMap();
    void WeightOverload();
    void Collision();

private:
    Inventory<ItemBase> inventory;
    //x and y position for the Arrays
    int x{}, y{};

    //Collision Bools
    bool wallCollision = false;
    bool wallCollision2 = false;
    bool wallCollision3 = false;
    bool wallCollision4 = false;
    bool StoneCollision = false;
    bool GoalCollision = false;
    bool WaterDraw = true;
    bool ChilliDraw = true;
    bool MilkDraw = true;
    bool PuddingDraw = true;
    bool SpamtonDraw = true;

    //First one is how many Arrays (20 Arrays) we can create with 25 Elements stored inside of it.
    int map[20][25]{};
    //The Texture of the Tile Map
    Texture2D T_map = LoadTexture("assets/graphics/tiles_packed.png");
    Texture2D Spawn = LoadTexture("assets/graphics/stone_start.png");
    Texture2D Tree = LoadTexture("assets/graphics/Tree.png");
    Texture2D Stone = LoadTexture("assets/graphics/Stone.png");
    Texture2D Goal = LoadTexture("assets/graphics/Finish.png");


    //Goal
    Rectangle goalrec = {};
    //T_Framerec is the Path One
    Rectangle T_frameRec = {0, 32, 16, 16};
    int currentFrame = 1;
    //T_Start Rec for the start item
    Rectangle T_StartRec = {0, 32, 16, 16};
    int currentStartFrame = 1;

    //Stone
    std::vector<Rectangle> stonerecc = {};

    //The Border Rectangles, The Player cannot go outside of the Map.
    Rectangle border1 = {0, 320, 400, 16};
    Rectangle border2 = {0, 0, 16, 320};
    Rectangle border3 = {-16, -16, 410, 16};
    Rectangle border4 = {384, 0, 16, 320};

};

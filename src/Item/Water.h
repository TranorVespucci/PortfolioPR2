//
// Created by user on 10.08.2022.
//
#pragma once
#include "ItemBase.h"
#include <vector>

class Water : public ItemBase {
public:

    Water();
    void Draw() override;
    Rectangle getRec() override;
    Rectangle deleteRec() override;
    ~Water();



private:
    Vector2 waterposition = {};
    Rectangle waterrec = {};
    Texture2D water = LoadTexture("assets/graphics/spr_Water.png");
    Rectangle framerec = { 0.0f, 0.0f, (float)water.width, (float)water.height};
    int currentFrame = 0;
};


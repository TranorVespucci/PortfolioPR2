//
// Created by user on 26.09.2022.
//

#pragma once
#include "ItemBase.h"
#include <vector>


class Pudding : public ItemBase{
public:
    Pudding();
    void Draw() override;
    Rectangle getRec() override;
    Rectangle deleteRec() override;
    ~Pudding();
private:
    Vector2 puddingposition = {};
    Rectangle puddingrec = {};
    Texture2D pudding = LoadTexture("assets/graphics/spr_Pudding.png");

    Rectangle framerec = {0.0f, 0.0f, (float)pudding.width, (float)pudding.height};
    int currentFrame = 0;
};




//
// Created by user on 26.09.2022.
//

#pragma once
#include "ItemBase.h"
#include <vector>

class Milk : public ItemBase {
public:
    Milk();
    void Draw() override;
    Rectangle getRec() override;
    Rectangle deleteRec() override;
    ~Milk();

private:
    Vector2 milkposition = {};
    Rectangle milkrec = {};
    Texture2D milk = LoadTexture("assets/graphics/spr_milk.png");

    Rectangle framerec = {0.0f, 0.0f, (float)milk.width, (float)milk.height};
    int currentFrame = 0;
};



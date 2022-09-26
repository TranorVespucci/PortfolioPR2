//
// Created by user on 26.09.2022.
//
#pragma once
#ifndef RAYLIBSTARTER_CHILLI_H
#define RAYLIBSTARTER_CHILLI_H
#include "ItemBase.h"
#include <vector>


class Chilli : public ItemBase {
public:

    Chilli();
    void Draw() override;
    Rectangle getRec() override;
    Rectangle deleteRec() override;
    ~Chilli();

private:
    Vector2 chilliposition = {};
    Rectangle chillirec = {};
    Texture2D chilli = LoadTexture("assets/graphics/spr_Chilli.png");

    Rectangle framerec = { 0.0f, 0.0f, (float)chilli.width, (float)chilli.height};
    int currentFrame = 0;
};


#endif //RAYLIBSTARTER_CHILLI_H

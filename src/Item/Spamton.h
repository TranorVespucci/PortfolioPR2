//
// Created by user on 26.09.2022.
//
#pragma once
#include "ItemBase.h"
#include <vector>
//This is a Character from the Game Deltarune created by Toby Fox
//I just drew that Character in 16x16 format, yet the Character drawn in the Deltarune Game
//Is made by Toby Fox and Temmy Chang

class Spamton : public ItemBase{
public:
    Spamton();
    void Draw() override;
    Rectangle getRec() override;
    Rectangle deleteRec() override;
    ~Spamton();
private:
    Vector2 spamtonposition = {};
    Rectangle spamtonrec = {};
    Texture2D spamton = LoadTexture("assets/graphics/spr_Spamton.png");

    Rectangle framerec = { 0.0f, 0.0f, (float)spamton.width, (float)spamton.height};
    int currentFrame = 0;
};




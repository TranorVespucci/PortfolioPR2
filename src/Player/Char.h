//
// Created by goerk on 09.08.2022.
//
#pragma once
#include <raylib.h>
#include "../Inventory/Inventory.h"

class Char{
public:

    Char(int HP, int STR, int MaxWeight);
    virtual void Draw();
    virtual void Update();
    bool Active = true;

    virtual Texture2D GetTexture();
    virtual Vector2 GetPositionVec();
    virtual void SetPositionVec(Vector2 position);
    virtual Rectangle GetPlayerRectangle();
    virtual float GetSpeed();
    virtual float Collision();
    int getMaxWeight();
    ~Char();

protected:
    Vector2 Position = {};
    int pc_maxWeight;
    int pc_HP;
    int pc_Str;

};




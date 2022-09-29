//
// Created by goerk on 09.08.2022.
//
#pragma once
#include "Char.h"
#include <string>
#include "../Inventory/Inventory.h"

class PC: public Char{
public:
    PC();
    void Draw() override;
    void Update() override;
    Texture2D GetTexture() override;
    Vector2 GetPositionVec() override;
    void SetPositionVec(Vector2 position) override;
    Rectangle GetPlayerRectangle() override;
    virtual float GetSpeed();
    float Collision() override;

    ~PC();

    enum class Direction {UP, DOWN, LEFT, RIGHT};

    Direction direction = Direction::UP;


private:
    Inventory<ItemBase> inventory;
    const char* pc_name;
    float speed = 1;

    Vector2 playerposition = {};
    Texture2D pc = LoadTexture("assets/graphics/PC.png");

    Rectangle framerec = { 0.0f, 0.0f, (float)pc.width, (float)pc.height};
    int currentFrame = 0;
    Rectangle playerrec = {};
};




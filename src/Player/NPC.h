//
// Created by user on 28.09.2022.
//
#pragma once
#include "Char.h"
#include <string>

class NPC : public Char{
public:
    NPC();
    void Draw() override;
    void Update() override;
    Texture2D GetTexture() override;
    Vector2 GetPositionVec() override;
    void SetPositionVec(Vector2 position) override;
    Rectangle GetPlayerRectangle() override;
    virtual float GetSpeed();
    float Collision() override;
    ~NPC();

private:
    const char* npc_name;

};


//
// Created by goerk on 09.08.2022.
//

#include "PC.h"
#include <iostream>

PC::PC() = default;

PC::~PC() = default;

void PC::Draw() {
    playerrec = {playerposition.x, playerposition.y, 16, 16 };
    DrawTextureRec(pc,playerrec,playerposition, WHITE);
    //DrawRectangleRec(playerrec, RED);
}


void PC::Update() {
    if (IsKeyPressed(KEY_W))
    {
        playerposition.y -= speed;
    }

    if (IsKeyPressed(KEY_S))
    {
        playerposition.y += speed;
    }

    if (IsKeyPressed(KEY_A))
    {
        playerposition.x -=  speed;
    }

    if  (IsKeyPressed(KEY_D))
    {
        playerposition.x += speed;
    }

    if (IsKeyPressed(KEY_Q))
    {
        std::cout << playerposition.x << "\n";
        std::cout << playerposition.y << "\n";
    }
}

Texture2D PC::GetTexture() {
    return pc;
}

Vector2 PC::GetPositionVec() {
    return Vector2();
}

void PC::SetPositionVec(Vector2 position) {
    playerposition = position;
}

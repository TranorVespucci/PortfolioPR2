//
// Created by goerk on 09.08.2022.
//

#include "PC.h"
#include <iostream>

PC::PC() = default;

PC::~PC() = default;

void PC::Draw() {
    playerrec = {playerposition.x, playerposition.y, 16, 16 };
    DrawRectangleRec(playerrec, Color{});
    DrawTextureRec(pc,playerrec,playerposition, WHITE);
    playerrec.x = (float)currentFrame * (float)pc.width / 2;

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
        playerposition.x -= speed;
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

Rectangle PC::GetPlayerRectangle() {
    return playerrec;
}

float PC::GetSpeed() {
    return speed;
}

float PC::GetDownCollision() {
    playerposition.y -= 0.1;
    //speed = 0;
}

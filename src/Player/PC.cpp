//
// Created by goerk on 09.08.2022.
//

#include "PC.h"
#include <iostream>

PC::PC() : Char(50, 60, 7) {

}

PC::~PC() = default;

void PC::Draw() {
    playerrec = {playerposition.x, playerposition.y, 16, 16 };
    DrawRectangleRec(playerrec, Color {});
    DrawTextureRec(pc,framerec,playerposition, WHITE);
    playerrec.x = (float)currentFrame * (float)pc.width / 2;

}


void PC::Update() {

    if (IsKeyDown(KEY_W))
    {
        direction = Direction::UP;
        playerposition.y -= speed;
    }

    if (IsKeyDown(KEY_S))
    {
        direction = Direction::DOWN;
        playerposition.y += speed;
    }

    if (IsKeyDown(KEY_A))
    {
        direction = Direction::LEFT;
        playerposition.x -= speed;
    }

    if  (IsKeyDown(KEY_D))
    {
        direction = Direction::RIGHT;
        playerposition.x += speed;
    }

    if (IsKeyPressed(KEY_Q))
    {
        /*
        std::cout << playerposition.x << "\n";
        std::cout << playerposition.y << "\n";*/
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
    return {playerposition.x, playerposition.y, static_cast<float>(pc.width), static_cast<float>(pc.height)};
}

float PC::GetSpeed() {
    return speed;
}

float PC::Collision() {
    switch (direction)
    {
        case Direction::UP:
            playerposition.y += 1;
            break;
        case Direction::DOWN:
            playerposition.y -= 1;
            break;
        case Direction::LEFT:
            playerposition.x += 1;
            break;
        case Direction::RIGHT:
            playerposition.x -= 1;
            break;
    }
}



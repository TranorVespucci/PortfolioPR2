//
// Created by goerk on 09.08.2022.
//

#include "PC.h"
#include <iostream>

PC::PC() = default;

PC::~PC() = default;

void PC::Draw() {
    //DrawTexture(pc,playerrec.x,playerrec.y,WHITE);
    playerrec = {0, 0, 16, 16 };
    DrawTextureRec(pc,playerrec,playerposition, WHITE);
}

float PC::GetXPosition() {
    return playerposition.x;
}

float PC::GetYPosition() {
    return playerposition.y;
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
}

Texture2D PC::GetTexture() {
    return pc;
}

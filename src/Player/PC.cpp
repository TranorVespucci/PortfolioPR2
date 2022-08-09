//
// Created by goerk on 09.08.2022.
//

#include "PC.h"

PC::PC() = default;

PC::~PC() = default;

/*void PC::Draw(float x, float y) {
}*/


void PC::Draw(Vector2 position) {
    DrawTextureRec(pc,playerrec, position, WHITE);
}

int PC::GetXPosition() {
    return playerrec.x;
}

int PC::GetYPosition() {
    return playerrec.y;
}

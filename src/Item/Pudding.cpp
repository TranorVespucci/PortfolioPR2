//
// Created by user on 26.09.2022.
//

#include "Pudding.h"

Pudding::Pudding() : ItemBase("Puddi pud Pud", 1, 2, "Kneel before Pudding or die") {
    puddingposition = {static_cast<float>((rand()%300 + 1)), static_cast<float>(rand()%300 + 1)};
    Type = PUDDING;
    texture_ = LoadTexture("assets/graphics/spr_Pudding.png");
}

void Pudding::Draw() {
    puddingrec = {puddingposition.x, puddingposition.y, 16, 16};
    DrawRectangleRec(puddingrec, Color{});
    DrawTextureRec(pudding, framerec, puddingposition, WHITE);
    puddingrec.x = (float)currentFrame * (float)pudding.width / 2;
}

Rectangle Pudding::getRec() {
    return {puddingposition.x, puddingposition.y, static_cast<float>(texture_.width), static_cast<float>(texture_.height)};
}

Rectangle Pudding::deleteRec() {
    return {};
}

Pudding::~Pudding() {

}

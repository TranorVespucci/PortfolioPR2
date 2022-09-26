//
// Created by user on 26.09.2022.
//

#include "Chilli.h"

Chilli::Chilli() : ItemBase("Chilli Boom Boom", 2, 4, "Eat it and your throat go Boom Boom :)") {
    chilliposition = {static_cast<float>((rand()%300 + 1)), static_cast<float>(rand()%300 + 1)};
    Type = CHILLI;
    texture_ = LoadTexture("assets/graphics/spr_Chilli.png");
}

void Chilli::Draw() {
    chillirec = {chilliposition.x, chilliposition.y, 16, 16};
    DrawRectangleRec(chillirec, Color{});
    DrawTextureRec(chilli, framerec, chilliposition, WHITE);
    chillirec.x = (float)currentFrame * (float)chilli.width / 2;
}

Rectangle Chilli::getRec() {
    return {chilliposition.x, chilliposition.y, static_cast<float>(texture_.width), static_cast<float>(texture_.height)};
}

Rectangle Chilli::deleteRec() {
    return {};
}

Chilli::~Chilli() {

}

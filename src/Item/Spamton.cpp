//
// Created by user on 26.09.2022.
//

#include "Spamton.h"

Spamton::Spamton() : ItemBase("Spamton G. Spamton", 1, 9, "He a Good Boi") {
    spamtonposition = {static_cast<float>((rand()%300 + 1)), static_cast<float>(rand()%300 + 1)};
    Type = SPAMTON;
    texture_ = LoadTexture("assets/graphics/spr_Spamton.png");

}

void Spamton::Draw() {
    spamtonrec = {spamtonposition.x, spamtonposition.y, 16, 16};
    DrawRectangleRec(spamtonrec, Color{});
    DrawTextureRec(spamton, framerec, spamtonposition, WHITE);
    spamtonrec.x = (float)currentFrame * (float)spamton.width / 2;
}

Rectangle Spamton::getRec() {
    return {spamtonposition.x, spamtonposition.y, static_cast<float>(texture_.width), static_cast<float>(texture_.height)};
}

Rectangle Spamton::deleteRec() {
    return {};
}

Spamton::~Spamton() {

}

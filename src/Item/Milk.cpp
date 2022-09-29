//
// Created by user on 26.09.2022.
//

#include "Milk.h"

Milk::Milk() : ItemBase("MOO MOO MILCH!!!!", 3, 5, "Certified Momy Milk. \nAnd I fucking love it! <3") {
    milkposition = {static_cast<float>((rand()%300 + 1)), static_cast<float>(rand()%300 + 1)};
    Type = MILK;
    E_Type = ARMOR;
    texture_ = LoadTexture("assets/graphics/spr_milk.png");
}

void Milk::Draw() {
    milkrec = {milkposition.x, milkposition.y, 16, 16};
    DrawRectangleRec(milkrec, Color {});
    DrawTextureRec(milk, framerec, milkposition, WHITE);
    milkrec.x = (float)currentFrame * (float)milk.width / 2;

}


Rectangle Milk::getRec() {
    return {milkposition.x, milkposition.y, static_cast<float>(texture_.width), static_cast<float>(texture_.height)};
}
Rectangle Milk::deleteRec() {
    return {};
}

Milk::~Milk() {

}

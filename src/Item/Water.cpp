//
// Created by user on 10.08.2022.
//

#include "Water.h"

Water::Water() : ItemBase("Bottle of Water", 1, 2, "British People love to \nask for a Bottle of Water") {
    waterposition = {static_cast<float>((rand()%300 + 1)), static_cast<float>(rand()%300 + 1)};
    Type = WATER;
    E_Type = ACCESSOIR;
    texture_ = LoadTexture("assets/graphics/spr_Water.png");
}

Water::~Water() {

}

void Water::Draw() {

    waterrec = {waterposition.x, waterposition.y, 16, 16};
    DrawRectangleRec(waterrec, Color{});
    DrawTextureRec(water, framerec, waterposition, WHITE);
    waterrec.x = (float)currentFrame * (float)water.width / 2;



}

Rectangle Water::getRec() {
   return {waterposition.x, waterposition.y, static_cast<float>(texture_.width), static_cast<float>(texture_.height)};
}

Rectangle Water::deleteRec() {
  return {};
}

//
// Created by goerk on 09.08.2022.
//

#include "Char.h"

Char::Char(int HP, int STR, int MaxWeight) : pc_HP(HP), pc_Str(STR), pc_maxWeight(MaxWeight) {

}


void Char::Draw() {

}

Char::~Char() = default;

void Char::Update() {

}

Texture2D Char::GetTexture() {
    return Texture2D();
}

Vector2 Char::GetPositionVec() {
    return Position;
}

void Char::SetPositionVec(Vector2 position) {

}

Rectangle Char::GetPlayerRectangle() {
    return Rectangle();
}

float Char::GetSpeed() {
    return 0;
}

float Char::Collision() {
    return 0;
}



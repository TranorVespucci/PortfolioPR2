//
// Created by goerk on 09.08.2022.
//

#include "Char.h"

Char::Char() = default;

void Char::Draw() {

}

Char::~Char() = default;

float Char::GetXPosition() {
    return Position.x;
}

float Char::GetYPosition() {
    return Position.y;
}

void Char::Update() {

}

Texture2D Char::GetTexture() {
    return Texture2D();
}

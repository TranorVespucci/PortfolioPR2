//
// Created by user on 10.08.2022.
//

#include "Sprite.h"

Sprite::Sprite(int pos_X, int pos_Y, Texture2D Texture) {
    pos_x    = pos_X;
    pos_y    = pos_Y;
    texture_ = Texture;
}

Sprite::~Sprite()
{
    TraceLog(LOG_INFO, "This is a Game for my Exam, which I most likely will fail");
    UnloadTexture(texture_);
}

//
// Created by user on 10.08.2022.
//

#include <raylib.h>


class Sprite {
public:
    int pos_x;
    int pos_y;
    Texture2D texture_;

    Sprite(int pos_x, int pos_y, Texture2D texture);

    ~Sprite();
};




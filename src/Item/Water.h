//
// Created by user on 10.08.2022.
//

#include "ItemBase.h"
#include <vector>

class Water : public ItemBase {
public:
    Water();
    void Draw() override;
    ~Water();

private:
    Vector2 waterposition = {};
    Texture2D water = LoadTexture("assets/graphics/chest_closed.png");
    Rectangle waterrec = {};
};


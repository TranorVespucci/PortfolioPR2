//
// Created by goerk on 09.08.2022.
//

#include "Char.h"
#include <string>

class PC: public Char{
public:
    PC();
    void Draw(Vector2 position) override;
    int GetXPosition() override;
    int GetYPosition() override;
    ~PC();

private:
    std::string pc_name;
    int pc_maxWeight{};
    int pc_HP{};
    int pc_Str{};
    Rectangle playerrec = {};
    Texture2D pc = LoadTexture("assets/graphics/PC.png");
    Vector2 PC_position = {};

};




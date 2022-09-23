//
// Created by goerk on 09.08.2022.
//

#include "Char.h"
#include <string>

class PC: public Char{
public:
    PC();
    void Draw() override;
    void Update() override;
    Texture2D GetTexture() override;
    Vector2 GetPositionVec() override;
    void SetPositionVec(Vector2 position) override;
    ~PC();

private:
    std::string pc_name;
    float speed = 16;
    int pc_maxWeight{};
    int pc_HP{};
    int pc_Str{};
    Rectangle playerrec = {};
    Vector2 playerposition = {};
    Texture2D pc = LoadTexture("assets/graphics/PC.png");
};




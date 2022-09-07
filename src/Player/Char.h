//
// Created by goerk on 09.08.2022.
//

#include <raylib.h>


class Char{
public:

    Char();
    virtual void Draw();
    virtual void Update();

    virtual Texture2D GetTexture();
    virtual Vector2 GetPositionVec();
    virtual void SetPositionVec(Vector2 position);
    ~Char();

protected:
    Vector2 Position = {};

};




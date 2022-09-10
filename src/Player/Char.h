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
    virtual Rectangle GetPlayerRectangle();
    virtual float GetSpeed();
    virtual float GetDownCollision();
    ~Char();

protected:
    Vector2 Position = {};

};




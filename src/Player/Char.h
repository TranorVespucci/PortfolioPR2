//
// Created by goerk on 09.08.2022.
//

#include <raylib.h>


class Char{
public:

    Char();
    virtual void Draw();
    virtual void Update();

    virtual float GetXPosition();
    virtual float GetYPosition();
    virtual Texture2D GetTexture();
    ~Char();

protected:
    Vector2 Position = {};

};




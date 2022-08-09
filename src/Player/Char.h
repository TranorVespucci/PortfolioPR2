//
// Created by goerk on 09.08.2022.
//

#include <raylib.h>


class Char{
public:

    Char();
    virtual void Draw(float x, float y);

    virtual void Draw(Vector2 position);
    virtual int GetXPosition();
    virtual int GetYPosition();
    ~Char();

protected:
    Vector2 Position = {};

};




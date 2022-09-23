//
// Created by goerk on 17.08.2022.
//

#include <array>
#include <raylib.h>
#include <iostream>

template <class I>
class Inventory {

private:
    I slots, maxSlots;

public:
    Inventory(I maxSize, I size)
    {
        slots = size;
        maxSlots = maxSize;

        if (slots < maxSlots)
        {
            std::cout << "Error";
        }
    }

    void getSize(){std::cout << slots;}



};

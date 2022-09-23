//
// Created by user on 21.09.2022.
//

#ifndef RAYLIBSTARTER_INVENTORY_H
#define RAYLIBSTARTER_INVENTORY_H
#include <vector>
#include <iostream>
#include <cassert>

template <class I>

class Inventory {
public:
    Inventory()
    {
    }

    bool AddItem(I ItemToBeAdded){
        if (content.size() >= MaxSize){
            return false;
        }
        else{content.push_back(ItemToBeAdded);}
    }

    I getSize()
    {
        return content.size();
    }


    ~Inventory()
    {
    }

private:
    std::vector<I> content;
    int MaxSize = 10;
};


#endif //RAYLIBSTARTER_INVENTORY_H

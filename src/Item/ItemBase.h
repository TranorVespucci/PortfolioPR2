//
// Created by user on 10.08.2022.
//
#pragma once
#include <raylib.h>
#include <string>
#include "../Enums/Enums.h"

class ItemBase {
public:

    itemType Type = ZERO;
    Texture2D texture_;
    ItemBase(std::string i_name, int i_weight, int i_price, std::string i_description );
    virtual void Draw();
    virtual Rectangle getRec();
    std::string getName();
    virtual Rectangle deleteRec();
    bool Active = true;

    ~ItemBase();
protected:

    int Strength;
    int weight;
    std::string name;
    std::string description;
    int price;
};


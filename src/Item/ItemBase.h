//
// Created by user on 10.08.2022.
//
#pragma once
#include <raylib.h>
#include <string>
#include "../Enums/Enums.h"

class ItemBase {
public:

    ItemBase();
    itemType Type = ZERO;
    EquipType E_Type = EMPTY;
    Texture2D texture_;
    ItemBase(const char* i_name, int i_weight, int i_price, const char* i_description );
    virtual void Draw();
    virtual Rectangle getRec();
    const char *getName();
    virtual Rectangle deleteRec();
    int getStrength();
    int getweight();
    const char *getdescription();
    int getprice();
    bool Active = true;
    ~ItemBase();


protected:
    int weight;
    int Strength;
    const char *name;
    const char *description;
    int price;
};


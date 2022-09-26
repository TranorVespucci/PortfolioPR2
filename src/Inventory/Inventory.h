//
// Created by user on 21.09.2022.
//
#pragma once
#ifndef RAYLIBSTARTER_INVENTORY_H
#define RAYLIBSTARTER_INVENTORY_H
#include <vector>
#include <raylib.h>
#include <iostream>
#include "../Item/Water.h"
#include "../Item/Chilli.h"

template <class I>

class Inventory {
public:
    ItemBase  *water = new Water();
    ItemBase *chilli = new Chilli();

    Inventory()
    {
        float x = GetScreenWidth() / 2 - 380;
        float y = GetScreenHeight() / 2 - 160;

        for (int i = 0; i < 5; i++){
            itemslot.push_back({x, y, 16, 16});
            x = x + 40;
        }
    }

    //This bool function tells, if the Inventory over or equal the maximum size, it will not add any item
    //Else it will add an element
    bool AddItem(I ItemToBeAdded){
        if (content.size() >= MaxSize){
            return false;
        }
        else{content.push_back(ItemToBeAdded);}
    }
    //This is the same by asking the size

    I Slot(int slotnumber){
        if (slotnumber < content.size()){
           switch (content[slotnumber].Type) {
                case WATER:
                    std::cout << water->getName() << "\n";
                break;
               case CHILLI:
                   std::cout << chilli->getName() << "\n";
                   break;

               default:
                   std::cout << "What?\n";
                   break;
            }
            return content[slotnumber];
        }


    }

    int getSize()
    {
        return content.size();
    }

    I setSize(I size)
    {
        size = MaxSize;
    }

    void Draw(){
        invrec1 = {static_cast<float>(GetScreenWidth() / 2 - 380), static_cast<float>(GetScreenHeight() / 2 - 160), 16, 16};
        invrec2 = {static_cast<float>(GetScreenWidth() / 2 - 340), static_cast<float>(GetScreenHeight() / 2 - 160), 16, 16};

        if (IsKeyDown(KEY_I)) {
            inventoryDrawActive = true;
        }
        if (inventoryDrawActive) {
            DrawTexture(spr_inventory, GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 250, WHITE);

            /*
            DrawRectangleRec(invrec1, RED);
            DrawRectangleRec(invrec2, RED);*/

            for (int i = 0; i < itemslot.size(); i++){
                DrawRectangleRec(itemslot[i], Color {});
            }

            for (int i = 0; i < MaxSize; i++){
                DrawTexture(content[i].texture_, itemslot[i].x, itemslot[i].y, WHITE);
            }

        } if (IsKeyPressed(KEY_O)) {
            inventoryDrawActive = false;
        }



    }


    ~Inventory()
    {
    }

private:
    std::vector<Rectangle> itemslot;
    Rectangle invrec1 = {};
    Rectangle invrec2 = {};
    bool inventoryDrawActive = false;
    std::vector<I> content;
    int MaxSize = 10;
    Texture2D spr_inventory = LoadTexture("assets/graphics/spr_inventory.png");
};


#endif //RAYLIBSTARTER_INVENTORY_H

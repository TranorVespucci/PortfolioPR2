//
// Created by user on 21.09.2022.
//
#pragma once
#include <vector>
#include <raylib.h>
#include <iostream>
#include "../Item/Water.h"
#include "../Item/Chilli.h"
#include "../Item/Milk.h"
#include "../Item/Pudding.h"
#include "../Item/Spamton.h"
#include <algorithm>
template <class I>

class Inventory {
public:
    ItemBase *water = new Water();
    ItemBase *chilli = new Chilli();
    ItemBase *milk = new Milk();
    ItemBase *pudding = new Pudding();
    ItemBase *spamton = new Spamton();

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
        else {
            content.push_back(ItemToBeAdded);
        }

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
               case MILK:
                   std::cout << milk->getName() << "\n";
               case PUDDING:
                   std::cout << pudding->getName() << "\n";
                   break;
               case SPAMTON:
                   std::cout << spamton->getName() << "\n";
                   break;

               default:
                   std::cout << "What?\n";
                   break;
            }
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

        //DRAWING THE INVENTORY!!!!
        if (IsKeyDown(KEY_I)) {
            inventoryDrawActive = true;
        }
        if (inventoryDrawActive) {
            DrawTexture(spr_inventory, GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 250, WHITE);
            currentitemselected = {static_cast<float>(GetScreenWidth() / 2 - 375), static_cast<float>(GetScreenHeight() / 2 - 210), 16, 16};
            armorrec = {static_cast<float>(GetScreenWidth() / 2 - 320), static_cast<float>(GetScreenHeight() / 2 - 225), 16, 16};
            accessoirrec = {static_cast<float>(GetScreenWidth() / 2 - 285), static_cast<float>(GetScreenHeight() / 2 - 225), 16, 16};
            weaponrec = {static_cast<float>(GetScreenWidth() / 2 - 320), static_cast<float>(GetScreenHeight() / 2 - 195), 16, 16};

            /*
            DrawRectangleRec(armorrec, YELLOW);
            DrawRectangleRec(accessoirrec, YELLOW);
            DrawRectangleRec(weaponrec, YELLOW);
            */

            if(IsKeyPressed(KEY_D)){
                box_rec.x += 40;
            }
            if(IsKeyPressed(KEY_A)){
                box_rec.x -= 40;
            }

            if (box_rec.x < 100) box_rec.x = 100;
            else if (box_rec.x > 260) box_rec.x = 260;

            DrawRectangleRec(box_rec, GREEN);

if (content.empty() == false) {


    for (int i = 0; i < itemslot.size(); i++) {
        DrawRectangleRec(itemslot[i], Color{});

    }

    for (int i = 0; i < MaxSize; i++) {
        DrawTexture(content[i].texture_, itemslot[i].x, itemslot[i].y, WHITE);

        if (itemslot[i].x == box_rec.x && itemslot[i].y == box_rec.y && itemslot[i].width == box_rec.width &&
            itemslot[i].height == box_rec.height) {
            if (i < content.size()) {

                //DRAW THE INFORMATION!!!!
                DrawTexture(content[i].texture_, static_cast<float>(GetScreenWidth() / 2 - 375),
                            static_cast<float>(GetScreenHeight() / 2 - 210), WHITE);
                DrawText(TextFormat("Name: %s", content[i].getName()), static_cast<float>(GetScreenHeight() / 2 - 105),
                         static_cast<float>(GetScreenHeight() / 2 - 230), 1, BLACK);
                DrawText(TextFormat("Price: %i", content[i].getprice()),
                         static_cast<float>(GetScreenHeight() / 2 - 105),
                         static_cast<float>(GetScreenHeight() / 2 - 220), 1, BLACK);
                DrawText(TextFormat("Weight: %i", content[i].getweight()),
                         static_cast<float>(GetScreenHeight() / 2 - 105),
                         static_cast<float>(GetScreenHeight() / 2 - 210), 1, BLACK);
                DrawText(TextFormat("%s", content[i].getdescription()), static_cast<float>(GetScreenHeight() / 2 - 105),
                         static_cast<float>(GetScreenHeight() / 2 - 200), 1, BLACK);
            }

            //DISCARD ITEM PERMANETELY FROM THE GAME
            if (IsKeyPressed(KEY_M)){
                content.erase(content.cbegin()+i);
            }


        }
    }

}
//Closing the Inventory
        } if (IsKeyPressed(KEY_O)) {
            inventoryDrawActive = false;
        }


    }

//SORT ALGORITHM!!!!
    void bubbleSort(std::vector<I> &sort){
        for (size_t i = 0; i < sort.size() - 1; i++){
            for(size_t j = 0; j < sort.size() - i - 1; j++){
                if (sort.at(j) > sort.at(j + 1))
                    std::swap(sort.at(j), sort.at(j + 1));
            }
        }
    }

    //CALCULATING OBJECT WEIGHT AND CALCULATING THE TOTAL WEIGHT IN THE INVENTORY
    int getWeight(){
       inventoryweight = 0;
        for (int i = 0; i < content.size(); i++){
            inventoryweight = inventoryweight + content[i].getweight();
        }
        return inventoryweight;
    }

    bool get_inventoryActive(){
        return inventoryDrawActive;
    }


    ~Inventory()
    {
        delete water;
        delete chilli;
        delete milk;
        delete pudding;
        delete spamton;
    }

private:
    Rectangle box_rec = {static_cast<float>(GetScreenWidth() / 2 - 380), static_cast<float>(GetScreenHeight() / 2 - 160), 16, 16};
    Rectangle currentitemselected = {};
    Rectangle armorrec = {};
    Rectangle accessoirrec = {};
    Rectangle weaponrec = {};
    std::vector<Rectangle> itemslot;
    std::vector<I> Armor;
    std::vector<I> Accessoir;
    std::vector<I> Weapon;
    bool inventoryDrawActive = false;
    std::vector<I> content;
    int MaxSize = 10;
    int inventoryweight = 0;
    Texture2D spr_inventory = LoadTexture("assets/graphics/spr_inventory.png");
};



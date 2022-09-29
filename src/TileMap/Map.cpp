//
// Created by goerk on 08.08.2022.
//
#include "Map.h"

int r = GetRandomValue(0, 1);

int Path[20][25] = {

        //THIS IS WHERE THE MAP IS DRAWN AND SET.

        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 2 },
        { 2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 2 },
        { 2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },


};




Map::Map()
{

    LoadMap(Path);

}

void Map::LoadMap(int arr[20][25])
{
    for (int row = 0; row < 20; row++)
    {
        for (int column = 0; column < 25; column++)
        {
            //SETTING THE SPAWN POSITION. PLAYER WILL ALWAYS SPAWN
            map[row][column] = arr[row][column];
            if (arr[row][column]== 3) {
                x = column * 16;
                y = row * 16;
                pc->SetPositionVec({static_cast<float>(x), static_cast<float>(y)});
            }

        }
    }

    for (int row = 0; row < 20; row++) {
        for (int column = 0; column < 25; column++) {

            //GIVING ALL STONES A RECTANGLE TO COLLIDE
            map[row][column] = arr[row][column];
            if (arr[row][column] == 1) {
                x = column * 16;
                y = row * 16;
                Rectangle BigStonerec = {0, 0, 16, 16};
                BigStonerec = {(float) x, (float) y, 13, 13};
                stonerecc.push_back(BigStonerec);
            }
        }
    }
}

void Map::DrawMap() {

    for (int row = 0; row < 20; row++) {
        for (int column = 0; column < 25; column++) {
            int type = map[row][column];
            x = column * 16;
            y = row * 16;

            //Setting the Rectangles to X and Y, so that they stay at the Drawing Position.
            T_StartRec.x = x;
            T_StartRec.y = y;

            //SWITCH CASE TELLS, WHAT WILL BE DRAWN IN THE NUMBERS!!!
            switch (type) {
                case 0:
                    DrawTextureRec(T_map, T_frameRec, {(float) x, (float) y}, WHITE);

                    T_frameRec.x = (float) currentFrame * (float) T_map.width / 7;
                    break;

                case 1:
                    DrawTexture(Stone, x, y, WHITE);

                    break;


                case 3:
                    DrawTextureRec(Spawn, T_StartRec, {(float) x, (float) y}, WHITE);

                    T_StartRec.x = (float) currentStartFrame * (float) T_map.width / 23;

                    break;

                case 2:
                    DrawTexture(Tree, (float) x, (float) y, WHITE);

                    break;

                case 4:
                    goalrec = {(float) x, (float) y, 16, 16};
                    DrawTexture(Goal, goalrec.x, goalrec.y, WHITE);
                    break;

                default:
                    break;

               }
        }
    }

    //DRAWING THE ITEMS IN THE MAP
    if (WaterDraw) {
        water->Draw();
    }
    if (ChilliDraw) {
        chilli->Draw();
    }
    if (MilkDraw){
        milk->Draw();
    }
    if (PuddingDraw){
        pudding->Draw();
    }
    if (SpamtonDraw){
        spamton->Draw();
    }

    pc->Update();
    pc->Draw();
    Collision();
    WeightOverload();
    inventory.Draw();
}


void Map::Collision() {

//SETTING THE COLLISIONS IN A BOOL VARIABLE TO MAKE THE TYPING EASIER
    Rectangle playerrectangle = pc->GetPlayerRectangle();
    wallCollision = CheckCollisionRecs(border1, playerrectangle);
    wallCollision2 = CheckCollisionRecs(border2, playerrectangle);
    wallCollision3 = CheckCollisionRecs(border3, playerrectangle);
    wallCollision4 = CheckCollisionRecs(border4, playerrectangle);
    StoneCollision = false;
    for (int i = 0; i < stonerecc.size(); i++){
        if (CheckCollisionRecs(stonerecc[i], playerrectangle)) {
            StoneCollision = true;
        }
    }
    GoalCollision = CheckCollisionRecs(goalrec, playerrectangle);

    //THIS IS WHERE THE COLLISIONS BETWEEN PLAYER AND OBJECT IS SET
    if (wallCollision){pc->Collision(); }
    if (wallCollision2){pc->Collision(); }
    if (wallCollision3){pc->Collision(); }
    if (wallCollision4){pc->Collision(); }
    if (StoneCollision){pc->Collision(); }
    if (GoalCollision){CloseWindow();}

    //ADDING THE ITEMS IN THE INVENTORY ARRAY
    if (water->Active) {
        if (CheckCollisionRecs(pc->GetPlayerRectangle(), water->getRec())) {
            water->Active = false;
            std::cout << "Collision" << "\n";
            WaterDraw = false;
            Water saskia;
            inventory.AddItem(saskia);
        }
    }

    if (chilli->Active){
        if (CheckCollisionRecs(pc->GetPlayerRectangle(), chilli->getRec())){
            chilli->Active = false;
            ChilliDraw = false;
            Chilli Javier;
            inventory.AddItem(Javier);
        }
    }

    if (milk->Active){
        if (CheckCollisionRecs(pc->GetPlayerRectangle(), milk->getRec())){
            milk->Active = false;
            MilkDraw = false;
            Milk WillSmith;
            inventory.AddItem(WillSmith);
        }
    }

    if (pudding->Active){
        if (CheckCollisionRecs(pc->GetPlayerRectangle(), pudding->getRec())){
            pudding->Active = false;
            PuddingDraw = false;
            Pudding Charlotte;
            inventory.AddItem(Charlotte);
        }
    }

    if(spamton->Active){
        if (CheckCollisionRecs(pc->GetPlayerRectangle(), spamton->getRec())){
            spamton->Active = false;
            SpamtonDraw = false;
            Spamton SpamtonNEO;
            inventory.AddItem(SpamtonNEO);
        }
    }
}


//AS THE FUNCTION SAYS, PLAYER CAN'T MOVE, IF THE TOTAL INVENTORY WEIGHT IS HIGHER THAN THE PLAYERS STRENGTH
void Map::WeightOverload()
{
    if (inventory.get_inventoryActive()){
        pc->Active = false;
    }
    if (!inventory.get_inventoryActive()){
        pc->Active = true;
    }

    if (IsKeyPressed(KEY_ENTER)){
        std::cout << "Inventory Weight: "<< inventory.getWeight() << "\n";
        std::cout << "Player Weight: "<< pc->getMaxWeight() << "\n";
    }

    if (inventory.getWeight() >= pc->getMaxWeight()){
        pc->Active = false;
    }
}




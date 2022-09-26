//
// Created by goerk on 08.08.2022.
//
#include "Map.h"



int Path[20][25] = {

        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2 },



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

            map[row][column] = arr[row][column];
            if (arr[row][column] == 1) {
                x = column * 16;
                y = row * 16;
                Rectangle BigStonerec = {0, 0, 16, 16};
                BigStonerec = {(float) x, (float) y, 16, 16};
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
            switch (type) {
                case 0:
                    DrawTextureRec(T_map, T_frameRec, {(float) x, (float) y}, WHITE);

                    T_frameRec.x = (float) currentFrame * (float) T_map.width / 7;
                    break;

                case 1:

                    for (int i = 0; i < stonerecc.size(); i++) {
                        DrawRectangleRec(stonerecc[i], Color{});
                        DrawTexture(Stone, stonerecc[i].x, stonerecc[i].y, WHITE);
                    }

                    break;

                case 3:
                    DrawTextureRec(Spawn, T_StartRec, {(float) x, (float) y}, WHITE);
                    //DrawRectangleRec(T_StartRec, RED);

                    T_StartRec.x = (float) currentStartFrame * (float) T_map.width / 23;

                    break;

                case 2:
                    DrawTexture(Tree, (float) x, (float) y, WHITE);

                    break;

                case 4:
                    goalrec = {(float) x, (float) y, 16, 16};
                    //DrawRectangleRec(goalrec, RED);
                    DrawTexture(Goal, goalrec.x, goalrec.y, WHITE);
                    break;

                default:
                    break;

            }
        }
    }
    if (WaterDraw) {
        water->Draw();
    }
    if (ChilliDraw) {
        chilli->Draw();
    }
    pc->Update();
    pc->Draw();
    Collision();
    inventory.Draw();
}


void Map::Collision() {

    //DrawRectangleRec(border1, RED);
    //DrawRectangleRec(border2, RED);
    //DrawRectangleRec(border3, RED);
    //DrawRectangleRec(border4, RED);


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

    if (wallCollision){pc->Collision(); }
    if (wallCollision2){pc->Collision(); }
    if (wallCollision3){pc->Collision(); }
    if (wallCollision4){pc->Collision(); }
    if (StoneCollision){pc->Collision(); }
    if (GoalCollision){CloseWindow();}

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


    if (IsKeyDown(KEY_F))
    {
        inventory.Slot(0);
    }

    if (IsKeyPressed(KEY_P)){
        std::cout << inventory.getSize() << "\n";
    }
}



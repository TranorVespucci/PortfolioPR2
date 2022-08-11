//
// Created by user on 10.08.2022.
//

#include "Water.h"

Water::Water() : ItemBase("Bottle of Water", 3, 2, "British People love to ask for a Bottle of Water") {
    waterposition = {(rand()%300 + 1), rand()%300 + 1};
}

Water::~Water() {

}

void Water::Draw() {

    waterrec = {0, 0, 16, 16};
    DrawTextureRec(water, waterrec, waterposition, WHITE);


}

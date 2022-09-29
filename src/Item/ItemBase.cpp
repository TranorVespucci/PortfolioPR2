//
// Created by user on 10.08.2022.
//

#include "ItemBase.h"
ItemBase::ItemBase() {}

ItemBase::ItemBase(const char* i_name, int i_weight, int i_price, const char* i_description)
: name(i_name), weight(i_weight), price(i_price), description(i_description){

}

ItemBase::~ItemBase() {

}

void ItemBase::Draw() {

}

Rectangle ItemBase::getRec() {
    return Rectangle();
}

Rectangle ItemBase::deleteRec() {
    return Rectangle();
}

const char *ItemBase::getName() {
    return name;
}

int ItemBase::getStrength() {
    return Strength;
}

const char *ItemBase::getdescription() {
    return description;
}

int ItemBase::getprice() {
    return price;
}

int ItemBase::getweight() {
    return weight;
}



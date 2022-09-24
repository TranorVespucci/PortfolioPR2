//
// Created by user on 10.08.2022.
//

#include "ItemBase.h"

ItemBase::ItemBase(std::string i_name, int i_weight, int i_price, std::string i_description)
: name(i_name), weight(i_weight), price(i_price), description(i_description){

}

ItemBase::~ItemBase() {

}

void ItemBase::Draw() {

}

Rectangle ItemBase::getRec() {
    return Rectangle();
}



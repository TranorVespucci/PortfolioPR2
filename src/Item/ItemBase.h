//
// Created by user on 10.08.2022.
//

#include <raylib.h>
#include <string>

class ItemBase {
public:
    ItemBase(std::string i_name, int i_weight, int i_price, std::string i_description );
    virtual void Draw();
    virtual Rectangle getRec();
    ~ItemBase();
protected:
    int weight;
    std::string name;
    std::string description;
    int price;
};


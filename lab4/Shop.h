//
// Created by Gleb Nemirko on 23.10.2022.
//
#include "Weapon.h"



#ifndef LAB1C___SHOP_H
#define LAB1C___SHOP_H
class Shop {
public:
    int size;
    Weapon catalogue[100];
    Shop(){
        size = 100;
    }
    void fillShop();
    Weapon openShop(int money_in_purse);
    Weapon showAvailableItems(int money);
    Weapon buyItem(int id);
};


#endif //LAB1C___SHOP_H

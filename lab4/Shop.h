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
/*
 * Заполнение магазина товарами
 */
    void fillShop();
/*
 * Открывает магазин
 *
 * @param money_in_purse - сколько денег у покупателя
 * @return Weapon которое было куплено
 */
    Weapon openShop(int money_in_purse);
/*
 * Открывает магазин
 *
 * @param money - Досутпные деньги
 * @return Weapon которое было куплено
 */
    Weapon showAvailableItems(int money);
/*
 * Покупает оружие
 *
 * @param id - id покупаемого оружия
 * @return Weapon которое было куплено
 */
    Weapon buyItem(int id);
};


#endif //LAB1C___SHOP_H

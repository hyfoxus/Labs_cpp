//
// Created by Gleb Nemirko on 23.10.2022.
//

#include "Shop.h"
#include "Weapon.h"
#include "Bow.h"
//#include "Weapon.cpp"
#include "Bow.cpp"
#include "Sword.h"
#include "Sword.cpp"
#include "Spear.h"
#include "Spear.cpp"

using namespace std;

void Shop::fillShop() {
    srand(time(NULL));
    for (int i = 0; i < size - 3; ++i) {
        int type = rand() % 3;
        switch (type) {
            case 0: {
                Bow bow;
                catalogue[i] = (Weapon)bow;
                break;
            }
            case 1: {
                Sword sword;
                catalogue[i] = (Weapon)sword;
                break;
            }
            case 2: {
                Spear spear;
                catalogue[i] = (Weapon)spear;
                break;
            }
            default: {
                break;
            }
        }
    }
    Bow bow(Weapon::Legendary);
    catalogue[size - 3] = (Weapon)bow;
    Sword sword (Weapon::Epic);
    catalogue[size - 2] = (Weapon)sword;
    Spear spear(Weapon::Rare);
    catalogue[size - 1] = (Weapon)spear;
}

Weapon Shop::openShop(int money_in_purse) {
    cout << "Hello, dear customer! What can I do for you?"<<endl;
    cout << "Options: 1) Show catalogue \t 2) Leave"<<endl;
    int answer;
    bool answer_exists = false;
    while (!answer_exists){
        cin >> answer;
        if (answer == 1) {
            Weapon purchase = showAvailableItems(money_in_purse);
            answer_exists = true;
            return purchase;
        }
        else if (answer == 2){
            answer_exists = true;
            break;
        }
        else cout << "I can't seem to understand you, can you repeat please?"<<endl;
    }
}

Weapon Shop::showAvailableItems(int money) {
    cout << "Here is what you can afford:" << endl;
    for (int i = 0; i < size; ++i) {

        if ((catalogue[i]).cost <= money) cout << i << ". " << (catalogue[i]).item_name << " Price: " << (catalogue[i]).cost <<  endl;
    }
    cout << "Do you want to buy anything? \n 1 - Yes\t 2 - No" << endl;
    int answer;
    bool answer_exists = false;
    while (!answer_exists){
        cin >> answer;
        if (answer == 1) {
            cout << "What do you want to buy?" << endl;
            int purchase_id;
            cin >> purchase_id;
            Weapon purchase = buyItem(purchase_id);
            answer_exists = true;
            return purchase;
        }
        else if (answer == 2) {
            cout << "No problem! Good luck!" << endl;
            answer_exists = true;
            break;
        }
        else cout << "I can't seem to understand you, can you repeat please?"<<endl;
    }
}

Weapon Shop::buyItem(int id) {
    srand(time(NULL));
    Weapon purchase = catalogue[id];
    int type = rand() % 3;
    switch (type) {
        case 0: {
            Bow bow;
            catalogue[id] = (Weapon)bow;
            break;
        }
        case 1: {
            Sword sword;
            catalogue[id] = (Weapon)sword;
            break;
        }
        case 2: {
            Spear spear;
            catalogue[id] = (Weapon)spear;
            break;
        }
        default: {
            break;
        }
    }
    return purchase;
}
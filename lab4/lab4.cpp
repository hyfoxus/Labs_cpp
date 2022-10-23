#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Weapon.h"
#include "Weapon.cpp"
#include "Shop.h"
#include "Shop.cpp"

using namespace std;

void showWeapon(Weapon weapon){
    //cout << weapon.image << endl;
    cout << "Name: " << weapon.item_name << endl;
    cout << "Rarity: " << weapon.rarity << endl;
    cout << "Element: " << weapon.element << endl;
    cout << "Durability: " << weapon.durability << endl;
    cout << "Damage: " << weapon.damage << endl;
    cout << "Speed: " << weapon.speed << endl;
    cout << "Ability: " << weapon.ability << endl;

}

void showInventory(int filled_slots, Weapon* weapon_inventory){

    for (int i = 0; i < filled_slots + 1; ++i) {
        cout << i << ". " << weapon_inventory[i].item_name <<  endl;
    }
}

int main() {
    srand(time(NULL));
    int money;
    Weapon weapon_inventory[100];
    int current_slot = 0;

    cout << "How much money do you have?" << endl;
    cin >> money;

    Shop shop;
    shop.fillShop();
    Weapon weapon = shop.openShop(money);
    money -= weapon.cost;

    weapon_inventory[current_slot] = weapon;
    current_slot++;

    bool in_shop = true;
    while (in_shop){
        cout << "Do you want to buy anything more?";
        cout << "Options: 1 - Yes \t 2 - No";
        int answer;
        bool answer_exists = false;
        while (!answer_exists){
            cin >> answer;
            if (answer == 1) {
                Weapon purchase = shop.showAvailableItems(money);
                weapon_inventory[current_slot] = purchase;
                current_slot++;
                answer_exists = true;
            }
            else if (answer == 2) {
                answer_exists = true;
                in_shop = false;
                break;
            }
            else cout << "I can't seem to understand you, can you repeat please?" << endl;
        }
    }
    cout << "Inventory commands:\n 1) Show Inventory\n 2) Show Weapon" << endl;
    while (true){
    int action;
    cin >> action;
    if (action == 1) showInventory(current_slot, weapon_inventory);
    if (action == 2){
        cout << "Insert ID" << endl;
        int id;
        cin >> id;
        if (id < 0 || id >= current_slot) break;
        else showWeapon(weapon_inventory[id]);
        }
    }

    return 0;
}
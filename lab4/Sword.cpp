//
// Created by Gleb Nemirko on 23.10.2022.
//


#include "Weapon.h"
#include "Sword.h"

using namespace std;
//void Sword::setImage(){
//    image = "              />\n"
//            " (           //------------------------------------------------------(\n"
//            "(*)OXOXOXOXO(*>                  --------                             \\\n"
//            " (           \\\\--------------------------------------------------------)\n"
//            "              \\>";
//
//}

void Sword::setAbility() {

    string starting_part = "Creates Sword Beam that deals " ;
    string damage_ability = to_string((rarity_enum + 1) * damage * 10);
    string ending_part = " points of " + element + " damage!";
    ability = starting_part + damage_ability + ending_part;
}

void Sword::setName() {
    item_name = rarity + " Sword of " + element;
}
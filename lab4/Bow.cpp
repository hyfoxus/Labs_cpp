//
// Created by Gleb Nemirko on 23.10.2022.
//

#include "Bow.h"
#include "Weapon.h"

using namespace std;
//void Bow::setImage(){
//    image = "   (\n"
//            "    \\\n"
//            "     )\n"
//            "##-------->\n"
//            "     )\n"
//            "    /\n"
//            "   (";
//
//}

void Bow::setAbility() {

    string starting_part = "Creates Rain of Arrows that deals " ;
    string damage_ability = to_string((rarity_enum + 1) * damage * 10);
    string ending_part = " points of " + element + " damage!";
    ability = starting_part + damage_ability + ending_part;
}

void Bow::setName() {
    item_name = rarity + " Bow of " + element;
}
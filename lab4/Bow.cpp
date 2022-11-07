//
// Created by Gleb Nemirko on 23.10.2022.
//

#include "Bow.h"
#include "Weapon.h"

using namespace std;


/*
 * Создание картинки Лука
 *
 */

void Bow::setImage(){
    image = "   (\n"
            "    \\\n"
            "     )\n"
            "##-------->\n"
            "     )\n"
            "    /\n"
            "   (";

}


/*
 * Создание способности Лука
 *
 */

void Bow::setAbility() {

    string starting_part = "Creates Rain of Arrows that deals " ;
    string damage_ability = to_string((rarity_enum + 1) * damage * 10);
    string ending_part = " points of " + element + " damage!";
    ability = starting_part + damage_ability + ending_part;
}


/*
 * Создание имени Меча
 *
 */

void Bow::setName() {
    item_name = rarity + " Bow of " + element;
}
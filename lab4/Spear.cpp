//
// Created by Gleb Nemirko on 23.10.2022.
//

#include "Spear.h"
#include "Weapon.h"
using namespace std;

//void Spear::setImage(){
//    image = "                                                                                    ▓▓▓▓▓▓▓▓\n"
//            "                                                                                  ██▒▒░░░░██\n"
//            "                                                                                ██▒▒▒▒░░░░██\n"
//            "                                                                              ██▒▒░░░░░░  ██\n"
//            "                                                                            ██▒▒▒▒░░░░  ▒▒  \n"
//            "                                                                          ██▒▒░░░░░░  ██    \n"
//            "                                                                        ██▒▒░░░░░░  ██      \n"
//            "                                                                      ██▒▒░░░░░░  ▓▓        \n"
//            "                                                              ██    ██▒▒░░░░░░  ██          \n"
//            "                                                            ██▒▒████▒▒▒▒░░░░  ▓▓░░          \n"
//            "                                                            ██░░██▒▒░░░░░░  ██              \n"
//            "                                                            ██  ██▒▒░░░░  ▒▒░░              \n"
//            "                                                            ██    ██░░  ██                  \n"
//            "                                                            ██    ░░▓▓████                  \n"
//            "                                                          ██▓▓██      ░░▒▒██                \n"
//            "                                                        ██▒▒▒▒▒▒██████████                  \n"
//            "                                                      ██▓▓▒▒▒▒██                            \n"
//            "                                                    ██▒▒▒▒▒▒██                              \n"
//            "                                                  ▓▓▓▓▒▒▒▒▓▓                                \n"
//            "                                                ██▓▓▒▒▒▒██                                  \n"
//            "                                              ██▓▓▒▒▒▒██░░                                  \n"
//            "                                            ██▓▓▒▒▒▒██                                      \n"
//            "                                      ██████▒▒▒▒▒▒██                                        \n"
//            "                                    ▓▓░░░░  ██▒▒██                                          \n"
//            "                                      ████    ██                                            \n"
//            "                                    ▓▓▓▓▒▒▓▓  ██                                            \n"
//            "                              ██  ██▓▓▒▒▒▒██░░██                                            \n"
//            "                            ▒▒▒▒▒▒▓▓▒▒▒▒██░░▓▓                                              \n"
//            "                            ██  ██▒▒▒▒██                                                    \n"
//            "                            ██    ████                                                      \n"
//            "                          ██▓▓██  ░░░░██                                                    \n"
//            "                        ██▒▒▒▒▒▒██████                                                      \n"
//            "                      ▓▓▓▓▒▒▒▒██  ░░░░                                                      \n"
//            "                    ██▓▓▒▒▒▒██                                                              \n"
//            "                  ▓▓▓▓▒▒▒▒▓▓░░                                                              \n"
//            "                ██▓▓▒▒▒▒██                                                                  \n"
//            "              ▒▒▒▒▒▒▒▒▓▓                                                                    \n"
//            "            ██▓▓▒▒▒▒██                                                                      \n"
//            "          ██▒▒▒▒▒▒██                                                                        \n"
//            "        ██▓▓▒▒▒▒██                                                                          \n"
//            "      ██▓▓▒▒▒▒██                                                                            \n"
//            "    ▓▓▓▓▒▒▒▒▓▓                                                                              \n"
//            "  ██▓▓▒▒▒▒██                                                                                \n"
//            "    ██▒▒▓▓                                                                                  \n"
//            "      ██                                                                                    ";
//
//}

void Spear::setAbility() {

    string starting_part = "Reverts causality itself and always reaches target and deals " ;
    string damage_ability = to_string((rarity_enum + 1) * damage * 10);
    string ending_part = " points of " + element + " damage!";
    ability = starting_part + damage_ability + ending_part;
}
void Spear::setName() {
    item_name = rarity + " Spear of " + element;
}
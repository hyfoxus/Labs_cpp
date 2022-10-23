//
// Created by Gleb Nemirko on 14.10.2022.
//

#include "Weapon.h"

int Weapon::getStatPoints(Rarity rarity){
    switch (rarity) {
        case 0:
        {
            return 10;
        }
        case 1:
        {
            return 100;
        }
        case 2:
        {
            return 100;
        }
        case 3:
        {
            return 1000;
        }
        case 4:
        {
            return 10000;
        }
        default:
        {
            return 0;
        }
    }
}

void Weapon::setElement(Rarity rarity){
    int random_element = rand() % 4;
    if (rarity == 0) element = Element[rarity];
    else {
        int element_id = ((rarity - 1) * 4 + random_element - 1);
        element = Element[element_id];
    }

}

void Weapon::setStats(int place_durability, int place_damage, int place_speed, int stats_points){
    for (int i = 1; i <= 3; ++i) {
        if (place_damage == i && stats_points != 0) {
            damage = rand() % stats_points;
            stats_points -= damage;
            continue;
        }
        if (place_durability == i && stats_points != 0) {
            durability = rand() % stats_points;
            stats_points -= durability;
            continue;
        }
        if (place_speed == i && stats_points != 0) {
            speed = rand() % stats_points;
            stats_points -= speed;
            continue;
        }
    }
}

void Weapon::setRarity() {
    int random_rarity = rand() % 100;
    if (random_rarity < 40) rarity_enum = Weapon::Common;
    else if (random_rarity < 70) rarity_enum = Weapon::Uncommon;
    else if (random_rarity < 90) rarity_enum = Weapon::Rare;
    else if (random_rarity < 98) rarity_enum = Weapon::Epic;
    else rarity_enum = Weapon::Legendary;
    rarity = Rarity_string[rarity_enum];
}

void Weapon::setCost(Rarity rarity) {
    switch (rarity) {
        case 0:
        {
            cost = (rand() % 10) + 1;
            break;
        }
        case 1:
        {
            cost = (rand() % 100) + 10;
            break;
        }
        case 2:
        {
            cost = (rand() % 1000) + 100;
            break;
        }
        case 3:
        {
            cost = (rand() % 10000) + 1000;
            break;
        }
        case 4:
        {
            cost = (rand() % 100000) + 10000;
            break;
        }
        default:
        {
            cost = 0;
            break;
        }
    }
}
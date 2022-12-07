//
// Created by Gleb Nemirko on 21.11.2022.
//

#include "Head.h"

int Head::AttackTower() {
        int damage = 20 + rand() % 31;
        damage_dealt += damage;
        return damage;
}

int Head::getDamageDealt() {
    return damage_dealt;
}

int Head::getTarget() {
    return target;
}

void Head::setTarget(int target_id) {
    target = target_id;
}
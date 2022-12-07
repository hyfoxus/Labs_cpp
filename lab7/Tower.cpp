//
// Created by Gleb Nemirko on 21.11.2022.
//

#include "Tower.h"

using namespace std;

int Tower::Attack() {
    if (is_alive){
        int damage = 20 + rand() % 31;
        damage_dealt += damage;
        return damage;
    } else return 0;
}

void Tower::TakeDamage(int damage) {
    if (is_alive){
        if ((health_points - damage) >= 0){
            health_points -= damage;
        } else{
            health_points = 0;
            cout << "Tower has fallen!" << endl;
            is_alive = false;
        }
    }
}

int Tower::getDamageDealt() {
    return damage_dealt;
}

bool Tower::getState() {
    return is_alive;
}
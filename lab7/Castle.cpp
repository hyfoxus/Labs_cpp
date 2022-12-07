//
// Created by Gleb Nemirko on 21.11.2022.
//

#include "Castle.h"

void Castle::CheckTowers() {
    bool destroyed = true;
    for (int i = 0; i < towers.size(); ++i) {
        if ((towers.at(i).getState())) destroyed = false;
    }
    if (destroyed) {
        castle_destroyed = true;
        cout << "Castle has fallen!"<<endl;
    }
}

Tower Castle::getTower(int id) {
    if (id > 0 && id < towers.size())return towers.at(id);
    else return towers.at(id % towers.size());
}

int Castle::getSize() {
    return towers.size();
}

bool Castle::getState() {
    return castle_destroyed;
}
//
// Created by Gleb Nemirko on 09.12.2022.
//

#include "Figure.h"

int Figure::getMapY() {
    return map_y;
}

int Figure::getMapX() {
    return map_x;
}

Figure::Team Figure::getTeam() {
    return team;
}

void Figure::setAttacked(bool attack) {
    attacked = attack;
}

bool Figure::isAttacked() {
    return attacked;
}

char Figure::getSymbol() {
    return symbol;
}

void Figure::setMapY(int y) {
    map_y = y;
}

void Figure::setMapX(int x) {
    map_x = x;
}

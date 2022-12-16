//
// Created by Gleb Nemirko on 16.12.2022.
//

#include "Player.h"

void Player::setName(string username) {
    name = username;
}

void Player::setColor(string user_color) {
    color = user_color;
}

string Player::getName() {
    return name;
}

string Player::getColor() {
    return color;
}

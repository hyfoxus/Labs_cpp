//
// Created by Gleb Nemirko on 06.11.2022.
//

#include "Cat.h"

void Cat::laze_around(Cat partner) {
    if (is_free && partner.is_free) {
        fatigue += fatigue_per_hour_animal;
        is_free = false;
    }
}
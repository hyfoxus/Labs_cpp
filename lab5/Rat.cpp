//
// Created by Gleb Nemirko on 06.11.2022.
//

#include "Rat.h"


void Rat::fuck_around(Rat partner) {
    if (is_free && partner.is_free) {
        fatigue += fatigue_per_hour_animal;
        is_free = false;
    }
}
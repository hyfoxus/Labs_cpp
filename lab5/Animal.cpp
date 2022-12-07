//
// Created by Gleb Nemirko on 06.11.2022.
//

#include "Animal.h"

void Animal::play(float intensity) {
    fatigue += fatigue_per_hour_human;
    hunger += (int)(hunger_per_hour * intensity);
    if (hunger > 0) hunger -= 1;
}

void Animal::sleep() {
    fatigue = 0;
    is_asleep = true;
}

void Animal::wake() {
    if (hours_slept == sleep_time && hours_slept != 0){
        is_asleep = false;
        hours_slept = 0;
    }
}

bool Animal::needFood() {
    if (hunger > 60) return true;
    else return false;
}
bool Animal::needSleep() {
    if (fatigue > 80) return true;
    else return false;
}

void Animal::feed() {
    hunger = 0;
    is_fed = false;
}

void Animal::fed(int hours_passed){
    if (hours_passed > 0 && start_feed != 0){
        is_fed = true;
        start_feed = 0;
    }
}

void Animal::doneTheDeed() {
    is_free = true;
}

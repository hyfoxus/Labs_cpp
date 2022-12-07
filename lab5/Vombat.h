//
// Created by Gleb Nemirko on 06.11.2022.
//

#ifndef LAB1C___VOMBAT_H
#define LAB1C___VOMBAT_H


class Vombat: public Animal {
public:
    Vombat(string n, int a){
        name = n;
        age = a;
        sleep_time = 8;
        hunger_per_hour = 20;
        fatigue = 0;
        hunger = 0;
        fatigue_per_hour_human = 20;
        fatigue_per_hour_animal = 18;
        is_asleep = false;
        is_free = true;
        is_available = true;
        is_fed = true;
    }
    Vombat(){
        name = "NO_NAME";
        age = 5;
        sleep_time = 10;
        hunger_per_hour = 10;
        fatigue = 0;
        hunger = 0;
        fatigue_per_hour_human = 12;
        fatigue_per_hour_animal = 9;
        is_asleep = false;
        is_free = true;
        is_available = true;
        is_fed = true;
    }
/*
 * Действие, совершаемое животным
 *
 * @param partner - партнер действия
 */
    void shit_around(Vombat partner);
};


#endif //LAB1C___VOMBAT_H

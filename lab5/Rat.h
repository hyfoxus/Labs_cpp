//
// Created by Gleb Nemirko on 06.11.2022.
//

#ifndef LAB1C___RAT_H
#define LAB1C___RAT_H


class Rat: public Animal {
public:
    Rat(string n, int a){
        name = n;
        age = a;
        sleep_time = 5;
        hunger_per_hour = 3;
        fatigue = 0;
        hunger = 0;
        fatigue_per_hour_human = 15;
        fatigue_per_hour_animal = 12;
        is_asleep = false;
        is_free = true;
        is_available = true;
        is_fed = true;
    }
    Rat(){
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

    void fuck_around(Rat partner);
};


#endif //LAB1C___RAT_H

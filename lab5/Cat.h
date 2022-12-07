//
// Created by Gleb Nemirko on 06.11.2022.
//

#ifndef LAB1C___CAT_H
#define LAB1C___CAT_H
using namespace std;

class Cat : public Animal {
public:
    Cat(string n, int a){
        name = n;
        age = a;
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
    Cat(){
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
    void laze_around(Cat partner);



};


#endif //LAB1C___CAT_H

//
// Created by Gleb Nemirko on 06.11.2022.
//

#ifndef LAB1C___DOG_H
#define LAB1C___DOG_H


class Dog: public Animal {
public:
    Dog(string n, int a){
        name = n;
        age = a;
        sleep_time = 8;
        hunger_per_hour = 8;
        fatigue = 0;
        hunger = 0;
        fatigue_per_hour_human = 8;
        fatigue_per_hour_animal = 5;
        is_asleep = false;
        is_free = true;
        is_available = true;
        is_fed = true;
    }
    Dog(){
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
    void sex(Dog partner);
};


#endif //LAB1C___DOG_H

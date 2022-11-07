//
// Created by Gleb Nemirko on 06.11.2022.
//

#ifndef LAB1C___ANIMAL_H
#define LAB1C___ANIMAL_H

using namespace std;

class Animal {
public:
    string name;
    int age;

    void play(float intensity);
    void sleep();
    void wake(int hours_passed);
    bool needSleep();
    bool needFood();
    void doneTheDeed();
    void feed();
    void fed(int hours_passed);


    bool is_available;
    int hunger;
    int fatigue;
    int hunger_per_hour;
    int fatigue_per_hour_human;
    int fatigue_per_hour_animal;
    int sleep_time;
    bool is_asleep;
    int start_sleep;
    bool is_fed;
    int start_feed;
    bool is_free;
};


#endif //LAB1C___ANIMAL_H

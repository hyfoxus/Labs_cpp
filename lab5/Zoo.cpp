//
// Created by Gleb Nemirko on 07.11.2022.
//

#include "Zoo.h"
#include "Cat.h"
#include "Rat.h"
#include "Vombat.h"
#include "Dog.h"
//#include "Animal.cpp"
#include "Animal.h"
//#include "Cat.cpp"
#include "Rat.cpp"
#include "Vombat.cpp"
#include "Dog.cpp"

using namespace std;

void Zoo::fillZoo() {
    cout << "Cats" << endl;
    for (int i = 0; i < size; ++i) {
        string name;
        int age;
        cout << "Insert name:" << endl;
        cin >> name;
        cout << "Insert age:" << endl;
        cin >> age;
        Cat cat(name, age);
        aviary_cat[i] = cat;
    }
    cout << "Dogs" << endl;
    for (int i = 0; i < size; ++i) {
        string name;
        int age;
        cout << "Insert name:" << endl;
        cin >> name;
        cout << "Insert age:" << endl;
        cin >> age;
        Dog dog(name, age);
        aviary_dog[i] = dog;
    }
    cout << "Rats" << endl;
    for (int i = 0; i < size; ++i) {
        string name;
        int age;
        cout << "Insert name:" << endl;
        cin >> name;
        cout << "Insert age:" << endl;
        cin >> age;
        Rat rat(name, age);
        aviary_rat[i] = rat;
    }
    cout << "Vombats" << endl;
    for (int i = 0; i < size; ++i) {
        string name;
        int age;
        cout << "Insert name:" << endl;
        cin >> name;
        cout << "Insert age:" << endl;
        cin >> age;
        Vombat vombat(name, age);
        aviary_vombat[i] = vombat;
    }
}

void Zoo::checkCats() {
    for (int i = 0; i < size; ++i) {
        if (aviary_cat[i].is_available){
            if (aviary_cat[i].needSleep()) {
                aviary_cat[i].is_available = false;
                aviary_cat[i].sleep();
                cout << aviary_cat[i].name << " is asleep!" << endl;
            }
            if (aviary_cat[i].needFood()){
                aviary_cat[i].is_available = false;
                aviary_cat[i].feed();
                cout << aviary_cat[i].name << " gets food!" << endl;
                aviary_cat[i].start_feed  = 0;
            }
        } else {
            if (aviary_cat[i].is_asleep && aviary_cat[i].sleep_time == aviary_cat[i].hours_slept)
                aviary_cat[i].wake();
            else aviary_cat[i].hours_slept++;
            aviary_cat[i].fed(time - aviary_cat[i].start_feed);
            if (aviary_cat[i].is_fed && !(aviary_cat[i].is_asleep)) aviary_cat[i].is_available = true;
        }


    }
}
void Zoo::checkVombats() {
    for (int i = 0; i < size; ++i) {
        if (aviary_vombat[i].is_available){
            if ((aviary_vombat[i].needSleep())) {
                aviary_vombat[i].is_available = false;
                aviary_vombat[i].sleep();
                cout << aviary_vombat[i].name << " is asleep!" << endl;
            }
            if (aviary_vombat[i].needFood()){
                aviary_vombat[i].is_available = false;
                aviary_vombat[i].feed();
                cout << aviary_vombat[i].name << " gets food!" << endl;
                aviary_vombat[i].start_feed  = time;
            }
        } else {
            if (aviary_vombat[i].is_asleep && aviary_vombat[i].sleep_time == aviary_vombat[i].hours_slept)
                aviary_vombat[i].wake();
            else aviary_vombat[i].hours_slept++;
            aviary_vombat[i].fed(time - aviary_vombat[i].start_feed);
            if (aviary_vombat[i].is_fed && !(aviary_vombat[i].is_asleep)) aviary_vombat[i].is_available = true;
        }
    }
}
void Zoo::checkDogs() {
    for (int i = 0; i < size; ++i) {
        if (aviary_dog[i].is_available){
            if ((aviary_dog[i].needSleep())) {
                aviary_dog[i].is_available = false;
                aviary_dog[i].sleep();
                cout << aviary_dog[i].name << " is asleep!" << endl;
            }
            if (aviary_dog[i].needFood()){
                aviary_dog[i].is_available = false;
                aviary_dog[i].feed();
                cout << aviary_dog[i].name << " gets food!" << endl;
                aviary_dog[i].start_feed  = time;
            }
        } else {
            if (aviary_dog[i].is_asleep && aviary_dog[i].sleep_time == aviary_dog[i].hours_slept)
                aviary_dog[i].wake();
            else aviary_dog[i].hours_slept++;
            aviary_dog[i].fed(time - aviary_dog[i].start_feed);
            if (aviary_dog[i].is_fed && !(aviary_dog[i].is_asleep)) aviary_dog[i].is_available = true;
        }
    }
}
void Zoo::checkRats() {
    for (int i = 0; i < size; ++i) {
        if (aviary_rat[i].is_available){
            if ((aviary_rat[i].needSleep())) {
                aviary_rat[i].is_available = false;
                aviary_rat[i].sleep();
                cout << aviary_rat[i].name << " is asleep!" << endl;
            }
            if (aviary_rat[i].needFood()){
                aviary_rat[i].is_available = false;
                aviary_rat[i].feed();
                cout << aviary_rat[i].name << " gets food!" << endl;
                aviary_rat[i].start_feed  = time;
            }
        } else {
            if (aviary_rat[i].is_asleep && aviary_rat[i].sleep_time == aviary_rat[i].hours_slept)
                aviary_rat[i].wake();
            else aviary_rat[i].hours_slept++;
            aviary_rat[i].fed(time - aviary_rat[i].start_feed);
            if (aviary_rat[i].is_fed && !(aviary_rat[i].is_asleep)) aviary_rat[i].is_available = true;
        }
    }
}

void Zoo::activitiesCats() {
    for (int i = 0; i < size; ++i) {
        if (aviary_cat[i].is_available){
            if (aviary_cat[i].is_free){
                if ((rand() % 100) < 20) {
                    for (int j = 0; j < 5; ++j) {
                        if (aviary_cat[j].is_free && i != j) {
                            aviary_cat[i].laze_around(aviary_cat[j]);
                            cout << aviary_cat[i].name << " lazes around with " << aviary_cat[j].name << endl;
                            break;
                        }
                    }

                }
            }
        }
    }
}
void Zoo::activitiesDogs() {
    for (int i = 0; i < size; ++i) {
        if (aviary_dog[i].is_available){
            if (aviary_dog[i].is_free){
                if ((rand() % 100) < 20) {
                    for (int j = 0; j < 5; ++j) {
                        if (aviary_dog[j].is_free && i != j) {
                            aviary_dog[i].sex(aviary_dog[j]);
                            cout << aviary_dog[i].name << " has sex with " << aviary_dog[j].name << endl;
                            break;
                        }
                    }

                }
            }
        }
    }
}
void Zoo::activitiesVombats() {
    for (int i = 0; i < size; ++i) {
        if (aviary_vombat[i].is_available){
            if (aviary_vombat[i].is_free){
                if ((rand() % 100) < 20) {
                    for (int j = 0; j < 5; ++j) {
                        if (aviary_vombat[j].is_free && i != j) {
                            aviary_vombat[i].shit_around(aviary_vombat[j]);
                            cout << aviary_vombat[i].name << " shit around with " << aviary_vombat[j].name << endl;
                            break;
                        }
                    }

                }
            }
        }
    }
}
void Zoo::activitiesRats() {
    for (int i = 0; i < size; ++i) {
        if (aviary_rat[i].is_available){
            if (aviary_rat[i].is_free){
                if ((rand() % 100) < 20) {
                    for (int j = 0; j < 5; ++j) {
                        if (aviary_rat[j].is_free && i != j) {
                            aviary_rat[i].fuck_around(aviary_rat[j]);
                            cout << aviary_rat[i].name << " fucks around with " << aviary_rat[j].name << endl;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void Zoo::visitCats() {
    for (int i = 0; i < size; ++i) {
        if (aviary_cat[i].is_available){
            if (aviary_cat[i].is_free){
                aviary_cat[i].play(intensity_table[(time % 16)]);
                cout << aviary_cat[i].name << " gets pets!" << endl;
            }
        }
    }
}
void Zoo::visitVombats(){
    for (int i = 0; i < size; ++i) {
        if (aviary_vombat[i].is_available){
            if (aviary_vombat[i].is_free){
                aviary_vombat[i].play(intensity_table[(time % 16)]);
                cout << aviary_vombat[i].name << " gets pets!" << endl;
            }
        }
    }
}
void Zoo::visitDogs(){
    for (int i = 0; i < size; ++i) {
        if (aviary_dog[i].is_available){
            if (aviary_dog[i].is_free){
                aviary_dog[i].play(intensity_table[(time % 16)]);
                cout << aviary_dog[i].name << " gets pets!" << endl;
            }
        }
    }
}
void Zoo::visitRats(){
    for (int i = 0; i < size; ++i) {
        if (aviary_rat[i].is_available){
            if (aviary_rat[i].is_free){
                aviary_rat[i].play(intensity_table[(time % 16)]);
                cout << aviary_rat[i].name << " gets pets!" << endl;
            }
        }
    }
}

void Zoo::hourPassed() {
    checkCats();
    checkDogs();
    checkVombats();
    checkRats();

    activitiesCats();
    activitiesDogs();
    activitiesVombats();
    activitiesRats();


    visitCats();
    visitDogs();
    visitVombats();
    visitRats();

    for (int i = 0; i < size; ++i) {
        if (!aviary_cat[i].is_free) aviary_cat[i].doneTheDeed();
        if (!aviary_rat[i].is_free) aviary_rat[i].doneTheDeed();
        if (!aviary_dog[i].is_free) aviary_dog[i].doneTheDeed();
        if (!aviary_vombat[i].is_free) aviary_vombat[i].doneTheDeed();
    }

    time++;
}

void Zoo::dayPassed() {
    for (int i = 0; i < working_time; ++i) {
        hourPassed();
    }
    for (int i = 0; i < size; ++i) {
        aviary_cat[i].fatigue = 0;
        aviary_cat[i].hunger = 0;

        aviary_dog[i].fatigue = 0;
        aviary_dog[i].hunger = 0;

        aviary_vombat[i].fatigue = 0;
        aviary_vombat[i].hunger = 0;

        aviary_rat[i].fatigue = 0;
        aviary_rat[i].hunger = 0;
    }
}
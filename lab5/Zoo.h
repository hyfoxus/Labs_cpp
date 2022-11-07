//
// Created by Gleb Nemirko on 07.11.2022.
//

#ifndef LAB1C___ZOO_H
#define LAB1C___ZOO_H
#include "Cat.h"
#include "Rat.h"
#include "Vombat.h"
#include "Dog.h"

const int size = 5;

class Zoo {
public:
    Cat aviary_cat[size];
    Rat aviary_rat[size];
    Dog aviary_dog[size];
    Vombat aviary_vombat[size];

    float intensity_table[16] = {0.1, 0.15, 0.2, 0.3, 0.4, 0.5, 0.6, 0.9, 1, 0.8, 0.7, 0.6, 0.4, 0.3, 0.2, 0.1};

    int time;
    int working_time;

    Zoo(){
        time = 0;
        working_time = 16;
        fillZoo();
    }
    void fillZoo();

    void checkVombats();
    void checkCats();
    void checkRats();
    void checkDogs();

    void activitiesCats();
    void activitiesVombats();
    void activitiesDogs();
    void activitiesRats();

    void visitCats();
    void visitDogs();
    void visitVombats();
    void visitRats();

    void hourPassed();
    void dayPassed();
};


#endif //LAB1C___ZOO_H

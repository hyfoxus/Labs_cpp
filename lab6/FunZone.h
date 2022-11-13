//
// Created by Gleb Nemirko on 14.11.2022.
//

#ifndef LAB1C___FUNZONE_H
#define LAB1C___FUNZONE_H
#include "Pistol.h"
#include "Shotgun.h"
#include "Rifle.h"
#include "AssaultRifle.h"


using namespace std;
class FunZone {
public:
    int targets[6] = {2, 10, 50, 100, 500, 1000}; //Массив целей (Расстояний до них)

    Pistol pistol;
    Shotgun shotgun;
    Rifle rifle;
    AssaultRifle assaultRifle;

    double real_shot_per_min_pistol;
    double real_shot_per_min_rifle;
    double real_shot_per_min_shotgun;
    double real_shot_per_min_assaultRifle;

    int hit_pistol[6]; //массив количества попаданий по целям из разных оружий
    int hit_shotgun[6];
    int hit_rifle[6];
    int hit_assaultRifle[6];

    FunZone(){
        real_shot_per_min_pistol = 0;
        real_shot_per_min_rifle = 0;
        real_shot_per_min_shotgun = 0;
        real_shot_per_min_assaultRifle = 0;
        fill( hit_pistol, hit_pistol + sizeof( hit_pistol ), 0 );
        fill( hit_shotgun, hit_shotgun + sizeof( hit_shotgun ), 0 );
        fill( hit_rifle, hit_rifle + sizeof( hit_rifle ), 0 );
        fill( hit_assaultRifle, hit_assaultRifle + sizeof( hit_assaultRifle ), 0 );
    }
    // Группа Методов собирает данные по точности и рельной скорострельности, принимет сколько контрольных вытсрелов нужно сделать по цели
    void verifyPistol(int amount_of_shots);
    void verifyShotgun(int amount_of_shots);
    void verifyRifle(int amount_of_shots);
    void verifyAssaultRifle(int amount_of_shots);

    void showStats(); //метод показывает собранную статистику
};


#endif //LAB1C___FUNZONE_H

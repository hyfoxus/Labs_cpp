//
// Created by Gleb Nemirko on 13.11.2022.
//

#ifndef LAB1C___WEAPON_H
#define LAB1C___WEAPON_H

using namespace std;
class Weapon {
public:
    int bullets_in_mag;
    int bullets_max;
    string calibre;
    int modes_amount;
    double mass;
    int accurate_distance;
    int reload_time;
    int rounds_per_second;

    virtual int reload(int bullets) = 0;

    virtual int shoot(double distance) = 0;

    virtual void showCharacteristics();
};


#endif //LAB1C___WEAPON_H

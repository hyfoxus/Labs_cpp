//
// Created by Gleb Nemirko on 13.11.2022.
//

#ifndef LAB1C___WEAPON_H
#define LAB1C___WEAPON_H

using namespace std;
class Weapon {
public:
    int bullets_in_mag; // Пули в магазине
    int bullets_max; // Максимум пуль в магазине
    string calibre;
    int modes_amount;
    double mass;
    int accurate_distance;
    int reload_time; // сколько времени занимает сунуть один предмет в оружик
    int rounds_per_second;

    virtual int reload(int bullets) = 0; // Чистый Виртульный класс перезарядки, принимает сколько пуль дали для перезарядки и возвращает время протраченно ена перезарядку

    virtual int shoot(double distance) = 0; // Чистый Виртульный класс стрельбыб принимает дистанцию для цели и выдает сколько попало пуль за единицу времени

    virtual void showCharacteristics(); //Виртуальный класс, показывает характеристики оружия
};


#endif //LAB1C___WEAPON_H

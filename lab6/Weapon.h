//
// Created by Gleb Nemirko on 13.11.2022.
//

#ifndef LAB1C___WEAPON_H
#define LAB1C___WEAPON_H

using namespace std;

/*
 * Класс Оружие
 *
 * @param bullets_in_mag - Пули в магазине
 * @param bullets_max - Максимум пуль в магазине
 * @param calibre - Калибр
 * @param modes_amount - Количество режимов
 * @param mass - Масса
 * @param accurate_distance - Дистанция точности
 * @param reload_time - сколько времени занимает сунуть один предмет в оружик
 * @param rounds_per_second - Скорострельность
 */


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
/*
 * Чистый Виртульный класс перезарядки, принимает сколько пуль дали для перезарядки и возвращает время протраченно ена перезарядку
 *
 * @param bullets Количество выданных пуль.
 * @return время потраченное на перезарядку
 */
    virtual int reload(int bullets) = 0;
/*
 * Чистый Виртульный класс стрельбыб принимает дистанцию для цели и выдает сколько попало пуль за единицу времени
 *
 * @param distance Растояние до цели
 * @return Число попаданий
 */
    virtual int shoot(double distance) = 0;
/*
 * Виртуальный класс, показывает характеристики оружия
 */
    virtual void showCharacteristics(); //
};


#endif //LAB1C___WEAPON_H

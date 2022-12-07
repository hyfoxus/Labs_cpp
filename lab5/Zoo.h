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

/*
 * Класс Зоопарк
 *
 * @param aviary_cat - Массмв кошек
 * @param aviary_rat - Массмв Крыс
 * @param aviary_dog - Массмв Собак
 * @param aviary_vombat - Массмв Вомбатов
 * @param intensity_table - Статистика по интенсиваности занятости зоопарка
 * @param time - Время
 * @param working_time - Сколько часов в день работает
 * @param real_shot_per_min_shotgun - Реальная скорострельность дробовик
 * @param real_shot_per_min_assaultRifle - Реальная скорострельность автомата
 * @param hit_pistol - массив кол-ва попаданий по разным целям Пистолета
 * @param hit_rifle - массив кол-ва попаданий по разным целям Винтовки
 * @param hit_shotgun - массив кол-ва попаданий по разным целям Дробовика
 * @param hit_assaultRifle - массив кол-ва попаданий по разным целям Автомата
 */

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
/*
 * Заполнение зоопарка
 *
 */
    void fillZoo();
/*
 * Проверить Вомбатов
 *
 */
    void checkVombats();
/*
 * Проверить Кошек
 *
 */
    void checkCats();
/*
 * Проверить крыс
 *
 */
    void checkRats();
/*
 * Проверить собак
 *
 */
    void checkDogs();
/*
 * Кошки ролляют занятость
 *
 */
    void activitiesCats();
/*
 * Вомбаты ролляют занятость
 *
 */
    void activitiesVombats();
/*
 * Собаки ролляют занятость
 *
 */
    void activitiesDogs();
/*
 * Крысы ролляют занятость
 *
 */
    void activitiesRats();
/*
 * Кошек посещяют посетители
 *
 */
    void visitCats();
/*
 * Собак посещяют посетители
 *
 */
    void visitDogs();
/*
 * Вомбатов посещяют посетители
 *
 */
    void visitVombats();
/*
 * Крыс посещяют посетители
 *
 */
    void visitRats();
/*
 * Имитация прошедшего часа
 *
 */
    void hourPassed();
/*
 * Имитация прошедшего дня
 *
 */
    void dayPassed();
};


#endif //LAB1C___ZOO_H

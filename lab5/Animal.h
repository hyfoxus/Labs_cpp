//
// Created by Gleb Nemirko on 06.11.2022.
//

#ifndef LAB1C___ANIMAL_H
#define LAB1C___ANIMAL_H

using namespace std;
/*
 * Класс Стрельбище
 *
 * @param name - имя
 * @param age - Возраст
 * @param hours_slept - Скролько часов проспал
 * @param is_available - Доступность
 * @param hunger - Степень голода
 * @param fatigue - Степень усталости
 * @param hunger_per_hour - Скорочть набирания голода
 * @param fatigue_per_hour_human - Скорочть набирания усталости с человеком
 * @param fatigue_per_hour_animal - Скорочть набирания голода с животным
 * @param sleep_time - Необходимое время для сна
 * @param is_asleep - Состояние пробуждения
 * @param is_fed -  Состояние кормления
 * @param start_feed - Начало времени кормления
 * @param is_free - Состояние свободы
};
 */

class Animal {
public:
    string name;
    int age;
/*
 * Метод "Играть"
 * @param intensity На сколько занятыйчас
 */
    void play(float intensity);
/*
 * Метод "Спать"
 */
    void sleep();
/*
 * Метод "Проснуться"
 * @param hours_passed Сколько времени прошло
 */
    void wake();
/*
 * Метод Проверки усталости
 */
    bool needSleep();
/*
 * Метод Проверки голода
 */
    bool needFood();

/*
 * Метод проверки закончил ли с актвиностью животное
 */
    void doneTheDeed();
/*
 * Метод "Кормиться"
 */
    void feed();
/*
 * Метод "кормить"
 * @param hours_passed Сколько времени уже кормят
 */
    void fed(int hours_passed);


    int hours_slept;
    bool is_available;
    int hunger;
    int fatigue;
    int hunger_per_hour;
    int fatigue_per_hour_human;
    int fatigue_per_hour_animal;
    int sleep_time;
    bool is_asleep;
    bool is_fed;
    int start_feed;
    bool is_free;
};


#endif //LAB1C___ANIMAL_H

//
// Created by Gleb Nemirko on 21.11.2022.
//

#ifndef LAB1C___DRAGON_H
#define LAB1C___DRAGON_H

#include "Head.h"
#include "Castle.cpp"
#include <vector>
#include "Castle.h"

/*
 * Класс Голова
 *
 * @param heads - Массив голов
 * @param health_points - Кол-во очков жизни
 * @param is_alive - Состояние жизни
 * @param random_strategy - Какая стратеги (True - случайная/ False - Логичная)
 * @param target_castle - Аттакуемый замок
 */

class Dragon {
public:

    Head heads[3];
    int health_points;
    bool is_alive;
    bool random_strategy;
    Castle target_castle;


    Dragon(bool is_random, int size)  {
        for (int i = 0; i < 3; ++i) {
            Head head;
            heads[i] = head;
        }
        health_points = 1000;
        is_alive = true;
        random_strategy = is_random;
        Castle targetCastle(size);
        target_castle = targetCastle;
    }

    Dragon()  {
        for (int i = 0; i < 3; ++i) {
            Head head;
            heads[i] = head;
        }
        health_points = 1000;
        is_alive = true;
        random_strategy = false;
        Castle targetCastle;
        target_castle = targetCastle;
    }
/*
 * Получения урона
 *
 * @param damage полученный урон.
 */
    void TakeDamage(int damage);
/*
 * Атака замка
 */
    void AttackCastle();
/*
 * Получения статистики
 */
    void showStats();

};


#endif //LAB1C___DRAGON_H

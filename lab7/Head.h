//
// Created by Gleb Nemirko on 21.11.2022.
//

#ifndef LAB1C___HEAD_H
#define LAB1C___HEAD_H

/*
 * Класс Голова
 *
 * @param target - Цель атаки
 * @param damage_dealt - Нанесенный урон
 */

class Head {
private:
    int target;
    int damage_dealt;


public:
    Head(){
        damage_dealt = 0;
    }
/*
 * Генерация нанесенного урона
 *
 * @return урон по башне.
 */
    int AttackTower();
/*
 * Получения нанесеного урона
 *
 * @return возвращает нанесенный урон.
 */
    int getDamageDealt();
/*
 * Получения цели
 *
 * @return возвращает id цели.
 */
    int getTarget();
/*
 * Присвоение цели
 *
 * @param target_id id цели.
 */
    void setTarget(int target_id);
};


#endif //LAB1C___HEAD_H

//
// Created by Gleb Nemirko on 21.11.2022.
//

#ifndef LAB1C___TOWER_H
#define LAB1C___TOWER_H


/*
 * Класс Голова
 *
 * @param health_points - Количество очков жизни
 * @param is_alive - состояние жизни
 * @param damage_dealt - Нанесенный урон
 */

class Tower {
private:
    int health_points;
    bool is_alive;
    int damage_dealt;
public:
    Tower(){
        health_points = 100;
        is_alive = true;
        damage_dealt = 0;
    }
/*
 * Получения урона
 *
 * @param damage полученный урон.
 */
    void TakeDamage(int damage);
/*
 * Атака Дракона
 *
 * @return возвращает урон.
 */
    int Attack();
/*
 * Получения состояние
 *
 * @return возвращает состояния.
 */
    bool getState();
/*
 * Получения нанесеного урона
 *
 * @return возвращает нанесенный урон.
 */
    int getDamageDealt();
};


#endif //LAB1C___TOWER_H

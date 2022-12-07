//
// Created by Gleb Nemirko on 21.11.2022.
//

#ifndef LAB1C___CASTLE_H
#define LAB1C___CASTLE_H


#include <vector>
#include "Tower.h"


using namespace std;

/*
 * Класс Голова
 *
 * @param castle_destroyed - Состояние замка
 * @param towers - Массив башен
 */

class Castle {
private:


    bool castle_destroyed;

    vector<Tower> towers;


public:
/*
 * Проверка состояния Замка
 */
    void CheckTowers();
/*
 * Получения башни
 *
 * @param id id желаемой башни.
 * @return возвращает башню.
 */
    Tower getTower(int id);
/*
 * Получения размера
 *
 * @return возвращает размер замка.
 */
    int getSize();
/*
 * Получения Состояния
 *
 * @return возвращает состояния.
 */
    bool getState();

    Castle(int castle_size){
        castle_destroyed = false;
        for (int i = 0; i < castle_size; ++i) {
            Tower tower;
            towers.push_back(tower);
        }
    }
    Castle(){
        castle_destroyed = false;
        for (int i = 0; i < 6; ++i) {
            Tower tower;
            towers.push_back(tower);
        }
    }
};


#endif //LAB1C___CASTLE_H

//
// Created by Gleb Nemirko on 14.11.2022.
//

#ifndef LAB1C___FUNZONE_H
#define LAB1C___FUNZONE_H
#include "Pistol.h"
#include "Shotgun.h"
#include "Rifle.h"
#include "AssaultRifle.h"

/*
 * Класс Стрельбище
 *
 * @param targets - Массмв целей
 * @param pistol - Проверяемый пистолет
 * @param shotgun - Проверяемый дробовик
 * @param rifle - Проверяемый винтовка
 * @param assaultRifle - Проверяемый автомат
 * @param real_shot_per_min_pistol - Реальная скорострельность пистолет
 * @param real_shot_per_min_rifle - Реальная скорострельность винтовка
 * @param real_shot_per_min_shotgun - Реальная скорострельность дробовик
 * @param real_shot_per_min_assaultRifle - Реальная скорострельность автомата
 * @param hit_pistol - массив кол-ва попаданий по разным целям Пистолета
 * @param hit_rifle - массив кол-ва попаданий по разным целям Винтовки
 * @param hit_shotgun - массив кол-ва попаданий по разным целям Дробовика
 * @param hit_assaultRifle - массив кол-ва попаданий по разным целям Автомата
 */
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

/*
 * Метод собирает данные по точности и рельной скорострельности пистолета, принимет сколько контрольных вытсрелов нужно сделать по цели
 *
 * @param amount_of_shots Количество вытрелов для проверки.
 */
    void verifyPistol(int amount_of_shots);
/*
 * Метод собирает данные по точности и рельной скорострельности дробовика, принимет сколько контрольных вытсрелов нужно сделать по цели
 *
 * @param amount_of_shots Количество вытрелов для проверки.
 */
    void verifyShotgun(int amount_of_shots);
/*
 * Метод собирает данные по точности и рельной скорострельности Винтовки, принимет сколько контрольных вытсрелов нужно сделать по цели
 *
 * @param amount_of_shots Количество вытрелов для проверки.
 */
    void verifyRifle(int amount_of_shots);
/*
 * Метод собирает данные по точности и рельной скорострельности Штурмовой винтовки, принимет сколько контрольных вытсрелов нужно сделать по цели
 *
 * @param amount_of_shots Количество вытрелов для проверки.
 */
    void verifyAssaultRifle(int amount_of_shots);
/*
 * Метод показывает собранную статистику

 */
    void showStats();
};


#endif //LAB1C___FUNZONE_H

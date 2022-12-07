//
// Created by Gleb Nemirko on 14.10.2022.
//

#ifndef LAB1C___WEAPON_H
#define LAB1C___WEAPON_H
using namespace std;


class Weapon {
public:
    enum Rarity { Common, Uncommon, Rare, Epic, Legendary };
    string Rarity_string[5] = { "Common", "Uncommon", "Rare", "Epic", "Legendary" };
    string rarity;
    int durability;
    int damage;
    int speed;
    int cost;
    enum WeaponType {Bow, Spear, Sword};
    WeaponType weaponType;
    string image;
    string ability;
    string item_name;

    string Element[17] = { "Neutral" ,  //for common weapons
            "Fire", "Water", "Wind", "Earth", // uncommon elements
            "Lightning", "Blood", "Ice", "Poison",  // rare elements
            "Light", "Spirit", "Darkness", "Gravity", // Epic elements
            "Energy", "Time", "Space", "Force" }; //Legendary Elements

    string element;
/*
 * Получение количества очков характеристик в зависимости от редкости
 *
 * @param rarity Редкость - из списка Rarity
 * @return возвращает кол-во очков.
 */
    int getStatPoints(Rarity rarity);
/*
 * Генерирует элемент в зависимости от редкости
 * @param rarity Редкость - из списка Rarity
 */
    void setElement(Rarity rarity);
/*
 * Генерирует редкость
 */
    void setRarity();
/*
 * Генерирует стоимость в зависимости от редкости
 */
    void setCost(Rarity rarity);
/*
 * Генерирует значения характеристик
 * @param place_durability На каком месте в очереди будет сгенерирована прочность
 * @param place_damage На каком месте в очереди будет сгенерирован урон
 * @param place_speed На каком месте в очереди будет сгенерирована скорость
 * @param stats_points Количество очков характеристик
 *
 */
    void setStats(int place_durability, int place_damage, int place_speed, int stats_points);

    Rarity rarity_enum;
};


#endif //LAB1C___WEAPON_H

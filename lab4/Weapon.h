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
    int durability = 0;
    int damage = 0;
    int speed = 0;
    int cost;
    enum WeaponType {Bow, Spear, Sword};
    WeaponType weaponType;
    //string image;
    string ability;
    string item_name;

    string Element[17] = { "Neutral" ,  //for common weapons
            "Fire", "Water", "Wind", "Earth", // uncommon elements
            "Lightning", "Blood", "Ice", "Poison",  // rare elements
            "Light", "Spirit", "Darkness", "Gravity", // Epic elements
            "Energy", "Time", "Space", "Force" }; //Legendary Elements

    string element;

    int getStatPoints(Rarity rarity);

    void setElement(Rarity rarity);

    void setRarity();

    void setCost(Rarity rarity);

    void setStats(int place_durability, int place_damage, int place_speed, int stats_points);

    Rarity rarity_enum;
};


#endif //LAB1C___WEAPON_H

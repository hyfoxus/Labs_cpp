//
// Created by Gleb Nemirko on 23.10.2022.
//

#ifndef LAB1C___SWORD_H
#define LAB1C___SWORD_H

using namespace std;

class Sword : public Weapon {
public:
    Sword(){
        setRarity();
        setElement(rarity_enum);
        setCost(rarity_enum);
        setStats(1, 3, 2, getStatPoints(rarity_enum)); // durability -> speed -> damage
        setName();
        setImage();
        setAbility();
        weaponType = Weapon::Sword;
    }

    Sword(Rarity get_rarity){
        rarity_enum = get_rarity;
        rarity = Rarity_string[get_rarity];
        setElement(rarity_enum);
        setCost(rarity_enum);
        setStats(2, 1, 3, getStatPoints(rarity_enum)); // damage -> durability -> damage
        setName();
        setImage();
        setAbility();
        weaponType = Weapon::Sword;
    }

/*
 * Генериция имени
 */
    void setName();
/*
 * Генериция текстовой картинки
 */
    void setImage();
/*
 * Генериция способности
 */
    void setAbility();
};
};


#endif //LAB1C___SWORD_H

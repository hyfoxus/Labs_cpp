//
// Created by Gleb Nemirko on 23.10.2022.
//

#ifndef LAB1C___BOW_H
#define LAB1C___BOW_H

using namespace std;

class Bow : public Weapon {
public:

    Bow(){
        setRarity();
        setElement(rarity_enum);
        setCost(rarity_enum);
        setStats(3, 2, 1, getStatPoints(rarity_enum));
        setName();
        //setImage();
        setAbility();
        weaponType = Weapon::Bow;
    }

    Bow(Rarity get_rarity){
        rarity_enum = get_rarity;
        rarity = Rarity_string[get_rarity];
        setElement(rarity_enum);
        setCost(rarity_enum);
        setStats(2, 1, 3, getStatPoints(rarity_enum)); // damage -> durability -> damage
        setName();
        //setImage();
        setAbility();
        weaponType = Weapon::Bow;
    }
    void setName();
    void setImage();
    void setAbility();
};


#endif //LAB1C___BOW_H

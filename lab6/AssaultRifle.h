//
// Created by Gleb Nemirko on 13.11.2022.
//

#ifndef LAB1C___ASSAULTRIFLE_H
#define LAB1C___ASSAULTRIFLE_H


class AssaultRifle: public Pistol {
public:
    int amount_upgrades;
    void showCharacteristics() override{
        cout << "Mag Size: " << bullets_max << endl;
        cout << "Calibre: " << calibre << endl;
        cout << "modes_amount: " << modes_amount << endl;
        cout << "Mass:  " << mass << endl;
        cout << "Accurate distance: " << accurate_distance << endl;
        cout << "Insert during reload time: " << reload_time << endl;
        cout << "Rounds per second (At least should be): " << rounds_per_second << endl;
        cout << "Amount of upgrades: " << amount_upgrades << endl;
    }

    AssaultRifle(){
        bullets_max = 30;
        bullets_in_mag = bullets_max;
        calibre = "5.56 mm";
        modes_amount = 3;
        mass = 3;
        accurate_distance = 200;
        reload_time = 8;
        rounds_per_second = 15;
        amount_upgrades = 9999;

    }
};


#endif //LAB1C___ASSAULTRIFLE_H

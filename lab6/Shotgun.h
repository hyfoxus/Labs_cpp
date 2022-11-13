//
// Created by Gleb Nemirko on 13.11.2022.
//

#ifndef LAB1C___SHOTGUN_H
#define LAB1C___SHOTGUN_H


class Shotgun: public Weapon {

public:
    int reload(int bullets) override {
    int time = 0;
        for (int i = 0; i < bullets; ++i) {
            if (bullets_in_mag < bullets_max) {
                bullets_in_mag += 1;
                time += reload_time;
            }
            else break;
        }
        return time;
    }

    int shoot(double distance) override{
        int success_shots = 0;
        float chance_success;
        if (distance >= accurate_distance){
            chance_success = 1/(pow(M_E, ((distance/accurate_distance) - 1)));
        } else chance_success = 1;

        for (int i = 0; i < rounds_per_second; ++i) {
            int roll = rand() % 100000;
            if (bullets_in_mag != 0){
                if (roll <= chance_success * 100000) {
                    success_shots++;

                }
                bullets_in_mag--;
            } else break;
        }
        return success_shots;
    }

    string crowd_shots;

    void showCharacteristics() override{
        cout << "Mag Size: " << bullets_max << endl;
        cout << "Calibre: " << calibre << endl;
        cout << "modes_amount: " << modes_amount << endl;
        cout << "Mass:  " << mass << endl;
        cout << "Accurate distance: " << accurate_distance << endl;
        cout << "Insert during reload time: " << reload_time << endl;
        cout << "Rounds per second (At least should be): " << rounds_per_second << endl;
        cout << "How good in trenches: " << crowd_shots << endl;
    }
    Shotgun(){
        bullets_max = 8;
        bullets_in_mag = bullets_max;
        calibre = "shotgun one";
        modes_amount = 1;
        mass = 2;
        accurate_distance = 5;
        reload_time = 1;
        rounds_per_second = 2;
        crowd_shots = "Yes.";
    }
};


#endif //LAB1C___SHOTGUN_H

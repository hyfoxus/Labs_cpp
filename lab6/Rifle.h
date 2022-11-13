//
// Created by Gleb Nemirko on 13.11.2022.
//

#ifndef LAB1C___RIFLE_H
#define LAB1C___RIFLE_H


class Rifle: public Weapon {
public:
    int reload(int bullets) override {
        bullets_in_mag++;
        return reload_time;
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

    Rifle(){
        bullets_max = 1;
        bullets_in_mag = bullets_max;
        calibre = "7.62 mm";
        modes_amount = 1;
        mass = 2;
        accurate_distance = 400;
        reload_time = 2;
        rounds_per_second = 1;
    }
};


#endif //LAB1C___RIFLE_H

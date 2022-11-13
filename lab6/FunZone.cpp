//
// Created by Gleb Nemirko on 14.11.2022.
//

#include "FunZone.h"
#include "Pistol.h"
#include "Shotgun.h"
#include "Rifle.h"
#include "AssaultRifle.h"

const int amount_of_targets = 6;

void FunZone::verifyPistol(int amount_of_shots) {

    cout << "Pistol:" << endl;
    pistol.showCharacteristics();

    int time = 0;
    for (int i = 0; i < amount_of_targets; ++i) {
        pistol.bullets_in_mag = pistol.bullets_max;
        for (int j = 0; j < amount_of_shots; ) {
            int start_of_second_mag = 0;
            start_of_second_mag = pistol.bullets_in_mag;
            hit_pistol[i] += pistol.shoot(targets[i]);
            time++;
            j += (start_of_second_mag - pistol.bullets_in_mag);
            if (j >= amount_of_shots) hit_pistol[i] -=  j - amount_of_shots;
            if (hit_pistol[i] < 0) hit_pistol[i] = 0;
            if (pistol.bullets_in_mag == 0) time += pistol.reload(pistol.bullets_max);
        }
    }
    real_shot_per_min_pistol = ((amount_of_shots * amount_of_targets) / time) * 60;
}
void FunZone::verifyShotgun(int amount_of_shots) {
    cout << "Shotgun:" << endl;

    shotgun.showCharacteristics();

    int time = 0;
    for (int i = 0; i < amount_of_targets; ++i) {
        shotgun.bullets_in_mag = shotgun.bullets_max;
        for (int j = 0; j < amount_of_shots; ) {
            int start_of_second_mag = shotgun.bullets_in_mag;
            hit_shotgun[i] += shotgun.shoot(targets[i]);
            time++;
            j += (start_of_second_mag -  shotgun.bullets_in_mag);
            if (j >= amount_of_shots) hit_shotgun[i] -= j - amount_of_shots;
            if (hit_shotgun[i] < 0) hit_shotgun[i] = 0;
            if (shotgun.bullets_in_mag == 0) time += shotgun.reload(shotgun.bullets_max);
        }
    }
    real_shot_per_min_shotgun = ((amount_of_shots * amount_of_targets) / time) * 60;
}
void FunZone::verifyRifle(int amount_of_shots) {
    cout << "Rifle:" << endl;

    rifle.showCharacteristics();


    int time = 0;
    for (int i = 0; i < amount_of_targets; ++i) {
        rifle.bullets_in_mag = rifle.bullets_max;
        for (int j = 0; j < amount_of_shots; ) {
            int start_of_second_mag = rifle.bullets_in_mag;
            hit_rifle[i] += rifle.shoot(targets[i]);
            time++;
            j += (start_of_second_mag - rifle.bullets_in_mag);
            if (j >= amount_of_shots) hit_rifle[i] -= j - amount_of_shots;
            if (hit_rifle[i] < 0) hit_rifle[i] = 0;
            if (rifle.bullets_in_mag == 0) time += rifle.reload(rifle.bullets_max);
        }
    }
    real_shot_per_min_rifle = ((amount_of_shots * amount_of_targets) / time) * 60;
}
void FunZone::verifyAssaultRifle(int amount_of_shots) {

    cout << "Assault Rifle:" << endl;
    assaultRifle.showCharacteristics();

    int time = 0;
    for (int i = 0; i < amount_of_targets; ++i) {
        assaultRifle.bullets_in_mag = assaultRifle.bullets_max;
        for (int j = 0; j < amount_of_shots; ) {
            int start_of_second_mag = assaultRifle.bullets_in_mag;
            hit_assaultRifle[i] += assaultRifle.shoot(targets[i]);
            time++;
            j += (start_of_second_mag - assaultRifle.bullets_in_mag);
            if (j >= amount_of_shots) hit_assaultRifle[i] -= j - amount_of_shots;
            if (hit_assaultRifle[i] < 0) hit_assaultRifle[i] = 0;
            if (assaultRifle.bullets_in_mag == 0) time += assaultRifle.reload(assaultRifle.bullets_max);
        }
    }
    real_shot_per_min_assaultRifle = ((amount_of_shots * amount_of_targets) / time) * 60;
}

void FunZone::showStats() {
    cout << "Pistol:" << endl;
    cout << "Real rate of fire (RPM): " << real_shot_per_min_pistol << endl;
    for (int i = 0; i < amount_of_targets; ++i) {
        cout << "Hit target on distance: " << targets[i] << " metres " << hit_pistol[i] << " times"<< endl;
    }

    cout << "Shotgun:" << endl;
    cout << "Real rate of fire (RPM): " << real_shot_per_min_shotgun << endl;
    for (int i = 0; i < amount_of_targets; ++i) {
        cout << "Hit target on distance: " << targets[i] << " metres " << hit_shotgun[i] << " times"<< endl;
    }

    cout << "Rifle:" << endl;
    cout << "Real rate of fire (RPM): " << real_shot_per_min_rifle << endl;
    for (int i = 0; i < amount_of_targets; ++i) {
        cout << "Hit target on distance: " << targets[i] << " metres " << hit_rifle[i] << " times"<< endl;
    }

    cout << "Assault Rifle:" << endl;
    cout << "Real rate of fire (RPM): " << real_shot_per_min_assaultRifle << endl;
    for (int i = 0; i < amount_of_targets; ++i) {
        cout << "Hit target on distance: " << targets[i] << " metres " << hit_assaultRifle[i] << " times"<< endl;
    }
}
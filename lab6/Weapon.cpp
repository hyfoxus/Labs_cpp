//
// Created by Gleb Nemirko on 13.11.2022.
//

#include "Weapon.h"

using namespace std;
void Weapon::showCharacteristics() {
    cout << "Mag Size: " << bullets_max << endl;
    cout << "Calibre: " << calibre << endl;
    cout << "modes_amount: " << modes_amount << endl;
    cout << "Mass:  " << mass << endl;
    cout << "Accurate distance: " << accurate_distance << endl;
    cout << "Insert during reload time: " << reload_time << endl;
    cout << "Rounds per second (At least should be): " << rounds_per_second << endl;
    cout << endl;
    cout << endl;
}

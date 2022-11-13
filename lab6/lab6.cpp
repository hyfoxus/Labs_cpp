#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Weapon.cpp"

#include <cmath>
#include "FunZone.h"
#include "FunZone.cpp"

using namespace std;

int main() {
    srand(time(NULL));

    FunZone funZone;

    funZone.verifyPistol(100);
    funZone.verifyRifle(100);
    funZone.verifyShotgun(100);
    funZone.verifyAssaultRifle(100);

    funZone.showStats();
    return 0;
}

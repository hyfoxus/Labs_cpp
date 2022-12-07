#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Castle.h"

#include "Dragon.h"
#include "Dragon.cpp"



using namespace std;


int main() {
    srand(time(NULL));
    int castle_size;
    cin >> castle_size;
    Castle castle(castle_size);

    Dragon dragon(false, castle_size);

    

    dragon.AttackCastle();
    dragon.showStats();


    return 0;
}
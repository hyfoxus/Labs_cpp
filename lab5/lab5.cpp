#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Animal.h"
#include "Cat.h"
#include "Cat.cpp"
#include "Animal.cpp"
#include "Zoo.h"
#include "Zoo.cpp"


int main() {
    Zoo zoo;
    for (int i = 0; i < 30; ++i) {
        zoo.dayPassed();
    }
    return 0;
}

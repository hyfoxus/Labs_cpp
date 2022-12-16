//
// Created by Gleb Nemirko on 04.12.2022.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>
#include "User.h"
#include "User.cpp"
using namespace std;

User f(){
    User user(rand() % 10, rand() % 10, rand() % 10, 10 + rand() % 91);
    return user;
}


ostream& operator << (ostream& out, vector<User> users){
    for (int i = 0; i < users.size(); ++i) {
        users.at(i).print();
    }
}


int main() {
    srand(time(NULL));

    vector<User> users(10);

    generate(users.begin(), users.end(), f);

    for (int i = 0; i < 10; ++i) {
        users.at(i).print();
    }

    

    for (int i = 0; i < 10; ++i) {
        users.at(i).print();
    }
    return 0;
}

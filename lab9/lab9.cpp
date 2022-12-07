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
    User user(1, 1, 1, 10);
    return user;
}


ostream& operator << (ostream& out, User user){
    cout << "Fullname: " << user.getFullname() << endl;
    cout << "Age: " << user.getAge() << endl;
    cout << "Login: " << user.getLogin() << endl;
    cout << "Password: " << user.getPassword() << endl;
    if (user.getActivity()) cout << "Activity: Online" << endl;
    else cout << "Activity: Offline" << endl;
}

//void generate_n(vector<User*>& users, int size){
//    random_device r;
//    mt19937 engine(r());
//    uniform_int_distribution<> ind(0, 10);
//    uniform_int_distribution<int> ind_age(10, 100);
//
//    for (int i = 0; i < size; ++i) {
//        int a = ind(engine);
//        int b = ind(engine);
//        int c = ind(engine);
//        int age = ind_age(engine);
//
//        User user(a, b, c, age);
//
//        users.push_back(&user);
//
//    }
//}

int main() {
    srand(time(NULL));

    vector<User> users;
    //users.reserve(10);
    //generate_n(users, 10);

    generate_n(users.begin(), 10, f);
    vector<User> users2;

    User user(1, 1, 1, 10);

    //users2.push_back(user);


    for (int i = 0; i < 10; ++i) {
        cout << users.at(i) << endl;
    }

    return 0;
}

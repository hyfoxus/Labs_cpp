//
// Created by Gleb Nemirko on 16.12.2022.
//

#ifndef LAB1C___PLAYER_H
#define LAB1C___PLAYER_H
#include <string>

class Player {
private:
    string name;
    string color;
public:
    void setName(string username);
    void setColor(string user_color);
    string getName();
    string getColor();
};


#endif //LAB1C___PLAYER_H

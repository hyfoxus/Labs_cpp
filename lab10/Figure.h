//
// Created by Gleb Nemirko on 09.12.2022.
//

#ifndef LAB1C___FIGURE_H
#define LAB1C___FIGURE_H

#include <utility>
#include <vector>
#include <string>


using namespace std;

const int N = 8;

class Figure {
protected:

    enum class Team {snowflake, nigger};
    Team team;
    bool isAlive;
    bool attacked;
    char symbol;
    int map_y;
    int map_x;
    string figure_type;

public:
    vector<pair<int, int>> possible_ways;

    virtual void checkAllPossibleMoves(char(*chess_map)[N]) = 0;

    virtual void canAttack(char(*chess_map)[N], Figure* figure) = 0;

    int getMapY();
    int getMapX();
    Team getTeam();
    void setAttacked(bool attack);
    bool isAttacked();
    char getSymbol();
    void setMapY(int y);
    void setMapX(int x);
};


#endif //LAB1C___FIGURE_H

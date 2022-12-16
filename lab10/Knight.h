//
// Created by Gleb Nemirko on 16.12.2022.
//

#ifndef LAB1C___KNIGHT_H
#define LAB1C___KNIGHT_H
#include "Figure.h"
#include "Pawn.h"
#include <utility>
#include <cmath>
class Knight: public Figure {
public:

    void checkAllPossibleMoves(char(*chess_map)[N]) override {
        possible_ways.clear();

        // check to right T
        int k = 1;
        if (chess_map[map_y + 1][map_x + 2] == '0' && map_y + 1 < N && map_x + 2 < N) {
            possible_ways.push_back(std::make_pair(map_y + 1, map_x + 2));
        }
        if (chess_map[map_y - 1][map_x + 2] == '0' && map_y - 1 >= 0 && map_x + 2 < N) {
            possible_ways.push_back(std::make_pair(map_y - 1, map_x + 2));
        }
        //check to UP T
        if (chess_map[map_y - 2][map_x + 1] == '0' && map_y - 2 >= 0 && map_x + 1 < N) {
            possible_ways.push_back(std::make_pair(map_y - 1, map_x + 3));
        }

        if (chess_map[map_y - 2][map_x - 1] == '0' && map_y - 2 >= 0 && map_y - 1 >= 0) {
            possible_ways.push_back(std::make_pair(map_y - 1, map_x + 3));
        }
        //check to left T
        if (chess_map[map_y + 1][map_x - 2] == '0' && map_y + 1 < N && map_x - 2 >= 0) {
            possible_ways.push_back(std::make_pair(map_y - 1, map_x + 3));
        }
        if (chess_map[map_y - 1][map_x - 2] == '0' && map_y - 1 >= 0 && map_y - 2 >= 0) {
            possible_ways.push_back(std::make_pair(map_y - 1, map_x + 3));
        }
        //check to down T
        if (chess_map[map_y + 2][map_x + 1] == '0' && map_y + 2 < N && map_x + 1 < N) {
            possible_ways.push_back(std::make_pair(map_y - 1, map_x + 3));
        }
        if (chess_map[map_y + 2][map_x - 1] == '0' && map_y + 2 < N && map_y - 1 >= 0) {
            possible_ways.push_back(std::make_pair(map_y - 1, map_x + 3));
        }

    }
    void canAttack(char(*chess_map)[N], Figure* figure) override
    {
        if (team != figure->getTeam()) {
            // check to right T
            if (figure->getMapX() == map_x + 2){
                if (figure->getMapY() == map_y + 1){
                    possible_ways.push_back(std::make_pair(map_y + 1, map_x + 2));
                    figure->setAttacked(true);
                }
                if (figure->getMapY() == map_y - 1){
                    possible_ways.push_back(std::make_pair(map_y - 1, map_x + 2));
                    figure->setAttacked(true);
                }
            }
            //check to left T
            if (figure->getMapX() == map_x - 2){
                if (figure->getMapY() == map_y + 1){
                    possible_ways.push_back(std::make_pair(map_y + 1, map_x - 2));
                    figure->setAttacked(true);
                }
                if (figure->getMapY() == map_y - 1){
                    possible_ways.push_back(std::make_pair(map_y - 1, map_x - 2));
                    figure->setAttacked(true);
                }
            }
            //check to down T
            if (figure->getMapY() == map_y + 2){
                if (figure->getMapX() == map_x + 1){
                    possible_ways.push_back(std::make_pair(map_y + 2, map_x + 1));
                    figure->setAttacked(true);
                }
                if (figure->getMapX() == map_x - 1){
                    possible_ways.push_back(std::make_pair(map_y + 2, map_x - 1));
                    figure->setAttacked(true);
                }
            }
            //check to UP T
            if (figure->getMapY() == map_y - 2){
                if (figure->getMapX() == map_x + 1){
                    possible_ways.push_back(std::make_pair(map_y - 2, map_x + 1));
                    figure->setAttacked(true);
                }
                if (figure->getMapX() == map_x - 1){
                    possible_ways.push_back(std::make_pair(map_y - 2, map_x - 1));
                    figure->setAttacked(true);
                }
            }
        }
    }
    Knight(bool isWhite, bool isLeft){
        if(isWhite){
            team = Figure::Team::snowflake;
            if (isLeft){
                map_x = 1;
                map_y = 7;
            } else {
                map_x = 6;
                map_y = 7;
            }

        } else {
            team = Figure::Team::nigger;
            if (isLeft){
                map_x = 1;
                map_y = 0;
            } else {
                map_x = 6;
                map_y = 0;
            }

        }
        isAlive = true;
        attacked = false;
        symbol = 'H';
        figure_type = "Knoight";
    }
    Knight(Pawn pawn){
        isAlive = true;
        attacked = pawn.isAttacked();
        map_x = pawn.getMapX();
        map_y = pawn.getMapY();
        symbol = 'H';
        team = pawn.getTeam();
    }

};


#endif //LAB1C___KNIGHT_H

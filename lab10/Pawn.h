//
// Created by Gleb Nemirko on 16.12.2022.
//

#ifndef LAB1C___PAWN_H
#define LAB1C___PAWN_H
#include "Figure.h"
#include <utility>

class Pawn: public Figure{
public:
    void checkAllPossibleMoves(char(*chess_map)[N]) override{
        possible_ways.clear();
        int k = 1;


        // check up way
        if (chess_map[map_y - k][map_x] == '0' && map_y - k >= 0 && team == Figure::Team::snowflake)
        {

            possible_ways.push_back(std::make_pair(map_y - k, map_x));
        }

        // check down way
        if (chess_map[map_y + k][map_x] == '0' && map_y + k < N && team == Figure::Team::nigger)
        {
            possible_ways.push_back(std::make_pair(map_y + k, map_x));
        }


    }
    void canAttack(char(*chess_map)[N], Figure* figure) override
    {
        if (team != figure->getTeam())
        {
            if (figure->getMapY() == map_y - 1 && team == Figure::Team::snowflake ){
                if (figure->getMapX() == map_x + 1) {
                    possible_ways.push_back(std::make_pair(map_y - 1, map_x + 1));
                    figure->setAttacked(true);
                } else if (figure->getMapX() == map_x - 1){
                    possible_ways.push_back(std::make_pair(map_y - 1, map_x - 1));
                    figure->setAttacked(true);
                }
            } else if(figure->getMapY() == map_y + 1 && team == Figure::Team::nigger){
                if (figure->getMapX() == map_x + 1) {
                    possible_ways.push_back(std::make_pair(map_y + 1, map_x + 1));
                    figure->setAttacked(true);
                } else if (figure->getMapX() == map_x - 1){
                    possible_ways.push_back(std::make_pair(map_y + 1, map_x - 1));
                    figure->setAttacked(true);
                }
            }
        }
    }

    Pawn(bool isWhite, int pos){
            if(isWhite){
                team = Figure::Team::snowflake;
                map_x = pos;
                map_y = 6;
            } else {
                team = Figure::Team::nigger;
                map_x = pos;
                map_y = 1;
            }
            isAlive = true;
            attacked = false;
            symbol = 'P';
            figure_type = "Pawn";
        }
};


#endif //LAB1C___PAWN_H

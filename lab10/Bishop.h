//
// Created by Gleb Nemirko on 15.12.2022.
//

#ifndef LAB1C___BISHOP_H
#define LAB1C___BISHOP_H
#include "Figure.h"
#include <utility>
#include <cmath>


class Bishop: public Figure {
public:
    void checkAllPossibleMoves(char(*chess_map)[N]) override{
        possible_ways.clear();

        //check down-left
        int k = 1;
        while (chess_map[map_y + k][map_x - k] == '0' && map_y + k < N && map_x - k >= 0)
        {
            possible_ways.push_back(std::make_pair(map_y + k, map_x - k));

            k++;
        }

        //check down-right
        k = 1;
        while (chess_map[map_y + k][map_x + k] == '0' && map_y + k < N && map_x + k < N)
        {
            possible_ways.push_back(std::make_pair(map_y + k, map_x + k));

            k++;
        }

        //check up-right
        k = 1;
        while (chess_map[map_y - k][map_x + k] == '0' && map_y - k >= 0 && map_x + k < N)
        {
            possible_ways.push_back(std::make_pair(map_y + k, map_x - k));

            k++;
        }

        //check up-left
        k = 1;
        while (chess_map[map_y - k][map_x - k] == '0' && map_x - k >= 0 && map_y - k >= 0)
        {
            possible_ways.push_back(std::make_pair(map_y + k, map_x + k));

            k++;
        }
    }

    void canAttack(char(*chess_map)[N], Figure* figure) override
    {
        if (team != figure->getTeam())
        {
            if (abs(map_y - figure->getMapY()) == abs(map_x - figure->getMapX()))
            {
                int k = 1;

                // check right-down
                while (chess_map[map_y + k][map_x + k] == '0' && map_y + k < N && map_x + k < N) k++;

                if (map_x + k == figure->getMapX() && map_y + k == figure->getMapY())
                {
                    possible_ways.push_back(std::make_pair(map_y + k, map_x + k));
                    figure->setAttacked(true);
                }
                k = 1;
                // check right-up
                while (chess_map[map_y - k][map_x + k] == '0' && map_y - k >= 0 && map_x + k < N) k++;

                if (map_x + k == figure->getMapX() && map_y - k == figure->getMapY())
                {
                    possible_ways.push_back(std::make_pair(map_y - k, map_x + k));
                    figure->setAttacked(true);
                }
                // check left-up
                k = 1;
                while (chess_map[map_y - k][map_x - k] == '0' && map_x - k >= 0 && map_y - k >= 0) k++;

                if (map_x - k == figure->getMapX() && map_y - k == figure->getMapY())
                {
                    possible_ways.push_back(std::make_pair(map_y - k, map_x - k));
                    figure->setAttacked(true);
                }
                // check left-down
                k = 1;
                while (chess_map[map_y + k][map_x - k] == '0' && map_y + k < N && map_x - k >= 0) k++;

                if (map_x - k == figure->getMapX() && map_y + k == figure->getMapY())
                {
                    possible_ways.push_back(std::make_pair(map_y + k, map_x - k));
                    figure->setAttacked(true);
                }
            }
        }
    }

    Bishop(bool isWhite, bool isLeft){
        if(isWhite){
            team = Figure::Team::snowflake;
            if (isLeft){
                map_x = 2;
                map_y = 7;
            } else {
                map_x = 5;
                map_y = 7;
            }

        } else {
            team = Figure::Team::nigger;
            if (isLeft){
                map_x = 2;
                map_y = 0;
            } else {
                map_x = 5;
                map_y = 0;
            }

        }
        isAlive = true;
        attacked = false;
        symbol = 'B';
        figure_type = "Bishop";
    }
    Bishop(Pawn pawn){
        isAlive = true;
        attacked = pawn.isAttacked();
        map_x = pawn.getMapX();
        map_y = pawn.getMapY();
        symbol = 'B';
        team = pawn.getTeam();
    }

};


#endif //LAB1C___BISHOP_H

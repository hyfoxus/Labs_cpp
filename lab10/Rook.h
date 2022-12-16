//
// Created by Gleb Nemirko on 15.12.2022.
//

#ifndef LAB1C___ROOK_H
#define LAB1C___ROOK_H


#include "Figure.h"
#include <utility>
#include <cmath>
#include "Pawn.h"
using namespace std;

class Rook: public Figure{
public:
    void checkAllPossibleMoves(char(*chess_map)[N]) override{
        possible_ways.clear();

        // check right way
        int k = 1;
        while (chess_map[map_y][map_x + k] == '0' && map_x + k < N)
        {
            possible_ways.push_back(std::make_pair(map_y, map_x + k));

            k++;
        }

        // check left way
        k = 1;
        while (chess_map[map_y][map_x - k] == '0' && map_x - k >= 0)
        {
            possible_ways.push_back(std::make_pair(map_y, map_x - k));

            k++;
        }

        // check up way
        k = 1;
        while (chess_map[map_y - k][map_x] == '0' && map_y - k >= 0)
        {
            possible_ways.push_back(std::make_pair(map_y - k, map_x));

            k++;
        }

        // check down way
        k = 1;
        while (chess_map[map_y + k][map_x] == '0' && map_y + k < N)
        {
            possible_ways.push_back(std::make_pair(map_y + k, map_x));

            k++;
        }

    }

    void canAttack(char(*chess_map)[N], Figure* figure) override
    {
        if (team != figure->getTeam())
        {
            if (map_x == figure->getMapX())
            {
                int k = 1;

                // check down
                while (chess_map[map_y + k][map_x] == '0' && map_y + k < N) k++;

                if (map_y + k == figure->getMapY())
                {
                    possible_ways.push_back(std::make_pair(map_y + k, map_x));
                    figure->setAttacked(true);
                }

                // check up
                k = 1;
                while (chess_map[map_y - k][map_x] == '0' && map_y - k >= 0) k++;

                if (map_y - k == figure->getMapY())
                {
                    possible_ways.push_back(std::make_pair(map_y - k, map_x));
                    figure->setAttacked(true);
                }
            }

            if (map_y == figure->getMapY())
            {
                int k = 1;

                // check right
                while (chess_map[map_y][map_x + k] == '0' && map_x + k < N) k++;

                if (map_x + k == figure->getMapX())
                {
                    possible_ways.push_back(std::make_pair(map_y, map_x + k));
                    figure->setAttacked(true);
                }

                // check left
                k = 1;
                while (chess_map[map_y][map_x - k] == '0' && map_x - k >= 0) k++;

                if (map_x - k == figure->getMapX())
                {
                    possible_ways.push_back(std::make_pair(map_y, map_x - k));
                    figure->setAttacked(true);
                }
            }

        }
    }

    Rook(bool isWhite, bool isLeft){
        if(isWhite){
            team = Figure::Team::snowflake;
            if (isLeft){
                map_x = 0;
                map_y = 7;
            } else {
                map_x = 7;
                map_y = 7;
            }

        } else {
            team = Figure::Team::nigger;
            if (isLeft){
                map_x = 0;
                map_y = 0;
            } else {
                map_x = 7;
                map_y = 0;
            }

        }
        isAlive = true;
        attacked = false;
        symbol = 'R';
        figure_type = "Rook";
    }
    Rook(Pawn pawn){
        isAlive = true;
        attacked = pawn.isAttacked();
        map_x = pawn.getMapX();
        map_y = pawn.getMapY();
        symbol = 'R';
        team = pawn.getTeam();
    }
};


#endif //LAB1C___ROOK_H

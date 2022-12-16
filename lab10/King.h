//
// Created by Gleb Nemirko on 16.12.2022.
//

#ifndef LAB1C___KING_H
#define LAB1C___KING_H

#include "Figure.h"
#include <utility>
#include <cmath>
using namespace std;

class King: public Figure {
public:
    void checkAllPossibleMoves(char(*chess_map)[N]) override{
        possible_ways.clear();

        // check right way
        int k = 1;
        if (chess_map[map_y][map_x + k] == '0' && map_x + k < N)
        {
            possible_ways.push_back(make_pair(map_y, map_x + k));
        }

        // check left way
        if (chess_map[map_y][map_x - k] == '0' && map_x - k >= 0)
        {
            possible_ways.push_back(std::make_pair(map_y, map_x - k));
        }

        // check up way
        if (chess_map[map_y - k][map_x] == '0' && map_y - k >= 0)
        {
            possible_ways.push_back(std::make_pair(map_y - k, map_x));
        }

        // check down way
        if (chess_map[map_y + k][map_x] == '0' && map_y + k < N)
        {
            possible_ways.push_back(std::make_pair(map_y + k, map_x));
        }

        //check down-left

        if (chess_map[map_y + k][map_x - k] == '0' && map_y + k < N && map_x - k >= 0)
        {
            possible_ways.push_back(std::make_pair(map_y + k, map_x - k));
        }

        //check down-right

        if (chess_map[map_y + k][map_x + k] == '0' && map_y + k < N && map_x + k < N)
        {
            possible_ways.push_back(std::make_pair(map_y + k, map_x + k));
        }

        //check up-right

        if (chess_map[map_y - k][map_x + k] == '0' && map_y - k >= 0 && map_x + k < N)
        {
            possible_ways.push_back(std::make_pair(map_y + k, map_x - k));
        }

        //check up-left

        if (chess_map[map_y - k][map_x - k] == '0' && map_x - k >= 0 && map_y - k >= 0)
        {
            possible_ways.push_back(std::make_pair(map_y + k, map_x + k));
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


                if (map_y + k == figure->getMapY())
                {
                    possible_ways.push_back(std::make_pair(map_y + k, map_x));
                    figure->setAttacked(true);
                }

                // check up
                k = 1;

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


                if (map_x + k == figure->getMapX())
                {
                    possible_ways.push_back(std::make_pair(map_y, map_x + k));
                    figure->setAttacked(true);
                }

                // check left
                k = 1;


                if (map_x - k == figure->getMapX())
                {
                    possible_ways.push_back(std::make_pair(map_y, map_x - k));
                    figure->setAttacked(true);
                }
            }

            if (abs(map_y - figure->getMapY()) == abs(map_x - figure->getMapX()))
            {
                int k = 1;

                // check right-down

                if (map_x + k == figure->getMapX() && map_y + k == figure->getMapY())
                {
                    possible_ways.push_back(std::make_pair(map_y + k, map_x + k));
                    figure->setAttacked(true);
                }

                // check right-up
                if (map_x + k == figure->getMapX() && map_y - k == figure->getMapY())
                {
                    possible_ways.push_back(std::make_pair(map_y - k, map_x + k));
                    figure->setAttacked(true);
                }
                // check left-up

                if (map_x - k == figure->getMapX() && map_y - k == figure->getMapY())
                {
                    possible_ways.push_back(std::make_pair(map_y - k, map_x - k));
                    figure->setAttacked(true);
                }
                // check left-down

                if (map_x - k == figure->getMapX() && map_y + k == figure->getMapY())
                {
                    possible_ways.push_back(std::make_pair(map_y + k, map_x - k));
                    figure->setAttacked(true);
                }
            }
        }
    }

    King(bool isWhite){
        if(isWhite){
            team = Figure::Team::snowflake;
            map_x = 4;
            map_y = 7;
        } else {
            team = Figure::Team::nigger;
            map_x = 3;
            map_y = 0;
        }
        isAlive = true;
        attacked = false;
        symbol = 'K';
        figure_type = "King";
    }

};


#endif //LAB1C___KING_H

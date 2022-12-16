//
// Created by Gleb Nemirko on 15.12.2022.
//

#ifndef LAB1C___QUEEN_H
#define LAB1C___QUEEN_H
#include "Figure.h"
#include "Pawn.h"
#include <utility>
#include <cmath>

using namespace std;
class Queen : public Figure {
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

        //check down-left
        k = 1;
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

                // check right-up
                k = 1;
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

    Queen(bool isWhite){
        if(isWhite){
            team = Figure::Team::snowflake;
            map_x = 3;
            map_y = 7;
        } else {
            team = Figure::Team::nigger;
            map_x = 4;
            map_y = 0;
        }
        isAlive = true;
        attacked = false;
        symbol = 'Q';
        figure_type = "Queen";
    }
    Queen(Pawn pawn){
        isAlive = true;
        attacked = pawn.isAttacked();
        map_x = pawn.getMapX();
        map_y = pawn.getMapY();
        symbol = 'Q';
        team = pawn.getTeam();
    }

};


#endif //LAB1C___QUEEN_H

//
// Created by Gleb Nemirko on 16.12.2022.
//

#ifndef LAB1C___CHESS_H
#define LAB1C___CHESS_H
#include "Board.h"
#include "Player.h"
#include <utility>
#include "vector"
#include <string>

class Chess {
private:
    vector<string> log;
    Player player1;
    Player player2;

public:
    bool checkIfKingSafe(pair<int, int> start, pair<int, int> end, bool isWhiteTurn, Board board);
    void generatePlayers();
    void startGame();
};


#endif //LAB1C___CHESS_H

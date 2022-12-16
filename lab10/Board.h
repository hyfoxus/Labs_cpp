//
// Created by Gleb Nemirko on 09.12.2022.
//

#ifndef LAB1C___BOARD_H
#define LAB1C___BOARD_H
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Pawn.h"
#include "Knight.h"
#include "King.h"
#include "algorithm"
#include <vector>
#include <utility>

using namespace std;



class Board {
public:
    char board[8][8];
    vector<Figure*> figureWhite;
    vector<Figure*> figureBlack;

    Board(){
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                board[i][j] = '0';
            }
        }

        Queen queenW(true);
        Queen queenB(false);
        figureWhite.push_back(&queenW);
        figureBlack.push_back(&queenB);
        King kingW(true);
        King kingB(false);
        figureWhite.push_back(&kingW);
        figureBlack.push_back(&kingB);

        Knight knightWL(true, true);
        Knight knightWR(true, false);
        Knight knightBL(false, true);
        Knight knightBR(false, false);

        figureWhite.push_back(&knightWL);
        figureWhite.push_back(&knightWR);
        figureBlack.push_back(&knightBL);
        figureBlack.push_back(&knightBR);

        Rook rookWL(true, true);
        Rook rookWR(true, false);
        Rook rookBL(false, true);
        Rook rookBR(false, false);

        figureWhite.push_back(&rookWL);
        figureWhite.push_back(&rookWR);
        figureBlack.push_back(&rookBL);
        figureBlack.push_back(&rookBR);

        Bishop bishopWL(true, true);
        Bishop bishopWR(true, false);
        Bishop bishopBL(false, true);
        Bishop bishopBR(false, false);

        figureWhite.push_back(&bishopWL);
        figureWhite.push_back(&bishopWR);
        figureBlack.push_back(&bishopBL);
        figureBlack.push_back(&bishopBR);

        Pawn pawn0W(true, 0);
        figureWhite.push_back(&pawn0W);
        Pawn pawn1W(true, 1);
        figureWhite.push_back(&pawn1W);
        Pawn pawn2W(true, 2);
        figureWhite.push_back(&pawn2W);
        Pawn pawn3W(true, 3);
        figureWhite.push_back(&pawn3W);
        Pawn pawn4W(true, 4);
        figureWhite.push_back(&pawn4W);
        Pawn pawn5W(true, 5);
        figureWhite.push_back(&pawn5W);
        Pawn pawn6W(true, 6);
        figureWhite.push_back(&pawn6W);
        Pawn pawn7W(true, 7);
        figureWhite.push_back(&pawn7W);

        Pawn pawn0B(false, 0);
        figureBlack.push_back(&pawn0B);
        Pawn pawn1B(false, 1);
        figureBlack.push_back(&pawn1B);
        Pawn pawn2B(false, 2);
        figureBlack.push_back(&pawn2B);
        Pawn pawn3B(false, 3);
        figureBlack.push_back(&pawn3B);
        Pawn pawn4B(false, 4);
        figureBlack.push_back(&pawn4B);
        Pawn pawn5B(false, 5);
        figureBlack.push_back(&pawn5B);
        Pawn pawn6B(false, 6);
        figureBlack.push_back(&pawn6B);
        Pawn pawn7B(false, 7);
        figureBlack.push_back(&pawn7B);


        for (int i = 0; i < 16; ++i) {
            board[figureBlack.at(i)->getMapY()][figureBlack.at(i)->getMapX()] = figureBlack.at(i)->getSymbol();
            board[figureWhite.at(i)->getMapY()][figureWhite.at(i)->getMapX()] = figureWhite.at(i)->getSymbol();

        }

    }

    Board(Board const &board_to_copy){
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                board[i][j] = board_to_copy.board[i][j];
            }
        }
        copy(board_to_copy.figureWhite.begin(), board_to_copy.figureWhite.end(), figureWhite.begin());
        copy(board_to_copy.figureBlack.begin(), board_to_copy.figureBlack.end(), figureBlack.begin());
    }

    virtual ~Board();



    void Move(pair<int, int> start, pair<int, int> end, bool isWhiteTurn);

    void print();

};


#endif //LAB1C___BOARD_H

//
// Created by Gleb Nemirko on 09.12.2022.
//

#include "Board.h"

using namespace std;

void Board::print() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}



void Board::Move(pair<int, int> start, pair<int, int> end, bool isWhiteTurn) {

    Figure* figurete = nullptr;
    if (isWhiteTurn) {
        for (int i = 0; i < 16; ++i) {
            if (figureWhite[i]->getMapX() == start.second && figureWhite[i]->getMapY() == start.first){
                figurete = figureWhite[i];
            }
        }
    } else{
        for (int i = 0; i < 16; ++i) {
            if (figureBlack.at(i)->getMapX() == start.second && figureBlack.at(i)->getMapY() == start.second){
                figurete = figureBlack.at(i);
            }
        }
    }

    if (figurete != nullptr) {
        figurete->checkAllPossibleMoves(board);

        for (auto i: figurete->possible_ways) {
            if (end == i) {
                figurete->setMapX(end.second);
                figurete->setMapY(end.first);

                board[start.first][start.second] = '0';
                board[figurete->getMapY()][figurete->getMapX()] = figurete->getSymbol();
            }
        }
    }

}




Board::~Board() {

}

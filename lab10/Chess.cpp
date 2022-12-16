//
// Created by Gleb Nemirko on 16.12.2022.
//

#include "Chess.h"

using namespace std;
bool Chess::checkIfKingSafe(pair<int, int> start, pair<int, int> end, bool isWhiteTurn, Board board) {
    Board board_theoretical(board);
    board_theoretical.Move(start, end, isWhiteTurn);
    if (isWhiteTurn){
        for (int i = 0; i < 16; ++i) {
            board_theoretical.figureBlack[i]->canAttack(board_theoretical.board, board_theoretical.figureWhite[1]);
        }
        if (board_theoretical.figureWhite[1]->isAttacked()) {
            return false;
        } else return true;
    } else{
        for (int i = 0; i < 16; ++i) {
            board_theoretical.figureWhite[i]->canAttack(board_theoretical.board, board_theoretical.figureBlack[1]);
        }
        if (board_theoretical.figureBlack[1]->isAttacked()) {
            return false;
        } else return true;
    }


}

void Chess::generatePlayers() {
    cout << "Insert Player 1 name" << endl;
    string name1;
    cin >> name1;
    cout << "Insert Player 2 name" << endl;
    string name2;
    cin >> name2;
    player1.setName(name1);
    player2.setName(name2);
    if (rand() % 2 == 0) {
        player1.setColor("Белый");
        player2.setColor("Черный");
    }
    else{
        player2.setColor("Белый");
        player1.setColor("Черный");
    }

}

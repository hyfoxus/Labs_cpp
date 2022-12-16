#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "Board.h"
#include "Board.cpp"
#include "Chess.h"
#include "Chess.cpp"
using namespace std;
int main() {
    Board board;
    //board.print();

   // cout<< board.figureWhite.at(1)->getMapX() << board.figureWhite.at(1)->getMapY() << endl;
    pair<int, int> start;
    pair<int, int> end;

    start.second = 3;
    start.first = 6;

    end.second = 3;
    end.first = 5;

    board.Move(start, end, true);
    board.print();


    return 0;
}

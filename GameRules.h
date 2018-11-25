//
// Created by noam on 03/09/2018.
//

#ifndef EX2_PRESEMSTER_GAMERULES_H
#define EX2_PRESEMSTER_GAMERULES_H

#include <vector>
#include <string>
#include "Board.h"

using namespace std;


class GameRules {

public:
    virtual vector<pair<int, int>> possibleMoves(Board board, string color) = 0;

    virtual bool isGameOver(Board board) = 0;

    virtual void resetBoard(Board *board) = 0;

    virtual vector<pair<int, int>> removeOutOfBounderyMoves(vector<pair<int, int>> possible_moves, int board_size) = 0;


};


#endif //EX2_PRESEMSTER_GAMERULES_H

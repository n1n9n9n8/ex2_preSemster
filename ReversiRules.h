//
// Created by noamc on 12/10/2018.
//

#ifndef EX2_PRESEMSTER_REVERSIRULES_H
#define EX2_PRESEMSTER_REVERSIRULES_H


#include "GameRules.h"

class ReversiRules : public GameRules {
public:
    vector<pair<int, int>> possibleMoves(Board board, string color);

    bool isGameOver(Board board);

    void resetBoard(Board *board);

    vector<pair<int, int>> removeOutOfBounderyMoves(vector<pair<int, int>> possible_moves, int board_size);
};


#endif //EX2_PRESEMSTER_REVERSIRULES_H

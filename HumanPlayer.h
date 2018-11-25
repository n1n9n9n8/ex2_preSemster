//
// Created by noam on 10/09/2018.
//

#ifndef EX2_PRESEMSTER_HUMANPLAYER_H
#define EX2_PRESEMSTER_HUMANPLAYER_H


#include "Player.h"
#include <vector>
#include <string>

class HumanPlayer: public Player {
private:
    // can be only "O" and "X"
    string color;

public:
    HumanPlayer(string color);
    pair<int, int> playOneTurn(vector<pair<int, int>> possibleMoves);
    string getColor();

};


#endif //EX2_PRESEMSTER_HUMANPLAYER_H

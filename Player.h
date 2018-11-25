//
// Created by noam on 03/09/2018.
//

#ifndef EX2_PRESEMSTER_PLAYER_H
#define EX2_PRESEMSTER_PLAYER_H


#include <vector>
#include <string>
#include "Board.h"

using namespace std;


class Player {
private:
//string color;

public:
  //  Player(string color);
    virtual pair<int, int> playOneTurn(vector<pair<int, int>> possibleMoves)=0;
    virtual string getColor()=0;

};


#endif //EX2_PRESEMSTER_PLAYER_H

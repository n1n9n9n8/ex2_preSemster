//
// Created by noam on 28/09/2018.
//

#ifndef EX2_PRESEMSTER_GAME_H
#define EX2_PRESEMSTER_GAME_H

#include "Board.h"
#include "GameRules.h"
#include "Player.h"


class Game {
private:
    Player* player1;
    Player* player2;
    GameRules* gameRules;
    Board* board;


    void playHisTurn(Player* player);

public:
    string movesToString(vector<pair<int,int>> possible_moves);
    Game(Player* player1,Player* player2,GameRules* gameRules, Board* board);
    void playGame();
};


#endif //EX2_PRESEMSTER_GAME_H

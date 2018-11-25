//
// Created by noam on 28/09/2018.
//

#include "Game.h"
#include <iostream>

#define ERROR_IN_TURN_MASSAGE "error in turns"
#define PRINT_BOARD_MASSAGE "Current board:"
#define WHOS_TURN_MASSAGE " It's your move."
#define GET_INPUT_MASSAGE "Please enter your move row,col: "
#define POSSIBLE_MOVES_MASSAGE "your possible moves are: "


Game::Game(Player *player1, Player *player2, GameRules *gameRules, Board *board) {
    this->player1 = player1;
    this->player2 = player2;
    this->gameRules = gameRules;
    this->board = board;
}


void Game::playGame() {
    gameRules->resetBoard(board);
    int turn = 1;
    while (!gameRules->isGameOver(*board)) {
        cout << PRINT_BOARD_MASSAGE << endl;
        board->printBoard();
        switch (turn) {
            case 1:
                playHisTurn(player1);
                turn = 2;
                break;
            case 2:
                playHisTurn(player2);
                turn = 1;
                break;
                //default pnly for coding style
            default:
                cout << ERROR_IN_TURN_MASSAGE << endl;

        }
    }
}


void Game::playHisTurn(Player *player) {
    vector<pair<int, int>> possible_moves = gameRules->possibleMoves(*board, player->getColor());
    string str_pissible_moves = movesToString(possible_moves);
    if (str_pissible_moves == "") {
        return;
    }
    cout << player->getColor() + ":" + WHOS_TURN_MASSAGE << endl;
    cout << POSSIBLE_MOVES_MASSAGE + str_pissible_moves << endl;
    cout << GET_INPUT_MASSAGE;
    player->playOneTurn(possible_moves);
}

string Game::movesToString(vector<pair<int, int>> possible_moves) {
    string s = "";
    //TODO: fix, allways thing the vector is empty
    if (possible_moves.empty()) {
        return s;
    }
    s += "(" + to_string(possible_moves[0].first) + "," + to_string(possible_moves[0].second) + ")";
    for (int i = 1; i < possible_moves.size(); ++i) {
        s += ",(" + to_string(possible_moves[i].first) + "," + to_string(possible_moves[i].second) + ")";
    }
    return s;
}







//
// Created by noam on 31/08/2018.
//

#include <iostream>
#include "Board.h"


Board::Board() {

    for (int i = 0; i < kBoardSize; ++i) {
        for (int j = 0; j < kBoardSize; ++j) {
            put(i, j, defultBlock);
        }
    }
}

string Board::getDefultBlock() {
    return defultBlock;
}


void Board::put(int x, int y, string s) {
    //check if the point is in the board limits
    if ((x < 0 || x >= kBoardSize) || (y < 0 || y >= kBoardSize)) {
        cout << "out of boundary insertion of " + s << endl;
        exit(1);
    }
    //put the s
    board[x][y] = s;
}

void Board::put(pair<int, int> point, string s) {
    put(point.first, point.second, s);

}


void Board::putO(int x, int y) {
    put(x, y, "O");
}


void Board::putX(int x, int y) {
    put(x, y, "X");
}


string Board::get(int x, int y) {
    return board[x][y];
}

string Board::get(pair<int, int> point) {
    return board[point.first][point.second];
}


string Board::toString() {
    //will be used allot:
    const string kSparedLineOfX = "| ";
    const string kSparedLineOfY = "\n-----------------------------------\n";
    //an empty string, to be edit
    string s = "";
    //add an empty block for the column of numbers
    s += " " + kSparedLineOfX;

    //first line, only numbers
    for (int i = 1; i < kBoardSize + 1; ++i) {
        s += to_string(i) + " " + kSparedLineOfX;
    }
    // a spared line of y
    s += kSparedLineOfY;

    //all the other lines
    for (int j = 0; j < kBoardSize; ++j) {
        // add the column of number
        s += to_string(j + 1) + kSparedLineOfX;
        for (int k = 0; k < kBoardSize; ++k) {
            s += get(j, k) + " " + kSparedLineOfX;
        }
        s += kSparedLineOfY;
    }

    return s;
}


void Board::printBoard() {
    cout << toString() << endl;
}


vector<pair<int, int>> Board::findColor(string color) {
    vector<pair<int, int>> blocks_with_color;
    this->printBoard();
    for (int i = 0; i < kBoardSize; ++i) {
        for (int j = 0; j < kBoardSize; ++j) {
            string current_color = get(i, j);
            if (color == current_color) {
                pair<int, int> block;
                block.first = i;
                block.second = j;
                blocks_with_color.push_back(block);
            }
        }
    }
    return blocks_with_color;

}


int Board::size() {
    return kBoardSize;
}


vector<string> Board::getColors() {
    vector<string> colors;
    for (int i = 0; i < kBoardSize; ++i) {
        for (int j = 0; j < kBoardSize; ++j) {
            string color = get(i, j);
            if (color != defultBlock) {
                colors.push_back(color);
            }
        }
    }
    return colors;
}

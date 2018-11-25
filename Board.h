//
// Created by noam on 31/08/2018.
//

#ifndef EX1_PRESEMSTER_BOARD_H
#define EX1_PRESEMSTER_BOARD_H


#include <map>
#include <vector>

using namespace std;

class Board {
private:
    //TODO: check how to use const and static (what is allowed)
    static const int kBoardSize = 8;
    const string defultBlock = " ";
    string board[kBoardSize][kBoardSize];


public:

    //constructor
    Board();

    //get functions
    string getDefultBlock();


    //put functions
    void putX(int x, int y);

    void putO(int x, int y);

    void put(int x, int y, string s);

    void put(pair<int, int> point, string s);

    //a get function
    string get(int x, int y);

    string get(pair<int, int> point);

    //to string and print function
    string toString();

    void printBoard();

    //find all the blocks with a given color
    vector<pair<int, int>> findColor(string color);
    int size();
    vector<string> getColors();

};


#endif //EX1_PRESEMSTER_BOARD_H

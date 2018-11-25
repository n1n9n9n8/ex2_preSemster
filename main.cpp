#include <iostream>
#include "GameElements.h"

using namespace std;


int main() {
//    Board b;
//    b.printBoard();
//    Board b;
//    GameRules gameRules;
//    b.printBoard();
//    vector<pair<int, int>> v = gameRules.possibleMoves(b,"X");
//    for (int i = 0; i < v.size(); ++i) {
//        cout <<to_string(i+1)+"." "(" + to_string(v[i].first+1) + "," + to_string(v[i].second+1) + ")" << endl;
//    }
//
//    regex regex("[0-9]+,[0-9]+");
//    string s1 = "1,1";
//    string s2 = "20,20";
//    string s3 = "3,3)";
//    if (regex_match(s1,regex)){
//        cout<<"1 works!"<<endl;
//    }
//    if (regex_match(s2,regex)){
//        cout<<"2 works!"<<endl;
//    }
//    if (!regex_match(s3,regex)){
//        cout<<"3 works!"<<endl;
//    }
//    HumanPlayer hm = HumanPlayer("x");
//    vector<pair<int, int>> v = {{1, 1}};
//    pair<int, int> p = hm.playOneTurn(v);
//    cout << "(" + to_string(p.first) + "," + to_string(p.second) + ")" << endl;

    HumanPlayer player1("x");
    HumanPlayer player2("o");
    Board board;
    ReversiRules gameRules;
    Game game(&player1, &player2, &gameRules, &board);
    //game.playGame();
    gameRules.resetBoard(&board);
    cout<<game.movesToString(gameRules.possibleMoves(board,player2.getColor()));
    return 0;
}
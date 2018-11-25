//
// Created by noam on 03/09/2018.
//

//#include "Player.h"
//#include <iostream>
//#include <regex>
//
//
//#define REGEX "[0-9]+,[0-9]+"
//#define WRONG_INPUT_MASSAGE "there has been a problem with the following input,"  \
//" please enter another input.\nthe bad input is: "
//#define GET_INPUT_MASSAGE "Please enter your move row,col: "
//
//pair<int, int> stringToPairInt(string s);
//
//bool checkInput(string input);
//
//void badInput(string input);
//
//Player::Player(string color) {
//    this->color = color;
//}
//
//pair<int, int> Player::playOneTurn(vector<pair<int, int>> possibleMoves) {
//    cout << GET_INPUT_MASSAGE << endl;
//    string input;
//    cin >> input;
//    while (!checkInput(input)) {
//        badInput(input);
//    }
//    //TODO: put a return
//    pair<int,int> pair = {1,1};
//    return pair;
//}
//
//
//pair<int, int> stringToPair(string input) {
//
//
//};
//
//bool checkInput(string input) {
//    regex pattern(REGEX);
//    return regex_match(input, pattern);
//}
//
//void badInput(string input) {
//    cout << WRONG_INPUT_MASSAGE + input << endl;
//}

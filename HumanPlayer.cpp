//
// Created by noam on 10/09/2018.
//

//
// Created by noam on 03/09/2018.
//

#include "Player.h"
#include "HumanPlayer.h"
#include <iostream>
#include <regex>

//TODO: check the code work

#define REGEX "[0-9]+,[0-9]+"
#define WRONG_INPUT_MASSAGE "there has been a problem with the following input,"  \
" please enter another input.\nthe bad input is: "
#define STARTING_NUMBER_ASCII '0'

pair<int, int> stringToPairInt(string intput);

bool checkInput(string input);

string badInput(string input);

string getInput();

string getNcheckInput();

HumanPlayer::HumanPlayer(string color) {
    this->color = color;
}
string HumanPlayer::getColor() {
    return color;
}


pair<int, int> HumanPlayer::playOneTurn(vector<pair<int, int>> possibleMoves) {
    //get the input as a string

    string str_input = getNcheckInput();
    //convert the string to a pair<int,int>
    pair<int, int> input = stringToPairInt(str_input);
    //check if the pair is in the vector
    for (int i = 0; i < possibleMoves.size(); ++i) {
        if (possibleMoves[i].first == input.first && possibleMoves[i].second == input.second) {
            return input;
        }
    }
    cout << WRONG_INPUT_MASSAGE + str_input << endl;
    //call the function again to get the input again
    return this->playOneTurn(possibleMoves);
}

string getNcheckInput() {
    string str_input = getInput();
    while (!checkInput(str_input)) {
        str_input = badInput(str_input);
    }
    return str_input;
}

string getInput() {
    string input;
    cin >> input;
    return input;
}


pair<int, int> stringToPairInt(string input) {
    int index = 0;
    char digit = input[0];
    string first_num = "";
    string second_num = "";

    while (digit != ',') {
        first_num += to_string(digit);
        index++;
        digit = input[index];
    }
    index++;
    while (index < input.size()) {
        digit = input[index];
        second_num += to_string(digit);
        index++;
    }

    pair<int, int> pair = {stoi(first_num) - STARTING_NUMBER_ASCII, stoi(second_num) - STARTING_NUMBER_ASCII};
    return pair;

};

bool checkInput(string input) {
    regex pattern(REGEX);
    return regex_match(input, pattern);
}

string badInput(string input) {
    cout << WRONG_INPUT_MASSAGE + input << endl;
    return getInput();
}

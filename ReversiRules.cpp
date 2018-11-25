//
// Created by noamc on 12/10/2018.
//

#include "ReversiRules.h"
//
// Created by noam on 03/09/2018.
//

#include <iostream>

vector<pair<int, int>> getBlocksNear(pair<int, int> block);


vector<pair<int, int>> ReversiRules::possibleMoves(Board board, string color) {
    //the vector to be return
    vector<pair<int, int>> possible_moves;

    vector<pair<int, int>> blocks_with_color = board.findColor(color);
    //the default block. if a block is this, the block is empty
    string defultBlock = board.getDefultBlock();
    //go over all the blocks with the given color
    for (int i = 0; i < blocks_with_color.size(); ++i) {
        //get all the blocks that near this block
        vector<pair<int, int>> near_blocks = getBlocksNear(blocks_with_color[i]);
        for (int j = 0; j < near_blocks.size(); ++j) {
            string block_color = board.get(near_blocks[j]);
            //if there is a near block with a diffrent color that is not empty
            if (block_color != color && block_color != defultBlock) {
                //find the dx and dy
                int dx = near_blocks[j].first - blocks_with_color[i].first;
                int dy = near_blocks[j].second - blocks_with_color[i].second;
                pair<int, int> possoble_blcok = {near_blocks[j].first + dx, near_blocks[j].second + dy};
                //check if the right block is empty
                if (board.get(possoble_blcok) == defultBlock) {
                    possible_moves.push_back(possoble_blcok);
                }

            }
        }
    }

    return removeOutOfBounderyMoves(possible_moves, board.size());
}

//TODO: there is not declaration of the function
void add_near_to_vecotr(vector<pair<int, int>> *vector, pair<int, int> block, int dx, int dy) {
    pair<int, int> new_block;
    new_block.first = block.first + dx;
    new_block.second = block.second + dy;
    vector->push_back(new_block);

}


vector<pair<int, int>> getBlocksNear(pair<int, int> block) {
    vector<pair<int, int>> near_blocks;
    add_near_to_vecotr(&near_blocks, block, 1, 1);
    add_near_to_vecotr(&near_blocks, block, 1, 0);
    add_near_to_vecotr(&near_blocks, block, 0, 1);
    add_near_to_vecotr(&near_blocks, block, -1, -1);
    add_near_to_vecotr(&near_blocks, block, -1, 0);
    add_near_to_vecotr(&near_blocks, block, 0, -1);
    add_near_to_vecotr(&near_blocks, block, 1, -1);
    add_near_to_vecotr(&near_blocks, block, -1, 1);

    return near_blocks;

};

vector<pair<int, int>> ReversiRules::removeOutOfBounderyMoves(vector<pair<int, int>> possible_moves, int board_size) {
    vector<pair<int, int>> possible_moves_in_boundery;
    for (int i = 0; i < possible_moves.size(); ++i) {
        if (possible_moves[i].first >= board_size && possible_moves[i].first < 0) {
            continue;
        }
        if (possible_moves[i].second >= board_size && possible_moves[i].second < 0) {
            continue;
        }
        possible_moves_in_boundery.push_back(possible_moves[i]);
    }
    return possible_moves_in_boundery;
}


bool ReversiRules::isGameOver(Board board) {
    board.printBoard();
    //check if the board is full
    bool isBoardFull = true;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            if (board.get(i, j) == board.getDefultBlock()) {
                isBoardFull = false;
                break;
            }
        }
    }
    if (isBoardFull) {
        return true;
    }
    //get all the colors on the board
    vector<string> colors = board.getColors();
    //check for each one if they have a possible move
    for (int k = 0; k < colors.size(); ++k) {
        vector<pair<int, int>> possible_moves = possibleMoves(board, colors[k]);
        //if a color has a possible move, return false
        if (!possible_moves.empty()) {
            return false;
        }
    }
    return true;

}


void ReversiRules::resetBoard(Board* board) {

//put the staring value of the white player
    board->putO(3, 3);
    board->putO(4, 4);
//put the staring value of the black player
    board->putX(3, 4);
    board->putX(4, 3);

}













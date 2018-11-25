cmake_minimum_required(VERSION 3.8)
project(ex2_preSemster)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Board.cpp Board.h Player.cpp Player.h GameRules.cpp GameRules.h HumanPlayer.cpp HumanPlayer.h Game.cpp Game.h GameElements.h ReversiRules.cpp ReversiRules.h)
add_executable(ex2_preSemster ${SOURCE_FILES})
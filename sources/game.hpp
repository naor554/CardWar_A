#include <iostream>
#include <stdexcept>
#include "player.hpp"

#ifndef EX1_CPP_A_GAME_H
#define EX1_CPP_A_GAME_H
#pragma once
#endif //EX1_CPP_A_GAME_H

namespace ariel{

    class Game
    {

    public:
        Game(Player &p1, Player &p2);
        ~Game();
        int getNumCardsInDeck();
        int getNumTurns();
        bool isOver();
        string getWinner();
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };

}



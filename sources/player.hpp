#include <iostream>
#include <stack>
#include <string>
#include "card.hpp"


#pragma once
#ifndef EX1_CPP_A_PLAYER_H
#define EX1_CPP_A_PLAYER_H

#endif //EX1_CPP_A_PLAYER_H

namespace ariel{
    using namespace std;

    class Player
    {
    private:
        string name;
        stack<Card> st;
        Card current;
        bool isplayning;
        int CardsLeft;
        int CardsWon;

    public:
        
        Player(string name);
        ~Player();
        int stacksize();
        int cardesTaken();
        bool isPlayning();
        string getName();
        Card GetCurrentCard();
        void takeCard();
        void addCard(Card c);
    };
    

}


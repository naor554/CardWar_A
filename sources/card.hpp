#include <iostream>
#pragma once
#ifndef EX1_CPP_A_CARD_H
#define EX1_CPP_A_CARD_H

#endif //EX1_CPP_A_CARD_H

enum shape{Heart,Diamond,Club,Spade};

namespace ariel{
    using namespace std;


    class Card
    {
    private:
        int num;
        enum shape shape;
  
    public:
        Card();
        Card(enum shape s, int val);
        ~Card();
        int value();
        string getinfo();
    };
}
    
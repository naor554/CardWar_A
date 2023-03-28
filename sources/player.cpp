#include "player.hpp"
#include "card.hpp"

namespace ariel
{
  Player::Player(string name){}
  Player::~Player() {}
  int Player:: stacksize(){ return 0;}
  int Player:: cardesTaken(){ return 0;}  
  string Player:: getName(){return "Bob";};
  bool Player:: isPlayning(){return false;}
  Card Player:: GetCurrentCard(){Card c(Heart,2); 
                                 return c;};
  void Player:: takeCard(){};
  void Player:: addCard(Card c){};
} 




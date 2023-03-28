#include <stdexcept>
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"

namespace ariel
{
    Game::Game(Player &p1, Player &p2){}
    Game::~Game() {}
    int Game:: getNumCardsInDeck(){return 56;}
    int Game:: getNumTurns(){return 0;}
    bool Game:: isOver(){return true;}
    string Game:: getWinner(){return "Alice";}
    void Game:: playTurn(){}
    void Game:: playAll(){}
    void Game:: printLastTurn(){}
    void Game:: printLog(){}
    void Game:: printStats(){}
    void Game:: printWiner(){}
} 

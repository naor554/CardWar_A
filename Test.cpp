#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

using namespace ariel;
using namespace std;



TEST_CASE ("Test game initialization") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK(game.getNumCardsInDeck() == 52);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE ("Test registeration for one game only") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK_NOTHROW(Game game2(p1,p2));
    CHECK_NOTHROW(Game game2(p2,p2));
}



TEST_CASE("Test playing a single turn") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();
    CHECK(game.getNumTurns() == 1);
    CHECK(game.getNumCardsInDeck() == 50);
}

TEST_CASE("Test playing multiple turns") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK(game.getNumTurns() > 0);
    CHECK(game.getNumCardsInDeck() == 0);
}

TEST_CASE("Test getting winner of the game") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK((game.getWinner()) == (p1.getName()));
    CHECK((game.getWinner()) == (p2.getName()));
}

TEST_CASE("Test edge case where both players have no cards left") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    // Make both players run out of cards
    while (!game.isOver()) {
        game.playTurn();
    }

    CHECK(game.getNumTurns() > 0);
    CHECK(game.getNumCardsInDeck() == 0);
    CHECK(game.getWinner() != "");
}

TEST_CASE("Test tiebreaker logic") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    // Make both players draw identical cards and go into tiebreaker
    Card c1(Heart, 5);
    Card c2(Diamond, 5);
    p1.addCard(c1);
    p2.addCard(c2);
    game.playTurn();
    CHECK(game.getNumTurns() == 1);
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK((p1.cardesTaken()) == 6);
    CHECK((p2.cardesTaken()) == 6);

}

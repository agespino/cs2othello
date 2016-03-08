#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.h"
#include "board.h"
#include <vector>
using namespace std;

class Player {

public:
    Player(Side side);
    ~Player();

    std::vector<Move*> possibleMoves();
    int getSquareWeight(Move *move);
    Move *doMove(Move *opponentsMove, int msLeft);

    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
    Board board;

private:
    Side side;
};

#endif

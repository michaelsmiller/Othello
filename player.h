#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.h"
#include "board.h"
using namespace std;

class Player {
private:
    Board *board;
    Side side;
public:
    Player(Side side);
    ~Player();
    
    Move *doMove(Move *opponentsMove, int msLeft);
    int getScore(Board *b, Side s, int depth);
    Move *findBestMove(int depth);
    void setBoard(Board * b);

    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
};

#endif

#include "player.h"

#include <climits>
#include <utility>
#include <iostream>
using namespace std;

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish 
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;

    this->side = side;
    board = new Board();
}

/*
 * Destructor for the awesome player.
 */
Player::~Player() 
{
    delete board;
}

void Player::setBoard(Board * b)
{
    delete board;
    board = b;
}

int Player::getScore(Board *b, Side s, int depth)
{
    //cerr << depth << "\n";
    vector<Move*> our_valid_moves = b->getValidMoves(s);
    int best;

    //if we are at the end of the ply, we find the move
    //that will lead to the highest score
    if (depth == 0 || our_valid_moves.empty())
    {
        return b->naiveScore(side);
    }
    else //the recursive step
    {
        best = (side == s) ? INT_MIN : INT_MAX;
        for (unsigned int i = 0; i < our_valid_moves.size(); i++)
        {
            Move * move = our_valid_moves[i];
            //cerr << "(" << move->x << "," << move->y << ")\n";
            Board * v_b = b->copy();
            v_b->doMove(move, s);
            int next_best = getScore(v_b, other(s), depth - 1);
            
            bool better = (side == s) ? next_best > best
                                      : next_best < best;
            if (better)//we've found a new replacement node
                best = next_best;

            delete v_b;
        }
        
    }
    return best;
}

Move *Player::findBestMove(int depth)
{
    vector<Move*> our_valid_moves = board->getValidMoves(side);

    if (depth == 0 || our_valid_moves.empty())
    {
        //cerr << "Theres your problem\n";
        return NULL;
    }

    int best = INT_MIN;
    Move * best_move = NULL;
    //cerr << "size is " << our_valid_moves.size() << endl;
    for (unsigned int i = 0; i < our_valid_moves.size(); i++)
    {
        Move * move = our_valid_moves[i];
        //cerr << "(" << move->x << "," << move->y << ")\n";
        Board * v_b = board->copy();
        v_b->doMove(move, side);
        int next_best = getScore(v_b, other(side), depth - 1);
        
        if (next_best > best)//we've found a new replacement node
        {
            best = next_best;
            best_move = move;
        }

        delete v_b;
    }

    return best_move;
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be NULL.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return NULL.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    if (testingMinimax)
    {
        board->doMove(opponentsMove, other(side));
        Move * winner = findBestMove(2);
        board->doMove(winner, side);
        return winner;
    }
    else //normal game
    {
        board->doMove(opponentsMove, other(side)); 
        // vector<Move*> valid = board->getValidMoves(side);
        // Move * m = valid[0];
        
        Move * m = findBestMove(4);

        board->doMove(m, side);
        return m;
    }
    return NULL;
}

#include "player.h"


/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish 
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;

    /* I made a comment 
    */
    board = Board();
    this->side = side;


    /* 
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
}
//This is a small change to the player.cpp file! 
/*
 * Destructor for the player.
 */
Player::~Player() {
}

std::vector<Move*> Player::possibleMoves()
{
    std::vector<Move*> result;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
           Move *move = new Move(i, j); 
           if (board.checkMove(move, side)) 
           {
               result.push_back(move);    
           }
        }
    }
    return result;
}

int Player::getSquareWeight(Move *move)
{
    int x = move->getX();
    int y = move->getY();
    int weight[8][8]={{30, -20, 10, 6, 6, 10, -20, 30},
    {-20, -25, 1, 1, 1, 1, -25, -20},
    {10, 1, 4, 2, 2, 4, 1, 10},
    {6, 1, 2, 1, 1, 2, 1, 6},
    {6, 1, 2, 1, 1, 2, 1, 6},
    {10, 1, 4, 2, 2, 4, 1, 10},
    {-20, -25, 1, 1, 1, 1, -25, -20},
    {30, -20, 10, 6, 6, 20, -20, 30}};
    
    return weight[x][y];

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
    /* 
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */ 
     Side opside;
     if (side == BLACK)
     {
        opside = WHITE;
     }
     else
     {
        opside = BLACK;
     }
     board.doMove(opponentsMove, opside);

    if(board.hasMoves(side))
    {

        std::vector<Move*> moves = possibleMoves();
        int max_index = 0; //index of the move whose square has the highest known heuristic value
        for (unsigned i = 0; i < moves.size(); i++)
        {
            if (getSquareWeight(moves[i]) > getSquareWeight(moves[max_index]))
            {
                max_index = i;
            }

        }
        board.doMove(moves[max_index], side);
        return moves[max_index];
    }
    else
    {
        return NULL;
    }

}

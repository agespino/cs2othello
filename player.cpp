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

int Player::getSquareWeight(Move move)
{
    int x = move.getX();
    int y = move.getY();
    if((x == 0 && y == 0)||(x == 0 && y == 7)||(x == 7 && y == 0)||(x == 7 && y == 7))
    {
        return 5;
    }
    else if ((x == 1 && y == 0) || (x == 0 && y ==1) || (x == 0 && y == 6) || (x == 1 && y == 7)
        ||(x == 0 && y == 6) || (x == 7 && y == 1) || (x == 7 && y == 6)||(x == 6 && y ==7))
    {
        return -1;
    }
    else if((x == 1 && y ==1) || (x == 6 && y ==1) || (x == 6 && y == 1) || (x == 6 && y == 6))
    {
        return -3;
    }
    else if( x == 0 || x == 7 || y == 0 || y == 7)
    {
        return 2;
    }
    else 
    {
        return 1;
    }

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
        std:: vector<int> weights;

        for(int i = 0; i < possibleMoves().size(); i ++ )
        {
            weights.push_back(getSquareWeight(possibleMoves[i]));
        }
        int max = weights[0];
        int max_index = 0;

        for int(i = 0; i < weights.size(); i++)
        {
            if (weights[i] > max)
            {
                max = weights[i];
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

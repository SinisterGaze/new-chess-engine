#include "Pawn.h"

// PAWN FUNCTION DEFINITIONS
unsigned long long Pawn::getPossibleMoves()
{
    unsigned long long moves = 0;
    if (this->color == WHITE)
    {
        moves = this->position<<7 | this->position<<8 | this->position<<9;
        if(!this->hasMoved)
        {
            moves = moves | this->position << (7+8) |this->position << (8+8) | this->position << (9+8); 
        }
    }
    else if (this->color == BLACK)
    {
        moves = this->position>>7 | this->position>>8 | this->position>>9;
        if(!this->hasMoved)
        {
            moves = moves | this->position >> (7+8) | this->position >> (8+8) | this->position >> (9+8); 
        }
    }
    return moves;
}


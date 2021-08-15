#include "Pawn.h"

// PAWN FUNCTION DEFINITIONS
unsigned long long Pawn::getPossibleMoves()
{
    return this->getColor() == WHITE ? this->getPosition()<<8 : this->getPosition()>>8;
}


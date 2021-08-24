#include "Rook.h"

// PAWN FUNCTION DEFINITIONS
uint64_t Rook::getPossibleMoves(BoardState * bs)
{
    uint64_t whiteOccupied = bs->getOccupiedPositions(ALL_TYPES, WHITE);
    uint64_t blackOccupied = bs->getOccupiedPositions(ALL_TYPES, BLACK);
    return getHorizontalMoves(this->color, this->position, whiteOccupied, blackOccupied) | getVerticalMoves(this->color, this->position, whiteOccupied, blackOccupied);
}


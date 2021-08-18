#include "Pawn.h"

// PAWN FUNCTION DEFINITIONS
uint64_t Pawn::getPossibleMoves(BoardState * bs)
{
    uint64_t moves = 0;
    uint64_t whiteOccupied = bs->getOccupiedPositions(ALL_TYPES, WHITE);
    uint64_t blackOccupied = bs->getOccupiedPositions(ALL_TYPES, BLACK);
    uint64_t occupied = whiteOccupied | blackOccupied;
    if (this->color == WHITE)
    {
        if (this->position > (1ULL << 55)) return 0ULL;
        uint64_t up  = this->position << 8;
        uint64_t up_left  = this->position << 9;
        uint64_t up_right  = this->position << 7;

        if (up & ~occupied) moves |= up;
        if ((this->position & ~BOARD_COLUMNS::A) && (up_left & blackOccupied) ) moves |= up_left;
        if ((this->position & ~BOARD_COLUMNS::H) && (up_right & blackOccupied) ) moves |= up_right;

         if (!this->hasMoved && this->position < (1ULL<<15) && this->position > (1ULL<<7) && ((this->position << 16) & ~blackOccupied)) moves |= this->position << 16;
    }
    else if (this->color == BLACK)
    {
        if (this->position < (1ULL << 8)) return 0ULL;
        uint64_t down  = this->position >> 8;
        uint64_t down_left  = this->position >> 7;
        uint64_t down_right  = this->position >> 9;
        if (down & ~occupied) moves |= down;
        if ((this->position & ~BOARD_COLUMNS::A) && (down_left & whiteOccupied)) moves |= down_left;
        if ((this->position & ~BOARD_COLUMNS::H) && (down_right & whiteOccupied)) moves |= down_right;

        if (!this->hasMoved && this->position > (1ULL<<47) && this->position < (1ULL<<56) && ((this->position >> 16) & ~whiteOccupied)) moves |= this->position >> 16;
    }
    return moves;
}


#include "defines.h"

#ifndef BOARDSTATE_H
#define BOARDSTATE_H

// BOARD
class BoardState
{
    public:
        BoardState(bool initialize = true);
        ~BoardState();

        // Functions
        void displayBoardState();
        uint64_t getOccupiedPositions(uint64_t type = 0b111111, uint64_t color = 0b11);

        // Variables
        BoardState * previousState;

    protected:
        uint64_t whitePawn, whiteRook, whiteKnight, whiteBishop, whiteQueen, whiteKing;
        uint64_t blackPawn, blackRook, blackKnight, blackBishop, blackQueen, blackKing;
        uint32_t ply;
        bool hasWhiteCastled, hasBlackCastled;
        bool whiteCheck, blackCheck;   
};

#endif
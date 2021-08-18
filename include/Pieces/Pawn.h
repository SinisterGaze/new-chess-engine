#include "defines.h"
#include "Piece.h"

#ifndef PAWN_H
#define PAWN_H

class Pawn : public Piece {
    public:
        Pawn(uint64_t position, unsigned color) : Piece(position, color) {setType(PAWN);}
        uint64_t getPossibleMoves(BoardState * bs);
        
    private:
        bool hasMoved = false;
};


#endif
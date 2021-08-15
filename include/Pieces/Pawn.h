#include "defines.h"
#include "Piece.h"

#ifndef PAWN_H
#define PAWN_H

class Piece;

class Pawn : public Piece {
    public:
        Pawn(bool color, unsigned position) : Piece(color, position) {setType(PAWN);}
        unsigned long long getPossibleMoves();
};


#endif
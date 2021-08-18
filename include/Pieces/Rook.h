#include "Piece.h"

#ifndef ROOK_H

class Rook : public Piece {
    public:
        Rook(uint64_t position, unsigned color) : 
        Piece(position, color) 
        {setType(ROOK);}    
        uint64_t getPossibleMoves(BoardState * bs);
};

#endif 
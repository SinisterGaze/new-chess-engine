#include "Piece.h"
#include "utils.h"

#ifndef ROOK_H

class Rook : public Piece {
    public:
        Rook(uint64_t position, unsigned color) : 
        Piece(position, color) 
        {setType(TYPES::ROOK);}    
        uint64_t getPossibleMoves(BoardState * bs);
};

#endif 
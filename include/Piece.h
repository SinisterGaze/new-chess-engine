#include "defines.h"
#include "BoardState.h"

#ifndef PIECE_H
#define PIECE_H

class Piece {
    public:
        Piece(uint64_t position, unsigned color);
        ~Piece();
        void setPosition(uint64_t position);
        void setColor(unsigned color);
        void setType(unsigned type);
        uint64_t getPosition();
        virtual uint64_t getPossibleMoves(BoardState * bs);
        unsigned getColor();
        unsigned getType();
    
    protected:
        unsigned type;
        unsigned color;
        uint64_t position; 
};

#endif

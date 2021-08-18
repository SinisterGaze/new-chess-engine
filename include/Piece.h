#include "defines.h"
#include "BoardState.h"

#ifndef PIECE_H
#define PIECE_H

class Piece {
    public:
        Piece(uint64_t position, unsigned color);
        ~Piece();
        void setPosition(uint64_t position);
        void setColor(bool color);
        void setType(unsigned type);
        uint64_t getPosition();
        virtual uint64_t getPossibleMoves(BoardState * bs);
        bool getColor();
        unsigned getType();
    
    protected:
        unsigned type;
        bool color;
        uint64_t position; 
};

#endif

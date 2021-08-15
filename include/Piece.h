#include "defines.h"

#ifndef PIECE_H
#define PIECE_H

class BoardState;

class Piece {
    public:
        Piece(bool color = WHITE, unsigned position = -1);
        ~Piece();
        void setPosition(unsigned long long position);
        void setColor(bool color);
        void setType(unsigned type);
        unsigned long long getPosition();
        virtual unsigned long long getPossibleMoves();
        bool getColor();
        unsigned getType();
    
    protected:
        unsigned type;
        bool color;
        unsigned long long position; 
};

#endif

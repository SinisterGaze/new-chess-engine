#include "defines.h"
#include "Piece.h"

#ifndef BOARDSTATE_H
#define BOARDSTATE_H

// BOARD
class BoardState
{
    public:
        BoardState(vector<Piece*> pieces);
        BoardState();
        ~BoardState();

        // Functions
        void update();
        void displayBoardState();
        void addPiece(Piece * p);
        unsigned long long getOccupiedPositions();

        // Variables
        vector<Piece*> pieces;
};

#endif
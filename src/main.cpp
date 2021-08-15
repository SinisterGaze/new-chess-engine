#include "defines.h"
#include "BoardState.h"
#include "Piece.h"
#include "Pawn.h"
#include "utils.h"

using namespace std;

int main()
{
    BoardState * bs = new BoardState;

    /*for (auto & p : bs->pieces)
    {
        cout << "\nColor: " << toStringColor(p->getColor()) <<  ". Position: \n\n";
        displayBoard(bitboard(p->getPosition()));
        cout << "Possible moves: \n\n";
        displayBoard(bitboard(p->getPossibleMoves()));
        cout << "-------------------------------\n";
    }*/
    
    unsigned long long fullyOccupied = 0;
    for (int i = 0; i<64; i++)
    {
        fullyOccupied |= 1ULL<<i;
    }
    displayBoard(fullyOccupied);
    return 0;
}

#include "defines.h"
#include "BoardState.h"
#include "Piece.h"
#include "Rook.h"
#include "Pawn.h"
#include "utils.h"

using namespace std;

int main()
{
    BoardState * bs = new BoardState();
    Piece * R = new Rook(toBitboard("C4"), COLORS::BLACK);
    displayBoard(R->getPossibleMoves(bs));
    return 0;
}


#include "defines.h"
#include "BoardState.h"
#include "Piece.h"
#include "Pawn.h"


using namespace std;


// UTILS
int toTilePosition(unsigned long long bin)
{
    if (__builtin_popcountll(bin) != 1)
    {
        cout << "invalid position\n";
        return -1;
    }
    unsigned cnt =1;
    while(bin>>=1) cnt++;
    return cnt;
}

unsigned long long toBinaryPosition(unsigned tile)
{
    assert(tile >= 1 && tile <= 64);
    return 1ULL<<(tile-1);
}

string toStringType(unsigned type)
{
    assert(type <=5);
    switch(type) {
        case PAWN:
            return "Pawn";
            break;
        case ROOK:
            return "Rook";
            break;
        case BISHOP:
            return "Bishop";
            break;
        case KNIGHT:
            return "Knight";
            break;
        case KING:
            return "King";
            break;
        case QUEEN:
            return "Queen";
            break;
        default:
            return "No type";
    }
}

string toStringColor(bool color)
{
    assert(color == WHITE || color == BLACK);
    if (color == WHITE) return "White";
    else if (color == BLACK) return "Black";
    else return "No color";
}

void displayBoard(const bitset<64> &bit)
{
    for (unsigned i = 0; i < 64; i++)
    {
        unsigned long long currentBit = 1ULL<<(64-i-1);
        if (bit.to_ullong() & currentBit) cout << "1";
        else cout << "0";
        if ((1+i)%8==0) cout << "\n";
    }
}


int main()
{
    BoardState * bs = new BoardState;
    for (unsigned i = 0; i < 8; i++)
    {
        bs->addPiece(new Pawn(WHITE, i+8+1));
        bs->addPiece(new Pawn(BLACK, 64-i-8));
    }
    bs->displayBoardState();

    return 0;
}

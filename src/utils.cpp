#include "utils.h"

map<uint64_t, unsigned> COLUMNS = 
{   
    {BOARD_COLUMNS::A, 0},
    {BOARD_COLUMNS::B, 1},
    {BOARD_COLUMNS::C, 2},
    {BOARD_COLUMNS::D, 3},
    {BOARD_COLUMNS::E, 4},
    {BOARD_COLUMNS::F, 5},
    {BOARD_COLUMNS::G, 6},
    {BOARD_COLUMNS::H, 7}
};

map<uint64_t, unsigned> ROWS = 
{
    {BOARD_ROWS::ONE, 0},
    {BOARD_ROWS::TWO, 1},
    {BOARD_ROWS::THREE, 2},
    {BOARD_ROWS::FOUR, 3},
    {BOARD_ROWS::FIVE, 4},
    {BOARD_ROWS::SIX, 5},
    {BOARD_ROWS::SEVEN, 6},
    {BOARD_ROWS::EIGHT, 7}
};

int toTilePosition(uint64_t bin)
{
    assert(__builtin_popcountll(bin) == 1);
    unsigned cnt =1;
    while(bin>>=1) cnt++;
    return cnt;
}

uint64_t toBinaryPosition(unsigned tile)
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

void displayBoard(const uint64_t & bitboard)
{
    cout << "\n";
    for (unsigned i = 1; i <= 64; i++)
    {
        uint64_t currentBit = 1ULL<<(64-i);
        if (bitboard & currentBit) cout << "1";
        else cout << "0";
        if (i%8==0) cout << "\n";
    }
    cout << "\n";
}

void demonstrateBoardPosition()
{
    for (unsigned i = 0; i < 64; i++)
    {
        cout << "   " << (64-i < 10 ? " " : "") << (64-i) << "  "; 
        
        if ((1+i)%8==0) cout << "\n";
    }
}

unsigned getCol(const uint64_t & pos)
{
    return 0;
}

uint64_t getHorizontalMoves(const uint64_t & pos, const uint64_t & whiteOccupied, const uint64_t & blackOccupied)
{
    return 0;
}


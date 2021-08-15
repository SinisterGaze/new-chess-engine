#include "utils.h"

int toTilePosition(unsigned long long bin)
{
    assert(__builtin_popcountll(bin) == 1);
    unsigned cnt =1;
    while(bin>>=1) cnt++;
    return cnt;
}

unsigned long long toBinaryPosition(unsigned tile)
{
    assert(tile >= 1 && tile <= 64);
    return 1ULL<<(tile-1);
}

std::string toStringType(unsigned type)
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

std::string toStringColor(bool color)
{
    assert(color == WHITE || color == BLACK);
    if (color == WHITE) return "White";
    else if (color == BLACK) return "Black";
    else return "No color";
}

void displayBoard(const bitboard & bit)
{
    unsigned long long bitull = bit.to_ullong();

    for (unsigned i = 0; i < 64; i++)
    {
        unsigned long long currentBit = 1ULL<<(64-i);
        if (bitull & currentBit) std::cout << "1";
        else std::cout << "0";
        if ((i+1)%8==0) std::cout << "\n";
    }
    std::cout << "\n";
}

void demonstrateBoardPosition()
{
    for (unsigned i = 0; i < 64; i++)
    {
        std::cout << "   " << (64-i < 10 ? " " : "") << (64-i) << "  "; 
        
        if ((1+i)%8==0) std::cout << "\n";
    }
}

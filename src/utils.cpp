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

unsigned getRow(const uint64_t & pos)
{   
    unsigned row = 0;
    for (auto it = ROWS.begin(); it != ROWS.end(); it++)
    {
        if ((it->first & pos) > 0)
        {
            row = it->second;
        }
    }
    assert(row <= 7);
    return row;
}

unsigned getCol(const uint64_t & pos)
{   
    unsigned col = 0;
    for (auto it = COLUMNS.begin(); it != COLUMNS.end(); it++)
    {
        if ((it->first & pos) > 0)
        {
            col = it->second;
        }
    }
    assert(col <= 7);
    return col;
}

uint64_t toBitboard(const string & tile)
{
    assert(tile.size() == 2);
    unsigned row = (unsigned)(tile[1] -  '1');
    unsigned col = (unsigned)(tile[0] - 'A');
    assert(row <= 7 && col <=7);
    return (1ULL<<((7-col) + 8*row));
}

uint64_t toBitboard(const unsigned & row, const unsigned & col)
{
    return (1ULL<<((7-col) + 8*row));
}

/*int toTilePosition(uint64_t bin)
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
}*/

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

uint64_t getHorizontalMoves(const unsigned & color, const uint64_t & pos, const uint64_t & whiteOccupied, const uint64_t & blackOccupied)
{
    uint64_t moves = 0;
    unsigned rowPos = getRow(pos);
    unsigned colPos = getCol(pos);

    for (int col = colPos-1; col >= 0; col--)
    {
        uint64_t compare = toBitboard(rowPos, col);
        if (compare & blackOccupied)
        {
            if (color == COLORS::WHITE)
            {
                moves |= compare;
            }
            break;
        }
        else if (compare & whiteOccupied)
        {
            if (color == COLORS::BLACK)
            {
                moves |= compare;
            }
            break;
        }
        else
        {
            moves |= compare;
        }
    }
    for (int col = colPos+1; col < 8; col++)
    {
        uint64_t compare = toBitboard(rowPos, col);
        if (compare & blackOccupied)
        {
            if (color == COLORS::WHITE)
            {
                moves |= compare;
            }
            break;
        }
        else if (compare & whiteOccupied)
        {
            if (color == COLORS::BLACK)
            {
                moves |= compare;
            }
            break;
        }
        else
        {
            moves |= compare;
        }
    }
    return moves;
}

uint64_t getVerticalMoves(const unsigned & color, const uint64_t & pos, const uint64_t & whiteOccupied, const uint64_t & blackOccupied)
{
    uint64_t moves = 0;
    unsigned rowPos = getRow(pos);
    unsigned colPos = getCol(pos);

    for (int row = rowPos-1; row >= 0; row--)
    {
        uint64_t compare = toBitboard(row, colPos);
        if ((compare & blackOccupied) > 0)
        {
            if (color == COLORS::WHITE)
            {
                moves |= compare;
            }
            break;
        }
        else if ((compare & whiteOccupied) > 0)
        {
            if (color == COLORS::BLACK)
            {
                moves |= compare;
            }
            break;
        }
        else
        {
            moves |= compare;
        }
    }
    for (int row = rowPos+1; row < 8; row++)
    {
        uint64_t compare = toBitboard(row, colPos);
        if ((compare & blackOccupied) > 0)
        {
            if (color == COLORS::WHITE)
            {
                moves |= compare;
            }
            break;
        }
        else if ((compare & whiteOccupied) > 0)
        {
            if (color == COLORS::BLACK)
            {
                moves |= compare;
            }
            break;
        }
        else
        {
            moves |= compare;
        }
    }
    return moves;
}




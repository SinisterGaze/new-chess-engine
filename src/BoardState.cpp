#include "BoardState.h"

using namespace std;

// BOARD FUNCTION DEFINITIONS

BoardState::BoardState(bool initialize)
{
    if (initialize)
    {
        this->whitePawn = 0b1111111100000000;
        this->whiteRook = 0b10000001;
        this->whiteKnight = 0b01000010;
        this->whiteBishop = 0b00100100;
        this->whiteQueen = 0b00010000;
        this->whiteKing = 0b00001000;

        this->blackPawn = 0b0000000011111111000000000000000000000000000000000000000000000000;
        this->blackRook = 0b1000000100000000000000000000000000000000000000000000000000000000;
        this->blackKnight = 0b0100001000000000000000000000000000000000000000000000000000000000;
        this->blackBishop = 0b0010010000000000000000000000000000000000000000000000000000000000;
        this->blackQueen = 0b0001000000000000000000000000000000000000000000000000000000000000;
        this->blackKing = 0b0000100000000000000000000000000000000000000000000000000000000000;

        this->ply = 0;
        this->hasWhiteCastled = false;
        this->hasBlackCastled = false;
    }
}

BoardState::~BoardState()
{
    delete this->previousState;
}


void BoardState::displayBoardState()
{
    uint64_t occupied = getOccupiedPositions();
    for (unsigned i = 0; i < 64; i++)
    {
        uint64_t currentBit = 1ULL<<(64-i-1);
        if (occupied & currentBit) cout << "1";
        else cout << "0";
        if ((1+i)%8==0) cout << "\n";
    }
    cout << "\n";
}

uint64_t BoardState::getOccupiedPositions(uint64_t type, uint64_t color)
{
    uint64_t occupied = 0b0;
    if (color & 0b1)
    {
        if (type & 0b1) occupied |= whitePawn;
        if (type & 0b10) occupied |= whiteRook;
        if (type & 0b100) occupied |= whiteKnight;
        if (type & 0b1000) occupied |= whiteBishop;
        if (type & 0b10000) occupied |= whiteKing;
        if (type & 0b100000) occupied |= whiteQueen;
    }
    if (color & 0b10)
    {
        if (type & 0b1) occupied |= blackPawn;
        if (type & 0b10) occupied |= blackRook;
        if (type & 0b100) occupied |= blackKnight;
        if (type & 0b1000) occupied |= blackBishop;
        if (type & 0b10000) occupied |= blackKing;
        if (type & 0b100000) occupied |= blackQueen;
    }
    return occupied;
}
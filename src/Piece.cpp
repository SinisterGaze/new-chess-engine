#include "Piece.h"

using namespace std;

// PIECE FUNCTION DEFINITIONS

Piece::Piece(uint64_t position, unsigned color)
{
    this->color = color;
    if (position)
    {
        setPosition(position);
    }
}

Piece::~Piece()
{
    
}

void Piece::setPosition(uint64_t position)
{
    assert(__builtin_popcountll(position) == 1 && position > 0);
    this->position = position;
}

void Piece::setColor(unsigned color)
{
    assert(color == COLORS::WHITE || color == COLORS::BLACK);
    this->color = color;
}

void Piece::setType(unsigned type)
{
    this->type = type;
}

uint64_t Piece::getPosition()
{
    return this->position;
}

uint64_t Piece::getPossibleMoves(BoardState * bs)
{
    return 0;
}

unsigned Piece::getColor()
{
    return this->color;
}

unsigned Piece::getType()
{
    return this->type;
}


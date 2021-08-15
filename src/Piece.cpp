#include "Piece.h"

using namespace std;

// PIECE FUNCTION DEFINITIONS

Piece::Piece(bool color, unsigned position)
{
    this->color = color;
    assert(position >=1 && position <=64);
    if (position)
    {
        setPosition(position);
    }
}

Piece::~Piece()
{
    delete this;
}

void Piece::setPosition(unsigned long long position)
{
    assert(__builtin_popcountll(position) == 1 && position > 0);
    this->position = position;
}

void Piece::setColor(bool color)
{
    assert(color == WHITE || color == BLACK);
    this->color = color;
}

void Piece::setType(unsigned type)
{
    this->type = type;
}

unsigned long long Piece::getPosition()
{
    return this->position;
}

unsigned long long Piece::getPossibleMoves()
{
    return 0;
}

bool Piece::getColor()
{
    return this->color;
}

unsigned Piece::getType()
{
    return this->type;
}


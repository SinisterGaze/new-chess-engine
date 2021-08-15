#include "BoardState.h"

using namespace std;

// BOARD FUNCTION DEFINITIONS

BoardState::BoardState(vector<Piece*> pieces)
{
    this->pieces = pieces;
}

BoardState::BoardState()
{
    this->pieces = vector<Piece *>(0);
}

BoardState::~BoardState()
{
    for (auto & p : pieces)
    {
        delete p;
    }
    pieces.clear();
}


void BoardState::displayBoardState()
{
    unsigned long long occupied = getOccupiedPositions();
    for (unsigned i = 0; i < 64; i++)
    {
        unsigned long long currentBit = 1ULL<<(64-i-1);
        if (occupied & currentBit) cout << "1";
        else cout << "0";
        if ((1+i)%8==0) cout << "\n";
    }
    cout << "\n";
}

void BoardState::addPiece(Piece * p)
{
    this->pieces.push_back(p);
}

unsigned long long BoardState::getOccupiedPositions()
{
    unsigned long long occupied = 0;
    for (unsigned i = 0; i < pieces.size(); i++)
    {
        occupied |= pieces[i]->getPosition();
    }
    return occupied;
}
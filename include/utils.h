#include "defines.h"

#ifndef UTILS_H
#define UTILS_H


extern map<uint64_t, unsigned> COLUMNS;
extern map<uint64_t, unsigned> ROWS;

void displayBoard(const uint64_t & bitboard);
void demonstrateBoardPosition();

string toStringColor(bool color);
string toStringType(unsigned type);

int toTilePosition(uint64_t bin);
uint64_t toBinaryPosition(unsigned tile);

unsigned getCol(const uint64_t & pos);


#endif 
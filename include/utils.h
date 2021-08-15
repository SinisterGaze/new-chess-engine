#include "defines.h"

#ifndef UTILS_H
#define UTILS_H

void displayBoard(const bitboard & bit);
void demonstrateBoardPosition();

std::string toStringColor(bool color);
std::string toStringType(unsigned type);

int toTilePosition(unsigned long long bin);
unsigned long long toBinaryPosition(unsigned tile);


#endif 
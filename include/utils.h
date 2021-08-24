#include "defines.h"

#ifndef UTILS_H
#define UTILS_H


extern map<uint64_t, unsigned> COLUMNS;
extern map<uint64_t, unsigned> ROWS;

unsigned getRow(const uint64_t &pos);
unsigned getCol(const uint64_t &pos);

uint64_t toBitboard(const string & tile);
uint64_t toBitboard(const unsigned & row, const unsigned & col);

void displayBoard(const uint64_t & bitboard);
void demonstrateBoardPosition();

string toStringColor(bool color);
string toStringType(unsigned type);

/*int toTilePosition(uint64_t bin);
uint64_t toBinaryPosition(unsigned tile);
*/

uint64_t getHorizontalMoves(const unsigned & color, const uint64_t & pos, const uint64_t & whiteOccupied, const uint64_t & blackOccupied);
uint64_t getVerticalMoves(const unsigned & color, const uint64_t & pos, const uint64_t & whiteOccupied, const uint64_t & blackOccupied);


#endif 
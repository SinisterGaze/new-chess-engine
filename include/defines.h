#ifndef DEFINES_H
#define DEFINES_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <bitset>
#include <assert.h>

enum Pieces {PAWN, ROOK, KNIGHT, BISHOP, KING, QUEEN};
enum Color {BLACK, WHITE};

using namespace std;

int toTilePosition(unsigned long long bin);
unsigned long long toBinaryPosition(unsigned tile);
string toStringType(unsigned type);
string toStringColor(bool color);
void displayBoard(const bitset<64> &bit);

#endif
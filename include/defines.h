#ifndef DEFINES_H
#define DEFINES_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <bitset>
#include <assert.h>

#define bitboard bitset<64>

using namespace std;

enum Pieces {PAWN, ROOK, KNIGHT, BISHOP, KING, QUEEN};
enum Color {BLACK, WHITE};

#endif
#ifndef DEFINES_H
#define DEFINES_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <bitset>
#include <assert.h>
#include <cstdint>


using namespace std;

enum {PAWN = 1, ROOK = 2, KNIGHT = 4, BISHOP = 8, KING = 16, QUEEN = 32, ALL_TYPES = 63};

enum {WHITE = 1, BLACK = 2, BOTH_COLORS = 3};

enum edges : uint64_t {
    RIGHT = ((1ULL) + (1ULL<<8) + (1ULL<<16) + (1ULL<< 24) + (1ULL<<32) + (1ULL<<40) + (1ULL<<48) + (1ULL<<56ULL)),
    LEFT = ((1ULL<<7) + (1ULL<<(7+8))  + (1ULL<<(7+16)) + (1ULL<<(7+24)) + (1ULL<<(7+32)) + (1ULL<<(7+40)) + (1ULL<<(7+48)) + (1ULL<<(7+56)))
    };

#endif
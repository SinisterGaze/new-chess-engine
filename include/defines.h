#ifndef DEFINES_H
#define DEFINES_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <bitset>
#include <assert.h>
#include <cstdint>
#include <map>


using namespace std;

enum TYPES {PAWN = 1, ROOK = 2, KNIGHT = 4, BISHOP = 8, KING = 16, QUEEN = 32, ALL_TYPES = 63};

enum COLORS {WHITE = 1, BLACK = 2, BOTH_COLORS = 3};

enum BOARD_COLUMNS : uint64_t {
    A = ((1ULL<<7) + (1ULL<<(7+8))  + (1ULL<<(7+16)) + (1ULL<<(7+24)) + (1ULL<<(7+32)) + (1ULL<<(7+40)) + (1ULL<<(7+48)) + (1ULL<<(7+56))),

    B = ((1ULL<<6) + (1ULL<<(6+8))  + (1ULL<<(6+16)) + (1ULL<<(6+24)) + (1ULL<<(6+32)) + (1ULL<<(6+40)) + (1ULL<<(6+48)) + (1ULL<<(6+56))),

    C = ((1ULL<<5) + (1ULL<<(5+8))  + (1ULL<<(5+16)) + (1ULL<<(5+24)) + (1ULL<<(5+32)) + (1ULL<<(5+40)) + (1ULL<<(5+48)) + (1ULL<<(5+56))),

    D = ((1ULL<<4) + (1ULL<<(4+8))  + (1ULL<<(4+16)) + (1ULL<<(4+24)) + (1ULL<<(4+32)) + (1ULL<<(4+40)) + (1ULL<<(4+48)) + (1ULL<<(4+56))),

    E = ((1ULL<<3) + (1ULL<<(3+8))  + (1ULL<<(3+16)) + (1ULL<<(3+24)) + (1ULL<<(3+32)) + (1ULL<<(3+40)) + (1ULL<<(3+48)) + (1ULL<<(3+56))),

    F = ((1ULL<<2) + (1ULL<<(2+8))  + (1ULL<<(2+16)) + (1ULL<<(2+24)) + (1ULL<<(2+32)) + (1ULL<<(2+40)) + (1ULL<<(2+48)) + (1ULL<<(2+56))),

    G = ((1ULL<<1) + (1ULL<<(1+8))  + (1ULL<<(1+16)) + (1ULL<<(1+24)) + (1ULL<<(1+32)) + (1ULL<<(1+40)) + (1ULL<<(1+48)) + (1ULL<<(1+56))),

    H = ((1ULL) + (1ULL<<8) + (1ULL<<16) + (1ULL<< 24) + (1ULL<<32) + (1ULL<<40) + (1ULL<<48) + (1ULL<<56ULL))
    };

enum BOARD_ROWS : uint64_t {
    ONE = (1ULL + (1ULL<<1) + (1ULL<<2) + (1ULL<<3) + (1ULL<<4) + (1ULL<<5) + (1ULL<<6) + (1ULL<<7)),

    TWO = ((1ULL<<8) + (1ULL << (8+1)) + (1ULL << (8+2))  + (1ULL << (8+3)) + (1ULL << (8+4)) + (1ULL << (8+5)) + (1ULL << (8+6)) + (1ULL << (8+7))),

    THREE = ((1ULL<<(2*8)) + (1ULL << (2*8+1)) + (1ULL << (2*8+2))  + (1ULL << (2*8+3)) + (1ULL << (2*8+4)) + (1ULL << (2*8+5)) + (1ULL << (2*8+6)) + (1ULL << (2*8+7))),

    FOUR = ((1ULL<<(3*8)) + (1ULL << (3*8+1)) + (1ULL << (3*8+2))  + (1ULL << (3*8+3)) + (1ULL << (3*8+4)) + (1ULL << (3*8+5)) + (1ULL << (3*8+6)) + (1ULL << (3*8+7))),

    FIVE = ((1ULL<<(4*8)) + (1ULL << (4*8+1)) + (1ULL << (4*8+2))  + (1ULL << (4*8+3)) + (1ULL << (4*8+4)) + (1ULL << (4*8+5)) + (1ULL << (4*8+6)) + (1ULL << (4*8+7))),

    SIX = ((1ULL<<(5*8)) + (1ULL << (5*8+1)) + (1ULL << (5*8+2))  + (1ULL << (5*8+3)) + (1ULL << (5*8+4)) + (1ULL << (5*8+5)) + (1ULL << (5*8+6)) + (1ULL << (5*8+7))),

    SEVEN = ((1ULL<<(6*8)) + (1ULL << (6*8+1)) + (1ULL << (6*8+2))  + (1ULL << (6*8+3)) + (1ULL << (6*8+4)) + (1ULL << (6*8+5)) + (1ULL << (6*8+6)) + (1ULL << (6*8+7))),

    EIGHT = ((1ULL<<(7*8)) + (1ULL << (7*8+1)) + (1ULL << (7*8+2))  + (1ULL << (7*8+3)) + (1ULL << (7*8+4)) + (1ULL << (7*8+5)) + (1ULL << (7*8+6)) + (1ULL << (7*8+7)))
};





#endif
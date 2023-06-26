//
// Created by Magda on 23.06.2023.
//

#ifndef MIKTOPROJEKT4_BOARD_H
#define MIKTOPROJEKT4_BOARD_H
#include "Graph.h"
#include <cmath>

class Board
{
public:
    Board(int _size, int _king, int _knight, int _tower);
    int king_position() const;
    int knight_position() const;
    int row;
    char alias[25];
    Graph graph;
private:
    int king;
    int tower;
    int knight;
    bool legall_move(int curr, int next);
};

#endif //MIKTOPROJEKT4_BOARD_H

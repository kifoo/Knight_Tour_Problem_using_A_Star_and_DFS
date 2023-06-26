//
// Created by Magda on 23.06.2023.
//

#ifndef MIKTOPROJEKT4_A_STAR_H
#define MIKTOPROJEKT4_A_STAR_H
#include "Board.h"
#include <cmath>
#include <limits>
#include <vector>
#include <algorithm>
#include <iostream>

class A_Star
{
public:
    static int heuristic(int curr, int target, int size);
    static void A_Star_path (const Board &board);
    static void order_of_path(const Board &board, std::vector<int>& visited, std::vector<int>& f_score, std::vector<int>& h_score, std::vector<int>& g_score);
    static void found_path(const Board &board, const std::vector<int>& came_from, int current_place);
};

#endif //MIKTOPROJEKT4_A_STAR_H

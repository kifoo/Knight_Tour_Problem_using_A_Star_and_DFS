//
// Created by Magda on 23.06.2023.
//

#ifndef MIKTOPROJEKT4_DFS_H
#define MIKTOPROJEKT4_DFS_H
#include "Graph.h"
#include "Board.h"
#include <iostream>
#include <stack>

class DFS
{
public:
    static void DFS_path(const Board &board);
    static void appropriate_DFS_path(const Board& board);
    static void loop(const Board &board, std::vector <int> visited, std::stack <int> to_visit, std::vector<bool> temp_visited);
    static void loop2(const Board &board, std::vector <int> visited, std::stack <int> to_visit, std::vector<bool> temp_visited);
    static void found_path(const Board &board, std::vector<int>& visited);
};

#endif //MIKTOPROJEKT4_DFS_H

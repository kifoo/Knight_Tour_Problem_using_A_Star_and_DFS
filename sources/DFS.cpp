//
// Created by Magda on 23.06.2023.
//

#include "../headers/DFS.h"
// the real DFS path
void DFS::appropriate_DFS_path(const Board& board)
{
    int first = board.knight_position();
    std::vector <int> visited;
    std::stack <int> to_visit;

    const int size = board.graph.number_of_apexes();
    std::vector<bool> temp_visited(size, false);

    to_visit.push(first);
    loop2(board, visited, to_visit, temp_visited);
}

// DFS algorithm for every first move of knight
void DFS::DFS_path(const Board& board)
{
    int first = board.knight_position();
    std::vector<int> visited;
    std::stack<int> to_visit;
    std::stack<int> more_options;

    const int size = board.graph.number_of_apexes();
    std::vector<bool> temp_visited(size, false);

    visited.push_back(first);
    temp_visited[first] = true;
    for(int i = 0; i < board.graph.number_of_apexes(); i++)
    {
        if(board.graph.is_edge(first, i) and !temp_visited[i]) {
            more_options.push(i);
        }
    }

    //improving DFS to check every first move of knight
    while( !more_options.empty() ) {
        to_visit.push(more_options.top());
        loop2(board, visited, to_visit, temp_visited);
        more_options.pop();
    }
}

void DFS::loop(const Board &board, std::vector <int> visited, std::stack <int> to_visit, std::vector<bool> temp_visited) {
    while (!to_visit.empty()) {
        int current_place = to_visit.top();
        to_visit.pop();
        if (!temp_visited[current_place]) {
            visited.push_back(current_place);
            temp_visited[current_place] = true;

            if (current_place == board.king_position()) {
                found_path(board, visited);
                return;
            }

            //for (int i = 0; i < board.graph.number_of_apexes(); i++) {
            for(int i = board.graph.number_of_apexes()-1 ; i >= 0; i--){
                if (board.graph.is_edge(current_place, i) and !temp_visited[i])
                    to_visit.push(i);
            }
        }
    }
}

// loop that choose searching for neighbours based on number of place
void DFS::loop2(const Board &board, std::vector <int> visited, std::stack <int> to_visit, std::vector<bool> temp_visited) {
    while (!to_visit.empty()) {
        int current_place = to_visit.top();
        to_visit.pop();
        if (!temp_visited[current_place]) {
            visited.push_back(current_place);
            temp_visited[current_place] = true;

            if (current_place == board.king_position()) {
                found_path(board, visited);
                return;
            }
            if(current_place % 2 == 1) {
                for (int i = board.graph.number_of_apexes() - 1; i >= 0; i--) {
                    if (board.graph.is_edge(current_place, i) and !temp_visited[i])
                        to_visit.push(i);
                }
            }
            else{
                for (int i = 0; i < board.graph.number_of_apexes(); i++) {
                    if (board.graph.is_edge(current_place, i) and !temp_visited[i])
                        to_visit.push(i);
                }
            }
        }
    }
}

void DFS::found_path(const Board &board, std::vector<int> &visited) {
    std::cout << std::endl << "Found path for DFS:" << std::endl;
    for(int i = 0; i < visited.size(); i++)
        std::cout << board.alias[visited[i]] << ", ";

    std::cout << std::endl;
}



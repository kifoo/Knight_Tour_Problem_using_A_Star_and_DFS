//
// Created by Magda on 23.06.2023.
//

#include "../headers/A_Star.h"

void A_Star::A_Star_path(const Board& board) {
    int first = board.knight_position();
    const int size = board.graph.number_of_apexes();
    std::vector<int> function_g(size, std::numeric_limits<int>::max());
    std::vector<int> function_h(size);
    std::vector<int> function_f(size, std::numeric_limits<int>::max());
    std::vector<int> visited_before(size, -1);
    std::vector<int> visited;
    std::vector<int> to_visit;

    function_h[first] = heuristic(first, board.king_position(), board.row);
    function_g[first] = 0;
    function_f[first] = function_g[first] + function_h[first];
    to_visit.push_back(first);
    int current;
    while ( !to_visit.empty()) {

        int temp = std::numeric_limits<int>::max();
        for(int i = 0; i < to_visit.size(); i++)
        {
            temp = std::min(temp, function_f[to_visit[i]]);
            if(temp == function_f[to_visit[i]])
                current = to_visit[i];
        }
        if (current == board.king_position()) {
            visited.push_back(current);
            order_of_path(board, visited, function_f, function_h, function_g);
            found_path(board, visited_before, board.king_position());
            return;
        }

        to_visit.erase(std::find(to_visit.begin(), to_visit.end(), current));
        visited.push_back(current);

        for (int i = 0; i < size; i++) {
            if (board.graph.is_edge(current, i) and
                std::find(visited.begin(), visited.end(), i) == visited.end()) {
                int temp_g_function = function_g[current] + 1;
                if (temp_g_function < function_g[i]) {
                    visited_before[i] = current;
                    function_g[i] = temp_g_function;
                    function_h[i] = heuristic(i, board.king_position(), board.row);
                    function_f[i] = function_g[i] + function_h[i];
                    if (std::find(to_visit.begin(), to_visit.end(), i) == to_visit.end())
                        to_visit.push_back(i);
                }
            }
        }
    }
}

int A_Star::heuristic(int curr, int target, int size) {
    return abs(curr / size - target / size) + abs(curr % size - target % size);
}

void A_Star::found_path(const Board &board, const std::vector<int>& came_from, int current_place) {
    std::vector<int> total_path;
    total_path.push_back(current_place);
    while (came_from[current_place] != -1) {
        current_place = came_from[current_place];
        total_path.push_back(current_place);
    }
    std::cout << std::endl << "Found path for A*:" << std::endl;
    for(auto it = total_path.end()-1; it >= total_path.begin(); it--)
        std::cout << board.alias[*it] << " ";
    std::cout << std::endl;

}

void A_Star::order_of_path(const Board &board, std::vector<int> &visited, std::vector<int> &f_score, std::vector<int> &h_score,
                           std::vector<int> &g_score) {
    std::cout << std::endl << "A* -> visited nodes:" << std::endl;
    for (int i = 0; i < visited.size(); ++i) {
        std::cout << board.alias[visited[i]] << " " << i + 1
                  << ", f = " << f_score[visited[i]]
                  << ", h = " << h_score[visited[i]]
                  << ", g = " << g_score[visited[i]] << std::endl;
    }
}
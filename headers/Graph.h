//
// Created by Magda on 23.06.2023.
//

#ifndef MIKTOPROJEKT4_GRAPH_H
#define MIKTOPROJEKT4_GRAPH_H
#include <vector>
#include <algorithm>

class Graph
{
private:
    std::vector<std::vector<int>> neighbours; // tablica sasiedztwa
    int number;
public:
    Graph(int apex);
    void add_edge(int curr, int next);
    bool is_edge(int curr, int next) const ;
    int number_of_apexes() const;
};


#endif //MIKTOPROJEKT4_GRAPH_H

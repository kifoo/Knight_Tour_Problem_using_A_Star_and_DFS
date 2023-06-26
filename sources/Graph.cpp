//
// Created by Magda on 23.06.2023.
//

#include "../headers/Graph.h"

Graph::Graph(int apex): number(apex), neighbours(apex) {}

// adding moves to make for knight
void Graph::add_edge(int curr, int next)
{
    neighbours[curr].push_back(next);
    neighbours[next].push_back(curr);
}

// check if edge is in neighbors of curr or not
bool Graph::is_edge(int curr, int next) const
{
    return std::find(neighbours[curr].begin(), neighbours[curr].end(), next) != neighbours[curr].end();
}

int Graph::number_of_apexes() const
{
    return number;
}

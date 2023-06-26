#include "headers/DFS.h"
#include "headers/A_Star.h"

int main()
{
    // 5x5, king H(7), knight W(22), tower A(0)
    Board board(5, 7, 22, 0);
    DFS::DFS_path(board);
    A_Star::A_Star_path(board);
    DFS::appropriate_DFS_path(board);

    return 0;
}
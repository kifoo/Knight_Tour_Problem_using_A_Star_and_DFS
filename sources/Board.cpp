//
// Created by Magda on 23.06.2023.
//

#include "../headers/Board.h"

Board::Board(int _size, int _king, int _knight, int _tower):
        king(_king), tower(_tower), knight(_knight), graph(_size*_size), row(_size)
{
    int field = row * row;
    for(int i = 0; i < field; i++)
        alias[i] = 'A' + i;

    // every place checks for his neighbours -> places he can hop
    for(int i = 0; i < field ; i++)
        for(int j = (i - 1 - 2*row>0)? (i - 1 - 2*row) : 0;  ((i + 1 + 2*row < field) ? (j <= (i + 1 + 2*row)) : (j < field)) ; j++)
        {
            if(legall_move(i, j))
            {
                if( !graph.is_edge(i, j))
                    graph.add_edge(i, j);
            }
        }
}

bool Board::legall_move(int curr, int next) // z curr do next
{
    int A_x = curr / row;  // row curr
    int A_y = curr % row;  // column curr
    int B_x = next / row;  // row next
    int B_y = next % row;  // column next

    // check if it is tower action move
    if((tower / row == B_x or tower % row == B_y) or (tower / row == A_x or tower % row == A_y))
        return false;

    int d_x = abs(B_x - A_x);  // difference of rows between curr and next
    int d_y = abs(B_y - A_y);  // difference of columns between curr and next

    if ((d_x == 1 and d_y == 2) or (d_x == 2 and d_y == 1))
        return true;

    return false;
}

int Board::king_position() const {
    return king;
}

int Board::knight_position() const {
    return knight;
}


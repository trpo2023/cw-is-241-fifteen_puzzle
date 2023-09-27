#include "move.h"
#include "board.h"
#include "file_io.h"
#include <stdio.h>

bool processMove(char move)
{
    int newRow = emptyRow;
    int newCol = emptyCol;

    switch (move) {
    case 'w':
        newRow = emptyRow - 1;
        break;
    case 's':
        newRow = emptyRow + 1;
        break;
    case 'a':
        newCol = emptyCol - 1;
        break;
    case 'd':
        newCol = emptyCol + 1;
        break;
    case 'q':
        exitGame();
        return true;
    default:
        return false;
    }

    if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE) {
        board[emptyRow][emptyCol] = board[newRow][newCol];
        board[newRow][newCol] = 0;
        emptyRow = newRow;
        emptyCol = newCol;
        return true;
    }

    return false;
}

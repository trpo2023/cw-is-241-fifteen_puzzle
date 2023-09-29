#include "board.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int board[SIZE][SIZE];
int emptyRow, emptyCol;

void initializeBoard()
{
    int num = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = num++;
        }
    }
    board[SIZE - 1][SIZE - 1] = 0;
    emptyRow = SIZE - 1;
    emptyCol = SIZE - 1;
}

void shuffleBoard(int numShuffles)
{
    srand(time(NULL));
    int newRow, newCol;

    for (int i = 0; i < numShuffles; i++) {
        int randomMove = rand() % 4;

        switch (randomMove) {
        case 0:
            newRow = emptyRow - 1;
            newCol = emptyCol;
            break;
        case 1:
            newRow = emptyRow + 1;
            newCol = emptyCol;
            break;
        case 2:
            newRow = emptyRow;
            newCol = emptyCol - 1;
            break;
        case 3:
            newRow = emptyRow;
            newCol = emptyCol + 1;
            break;
        default:
            continue;
        }

        if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE) {
            board[emptyRow][emptyCol] = board[newRow][newCol];
            board[newRow][newCol] = 0;
            emptyRow = newRow;
            emptyCol = newCol;
        }
    }
}

void displayBoard()
{
    printf("\n  ------------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("  |");
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                printf("   |");
            } else {
                if (i == emptyRow && j == emptyCol) {
                    printf("  *|"); // Выделение текущей позиции игрока
                } else {
                    printf(" %2d|", board[i][j]);
                }
            }
        }
        printf("\n  ------------------\n");
    }
}

int isGameFinished()
{
    int num = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != num++) {
                if (num == SIZE * SIZE && board[i][j] == 0) {
                    return 1;
                }
                return 0;
            }
        }
    }
    return 0;
}
#pragma once

#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

#define SIZE 4

extern int board[SIZE][SIZE];
extern int emptyRow, emptyCol;

void initializeBoard();
void shuffleBoard(int numShuffles);
void displayBoard();
int isGameFinished();

#endif /* BOARD_H */

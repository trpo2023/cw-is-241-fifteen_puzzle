#include "board.h"
#include "file_io.h"
#include "move.h"
#include <ctest.h>

CTEST(processMove, validMoves)
{
    initializeBoard();
    emptyRow = 1;
    emptyCol = 1;

    ASSERT_TRUE(processMove('w'));
    ASSERT_TRUE(processMove('a'));
    ASSERT_TRUE(processMove('s'));
    ASSERT_TRUE(processMove('d'));

    // Проверяем, что доска изменилась
    ASSERT_NOT_EQUAL(board[1][1], 0);
    ASSERT_EQUAL(board[emptyRow][emptyCol], 0);
}

CTEST(processMove, invalidMoves)
{
    initializeBoard();
    emptyRow = 0;
    emptyCol = 0;

    // Попытки выхода за границы доски
    ASSERT_FALSE(processMove('w'));
    ASSERT_FALSE(processMove('a'));

    emptyRow = SIZE - 1;
    emptyCol = SIZE - 1;

    // Попытки выхода за границы доски
    ASSERT_FALSE(processMove('s'));
    ASSERT_FALSE(processMove('d'));
}

CTEST(processMove, specialMoves)
{
    initializeBoard();
    emptyRow = 1;
    emptyCol = 1;
    ASSERT_TRUE(processMove('q'));
}

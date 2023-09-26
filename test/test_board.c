#include<board.h>
#include<ctest.h>

CTEST(board, initializeBoard) {
    initializeBoard();
    // Проверяем, что доска была инициализирована правильно
    ASSERT_EQUAL(0, board[SIZE - 1][SIZE - 1]);
}

CTEST(board, shuffleBoard) {
    initializeBoard();
    int originalBoard[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            originalBoard[i][j] = board[i][j];
        }
    }
    shuffleBoard(100);
    // Проверяем, что хотя бы одна ячейка изменила своё значение
    bool changed = false;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != originalBoard[i][j]) {
                changed = true;
                break;
            }
        }
    }
    ASSERT_TRUE(changed);
}

CTEST(board, isGameFinished) {
    initializeBoard();
    // Проверяем, что изначально игра не завершена
    ASSERT_FALSE(isGameFinished());

    shuffleBoard(100);
    // Переводим доску в завершенное состояние
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
        board[i][j] = i * SIZE + j + 1;
    }
    }
    board[SIZE - 1][SIZE - 1] = 0;

    // Проверяем, что теперь игра завершена
   ASSERT_FALSE(isGameFinished());
}

#include "board.h"
#include "file_io.h"
#include "move.h"
#include <stdio.h>

int main()
{
    int numShuffles = 1000;

    initializeBoard();
    shuffleBoard(numShuffles);

    printf("Добро пожаловать в игру 'Пятнашки'!\n");
    printf("Цель игры - упорядочить плитки по порядку от 1 до 15.\n");
    printf("Используйте клавиши 'w', 's', 'a' и 'd' для перемещения плиток.\n");
    printf("Для выхода используйте клавишу 'q'.\n");

    while (!isGameFinished()) {
        displayBoard();
        char move;
        printf("Введите ход: ");
        scanf(" %c", &move);

        if (!processMove(move)) {
            printf("Неверный ход. Попробуйте еще раз.\n");
        }
    }
    displayBoard();
    if (isGameFinished()) {
        printf("Поздравляем, вы выиграли!\n");
    }

    return 0;
}
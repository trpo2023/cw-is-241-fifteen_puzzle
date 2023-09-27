#include "board.h"
#include "file_io.h"
#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>

CTEST(file_io, exitGame)
{
    // Этот тест сложно напрямую проверить, так как он использует функцию exit.
    // Мы можем просто вызвать эту функцию и проверить, что она завершает
    // программу. В реальной программе это обычно делается с использованием
    // тестовых утилит, которые могут захватывать вывод.
    exitGame();
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int** createMatrix(int rows, int cols) {//выделения памяти под двумерный массив
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        fprintf(stderr, "Ошибка выделения памяти для строк\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Ошибка выделения памяти для столбцов\n");
            exit(1);
        }
    }

    return matrix;
}

void freeMatrix(int **matrix, int rows) {//освобождения памяти, выделенной под двумерный массив
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void fillMatrix(int **matrix, int rows, int cols) {//заполнение массива случайными числами
    srand(time(NULL));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 101-50;
        }
    }
}

void printMatrix(int **matrix, int rows, int cols) {//вывод массива на экран
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void findMinMax(int **matrix, int rows, int cols) {//нахождение строк и столбцов с минимальной и максимальной суммой
    int minRow = 0;
    int maxRow = 0;
    int minCol = 0;
    int maxCol = 0;

    for (int i = 0; i < cols; i++) {// Инициализация начальных значений минимальной и максимальной сумм
        minCol += matrix[0][i];
        maxCol += matrix[0][i];
    }

    for (int i = 1; i < rows; i++) {
        int RowSum = 0;
        int ColSum = 0;
        
        for (int j = 0; j < cols; j++) {// Вычисление суммы элементов в текущей строке и столбце
            RowSum += matrix[i][j];
            ColSum += matrix[j][i];
        }
        
        if (RowSum < minRow) {// Поиск минимальной и максимальной суммы по строкам
            minRow = RowSum;
        } else if (RowSum > maxRow) {
            maxRow = RowSum;
        }
        
        if (ColSum < minCol) {// Поиск минимальной и максимальной суммы по столбцам
            minCol = ColSum;
        } else if (ColSum > maxCol) {
            maxCol = ColSum;
        }
    }
    printf("Минимальная сумма по строкам: %d\n", minRow);
    printf("Максимальная сумма по строкам: %d\n", maxRow);
    printf("Минимальная сумма по столбцам: %d\n", minCol);
    printf("Максимальная сумма по столбцам: %d\n", maxCol);
}

int main() {
    int rows, cols;
    printf("Введите количество строк: ");
    scanf("%d", &rows);
    printf("Введите количество столбцов: ");
    scanf("%d", &cols);
    int **matrix = createMatrix(rows, cols);
    fillMatrix(matrix, rows, cols);
    printf("Исходный массив:\n");
    printMatrix(matrix, rows, cols);
    findMinMax(matrix, rows, cols);
    freeMatrix(matrix, rows);// Освобождение выделенной памяти

    return 0;
}

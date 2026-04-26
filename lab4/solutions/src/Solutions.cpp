//
// Created by irina on 13.04.2026.
//

#include "../include/Solutions.h"

#include <iostream>

#include "../../arrays/include/OneDimensionArrays.h"
#include "../../arrays/include/ThreeDimensionArrays.h"
#include "../../arrays/include/TwoDimensionArrays.h"

using namespace std;

void TaskOne() {
    cout << "\n Задание 1 Определить, есть ли в целочисленном массиве М (15) пары соседних одинаковых элементов. \n";
    int array_size;
    cout << "Введите размер массива: ";
    cin >> array_size;
    bool found = false;
    const auto array = NewOneDimensionArray(array_size);
    FillOneDimensionArrayWithNumbers(array, array_size);
    for (int i = 0; i < array_size-1; i++) {
        if (array[i] == array[i+1]) {
            found = true;
            break;
        }
    }
    if (found) cout << "Есть пары одинаковых элементов\n";
    else cout << "Пар нет\n";
    delete[] array;
}

void TaskOneWithPointerArithmetic() {
    cout << "\n Задание 1 Определить, есть ли в целочисленном массиве М (15) пары соседних одинаковых элементов. \n";
    int array_size;
    cin >> array_size;
    int* array = NewOneDimensionArray(array_size);
    FillOneDimensionArrayWithNumbersWithPointerArithmetic(array, array_size, 1, 10);

    bool found = false;
    const int* end = array + array_size;

    for (const int* ptr = array; ptr < end - 1; ptr++) {
        if (*ptr == *(ptr + 1)) {
            found = true;
            break;
        }
    }
    cout << "Массив:";
    PrintOneDimensionArray(array, array_size);
    if (found) cout << "\nЕсть пары одинаковых элементов\n";
    else cout << "\nПар нет\n";

    delete[] array;
}


void TaskTwo() {
    cout << "Найти наибольший отрицательный элемент одномерного массива и удалить его,"
            " сдвинув оставшиеся элементы к началу массива."
            "Если в массиве несколько элементов имеют наибольшее отрицательное значение, "
            "удалить их все. Массив, все элементы которого отрицательны и равны между собой,"
            " признается некорректным. \n";
    int array_size;
    cout << "Введите количество элементов в массиве" << endl;
    cin >> array_size;
    auto array = NewOneDimensionArray(array_size);
    FillOneDimensionArrayWithNumbers(array, array_size, -100, 100);
    int max_negative = FindMaxNegativeNumber(array, array_size);
    cout << "Массив до удаления элементов";
    PrintOneDimensionArray(array, array_size);
    if (max_negative < 0) {
        cout << "Максимальный отрицательный элемент в массиве" << max_negative <<endl;
        DeleteElementFromArray(array, array_size, max_negative);
        cout << "Массив после удаления элементов";
        PrintOneDimensionArray(array, array_size);
    }
    else {
        cout << "В массиве нет отрицательных чисел";
        PrintOneDimensionArray(array, array_size);
    }
    delete [] array;
}


void TaskThree() {
    cout << " Дана вещественная матрица D (7х9). "
            "Упорядочить (переставить) строки матрицы по неубыванию наименьших "
            "элементов строк. Если в строке все элементы имеют одно значение, "
            "считать его наименьшим. \n";
    int columns, rows;
    cout << "Введите количество строк в матрице" << endl;
    cin >> columns;
    cout << "Введите количество столбцов в матрице" << endl;
    cin >> rows;
    const auto array = NewTwoDimensionArrayDouble(rows, columns);
    const auto array_with_min_elements = NewOneDimensionArrayDouble(rows);
    FillTwoDimensionArrayWithNumbersDouble(array, rows, columns);
    std::cout << "Вывод не отсортированного массива: \n";
    PrintTwoDimensionArray(array, rows, columns);
    for (int i = 0; i < rows; i++) {
        array_with_min_elements[i] = FindMinElement(array[i], columns);
    }
    for (int i = 0; i < rows - 1; i++) {

        bool swapped = false;

        for (int j = 0; j < rows - i - 1; j++) {
            if (array_with_min_elements[j] > array_with_min_elements[j + 1]) {
                std::swap(array_with_min_elements[j], array_with_min_elements[j + 1]);
                std::swap(array[j], array[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
    std::cout << "Вывод отсортированного массива: \n";
    PrintTwoDimensionArray(array, rows, columns);
    DeleteTwoDimensionArray(array, rows);
}

void TaskFour() {
    cout << "Задание 4. Вычислить среднее арифметическое значение элементов "
            "квадратной матрицы, лежащих слева от главной диагонали. \n";
    int rows;
    int elementCounter = 0;
    int elementsSum = 0;
    cout << "Введите количество строк и столбцов в матрице" << endl;
    cin >> rows;
    const auto array = NewTwoDimensionArray(rows, rows);
    FillTwoDimensionArrayWithNumbers(array, rows, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (i > j) {
                elementsSum += array[i][j];
                elementCounter++;
            }
        }
    }
    DeleteTwoDimensionArray(array, rows);
    cout << "Среднее арифметическое значение элементов "
            "квадратной матрицы, лежащих слева от главной диагонали " << (elementsSum * 0.1)/elementCounter << endl;
}

void TaskFive() {
    cout << "Задание 5. Трехмерный массив описывает школьный журнал одного класса. "
            "Каждая страница журнала содержит оценки N учеников за М уроков по одному предмету "
            "(в каждой строке – оценки одного ученика, в каждой колонке – оценки за один урок). "
            "В журнале L страниц – по количеству изучаемых школьниками предметов. Пусть N=26, M=48, L=14. "
            "Определить, есть ли в классе ученики, которые учатся без двоек. \n";
    int columns, rows, depth;
    cout << "Введите количество учеников" << endl;
    cin >> columns;
    cout << "Введите количество предметов" << endl;
    cin >> rows;
    cout << "Введите количество страниц" << endl;
    cin >> depth;
    const auto array = NewThreeDimensionArray(depth, rows, columns);
    FillThreeDimensionArrayWithNumbers(array, depth, rows, columns, 2, 5);
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < rows; j++) {
            for (int z = 0; z < columns; z++) {
                if (array[i][j][z] == 2) {
                    cout << "В классе есть ученики, которые учатся на двойки" << endl;
                    DeleteThreeDimensionArray(array, depth, rows);
                    return;
                }
            }
        }
    }
    cout << "В классе все ученики учатся хорошо" << endl;
    DeleteThreeDimensionArray(array, depth, rows);
}
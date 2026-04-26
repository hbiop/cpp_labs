//
// Created by irina on 13.04.2026.
//

#include "../include/Solutions.h"

#include <iostream>

#include "../../arrays/include/OneDimensionArrays.h"
#include "../../arrays/include/ThreeDimensionArrays.h"
#include "../../arrays/include/TwoDimensionArrays.h"

using namespace std;

void task1() {
    cout << "Задание 1 Определить, есть ли в целочисленном массиве М (15) пары соседних одинаковых элементов. \n";
    int N;
    cout << "Введите размер массива: ";
    cin >> N;
    auto array = newOneDimensionArray(N);
    fillOneDimensionArrayWithNumbers(array, N);
    for (int i = 0; i < N-1; i++) {
        if (array[i] == array[i+1]) {
            cout << "В массиве есть пары соседних одинаковых элементов \n";
            delete[] array;
            return;
        }
    }
    delete[] array;
    cout << "В массиве есть нет пары соседних одинаковых элементов \n";
}

void task2() {
    cout << "Найти наибольший отрицательный элемент одномерного массива и удалить его,"
            " сдвинув оставшиеся элементы к началу массива."
            "Если в массиве несколько элементов имеют наибольшее отрицательное значение, "
            "удалить их все. Массив, все элементы которого отрицательны и равны между собой,"
            " признается некорректным. \n";
    int N;
    cout << "Введите количество элементов в массиве" << endl;
    cin >> N;
    auto array = newOneDimensionArray(N);
    fillOneDimensionArrayWithNumbers(array, N, -100, 100);
    int maxNegative = findMaxNegativeNumber(array, N);
    cout << "Массив до удаления элементов";
    printOneDimensionArray(array, N);
    if (maxNegative < 0) {
        cout << "Максимальный отрицательный элемент в массиве" << maxNegative <<endl;
        deleteElementFromArray(array, N, maxNegative);
        cout << "Массив после удаления элементов";
        printOneDimensionArray(array, N);
    }
    else {
        cout << "В массиве нет отрицательных чисел";
        printOneDimensionArray(array, N);
    }
    delete [] array;
}


void task3() {
    cout << " Дана вещественная матрица D (7х9). "
            "Упорядочить (переставить) строки матрицы по неубыванию наименьших "
            "элементов строк. Если в строке все элементы имеют одно значение, "
            "считать его наименьшим. \n";
    int N, M;
    cout << "Введите количество строк в матрице" << endl;
    cin >> N;
    cout << "Введите количество столбцов в матрице" << endl;
    cin >> M;
    auto array = newTwoDimensionArrayDouble(M, N);
    auto array_with_min_elements = newOneDimensionArrayDouble(M);
    fillTwoDimensionArrayWithNumbersDouble(array, M, N);
    std::cout << "Вывод не отсортированного массива: \n";
    printTwoDimensionArray(array, M, N);
    for (int i = 0; i < M; i++) {
        array_with_min_elements[i] = findMinElement(array[i], N);
    }
    for (int i = 0; i < M - 1; i++) {

        bool swapped = false;

        for (int j = 0; j < M - i - 1; j++) {
            if (array_with_min_elements[j] > array_with_min_elements[j + 1]) {
                std::swap(array_with_min_elements[j], array_with_min_elements[j + 1]);
                std::swap(array[j], array[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
    std::cout << "Вывод отсортированного массива: \n";
    printTwoDimensionArray(array, M, N);
    deleteTwoDimensionArray(array, M);
}

void task4() {
    cout << "Задание 4. Вычислить среднее арифметическое значение элементов "
            "квадратной матрицы, лежащих слева от главной диагонали. \n";
    int N;
    int elementCounter = 0;
    int elementsSum = 0;
    cout << "Введите количество строк и столбцов в матрице" << endl;
    cin >> N;
    auto array = newTwoDimensionArray(N, N);
    fillTwoDimensionArrayWithNumbers(array, N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > j) {
                elementsSum += array[i][j];
                elementCounter++;
            }
        }
    }
    deleteTwoDimensionArray(array, N);
    cout << "Среднее арифметическое значение элементов "
            "квадратной матрицы, лежащих слева от главной диагонали " << (elementsSum * 0.1)/elementCounter << endl;
}

void task5() {
    cout << "Задание 5. Трехмерный массив описывает школьный журнал одного класса. "
            "Каждая страница журнала содержит оценки N учеников за М уроков по одному предмету "
            "(в каждой строке – оценки одного ученика, в каждой колонке – оценки за один урок). "
            "В журнале L страниц – по количеству изучаемых школьниками предметов. Пусть N=26, M=48, L=14. "
            "Определить, есть ли в классе ученики, которые учатся без двоек. \n";
    int N, M, L;
    cout << "Введите количество учеников" << endl;
    cin >> N;
    cout << "Введите количество предметов" << endl;
    cin >> M;
    cout << "Введите количество страниц" << endl;
    cin >> L;
    auto array = newThreeDimensionArray(L, M, N);
    fillThreeDimensionArrayWithNumbers(array, L, M, N, 2, 5);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            for (int z = 0; z < N; z++) {
                if (array[i][j][z] == 2) {
                    cout << "В классе есть ученики, которые учатся на двойки" << endl;
                    deleteThreeDimensionArray(array, L, M);
                    return;
                }
            }
        }
    }
    cout << "В классе все ученики учатся хорошо" << endl;
    deleteThreeDimensionArray(array, L, M);
}
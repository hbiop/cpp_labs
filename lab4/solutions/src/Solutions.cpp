//
// Created by irina on 13.04.2026.
//

#include "../include/Solutions.h"

#include <iostream>

#include "../../arrays/include/OneDimensionArrays.h"
#include "../../arrays/include/ThreeDimensionArrays.h"
#include "../../arrays/include/TwoDimensionArrays.h"

using namespace std;


void lab4::TaskOne() {
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

void lab4::TaskOneWithPointerArithmetic() {
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


void lab4::TaskTwo() {
    cout << "\n--- Задание 2: Удаление макс. отрицательного ---\n";
    int size;
    cout << "Введите размер: "; cin >> size;
    int* array = NewOneDimensionArray(size);
    FillOneDimensionArrayWithNumbers(array, size, -10, 10);

    cout << "Исходный массив: "; PrintOneDimensionArray(array, size); cout << endl;

    int max_neg = 0;
    bool found = false;
    for(int i = 0; i < size; i++) {
        if (array[i] < 0) {
            if (!found || array[i] > max_neg) {
                max_neg = array[i];
                found = true;
            }
        }
    }

    if (found) {
        cout << "Удаляем элемент: " << max_neg << endl;
        DeleteElementFromArray(array, size, max_neg); // Функция из моего прошлого сообщения
        cout << "Результат: "; PrintOneDimensionArray(array, size); cout << endl;
    } else {
        cout << "Отрицательных элементов нет." << endl;
    }
    delete[] array;
}


void lab4::TaskThree() {
    int r, c;
    cout << "Строк: "; cin >> r;
    cout << "Столбцов: "; cin >> c;
    double** D = NewTwoDimensionArrayDouble(r, c);
    double* min_elements = NewOneDimensionArrayDouble(r);
    FillTwoDimensionArrayWithNumbersDouble(D, r, c, -50, 50);

    for (int i = 0; i < r; i++)
        min_elements[i] = FindMinElement(D[i], c);

    for (int i = 0; i < r - 1; i++) {
        for (int j = 0; j < r - i - 1; j++) {
            if (min_elements[j] > min_elements[j + 1]) {
                swap(min_elements[j], min_elements[j+1]);
                swap(D[j], D[j+1]);
            }
        }
    }

    cout << "Матрица:\n";
    PrintTwoDimensionArray(D, r, c);

    delete[] min_elements;
    DeleteTwoDimensionArray(D, r);
}

void lab4::TaskFour() {
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

void lab4::TaskFive() {
    int n, m, l;
    cout << "Учеников: "; cin >> n;
    cout << "Уроков: "; cin >> m;
    cout << "Предметов: "; cin >> l;
    int*** journal = NewThreeDimensionArray(l, n, m);
    FillThreeDimensionArrayWithNumbers(journal, l, n, m, 2, 5);

    int good_students_count = 0;
    for (int student = 0; student < n; student++) {
        bool has_two = false;
        for (int subj = 0; subj < l; subj++) {
            for (int lesson = 0; lesson < m; lesson++) {
                if (journal[subj][student][lesson] == 2) {
                    has_two = true; break;
                }
            }
            if (has_two) break;
        }
        if (!has_two) good_students_count++;
    }

    if (good_students_count > 0)
        cout << "Найдено учеников без двоек: " << good_students_count << endl;
    else
        cout << "В этом классе у всех есть двойки." << endl;

    DeleteThreeDimensionArray(journal, l, n);
}
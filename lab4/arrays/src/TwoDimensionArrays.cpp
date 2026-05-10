

#include "../include/TwoDimensionArrays.h"

#include <iomanip>
#include <iostream>

#include "../include/OneDimensionArrays.h"

int **NewTwoDimensionArray(const int rows, const int columns) {
    auto array = new int*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = NewOneDimensionArray(columns);
    }
    return array;
}

double **NewTwoDimensionArrayDouble(const int rows, const int columns) {
    auto array = new double*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = NewOneDimensionArrayDouble(columns);
    }
    return array;
}

void DeleteTwoDimensionArray(int** array, const int rows) {
    for (int i = 0; i < rows; i++) {
        delete [] array[i];
    }
    delete [] array;
}

void DeleteTwoDimensionArray(double** array, const int rows) {
    for (int i = 0; i < rows; i++) {
        delete [] array[i];
    }
    delete [] array;
}

void FillTwoDimensionArrayWithNumbers(int **array, const int rows, const int columns, const int min, const int max) {
    for (int i = 0; i < rows; i++) {
        FillOneDimensionArrayWithNumbers(array[i], columns, min, max);
    }
}

void FillTwoDimensionArrayWithNumbersDouble(double **array, const int rows, const int columns, const int min, const int max) {
    for (int i = 0; i < rows; i++) {
        FillOneDimensionArrayWithNumbersDouble(array[i], columns, min, max);
    }
}

void PrintTwoDimensionArray(double** array, int rows, int columns) {
    for (int j = 0; j < columns; j++) {
        for (int i = 0; i < rows; i++) {
            std::cout << std::fixed << std::setprecision(2) << std::setw(8) << array[i][j];
        }
        std::cout << std::endl;
    }
}
void PrintTwoDimensionArray(int** array, int rows, int columns) {
    for (int j = 0; j < columns; j++) {
        for (int i = 0; i < rows; i++) {
            std::cout << std::fixed << std::setprecision(2) << std::setw(8) << array[i][j];
        }
        std::cout << std::endl;
    }
}

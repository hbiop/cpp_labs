
#include "../include/OneDimensionArrays.h"

#include <iostream>
#include <iomanip>

#include "../../generators/include/RandomNumberGenerators.h"

int *NewOneDimensionArray(int array_size) {
    return new int[array_size];
}

double *NewOneDimensionArrayDouble(int array_size) {
    return new double[array_size];
}

void FillOneDimensionArrayWithNumbers(int *array, int array_size, int min, int max) {
    for (int i = 0; i < array_size; i++) {
        array[i] = GenerateRandomNumber(min, max);
    }
}

void FillOneDimensionArrayWithNumbersWithPointerArithmetic(int* array_ptr, int array_size, int min, int max) {
    int* end = array_ptr + array_size;
    for (int* p = array_ptr; p < end; p++) {
        *p = GenerateRandomNumber(min, max);
    }
}
void FillOneDimensionArrayWithNumbersDouble(double* array, int array_size, int min, int max) {
    for (int i = 0; i < array_size; i++) {
        array[i] = GenerateRandomNumber(min, max);
    }
}

void PrintOneDimensionArray(int *array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        std::cout << array[i] << " ";
    }
}

void PrintOneDimensionArray(double *array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        std::cout << std::fixed << std::setprecision(2) << array[i] << " ";
    }
    std::cout << std::endl;
}

double FindMinElement(double *array, int array_size) {
    double min = array[0];
    for (int i = 1; i < array_size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int FindMaxNegativeNumber(int *array, int array_size) {
    int max_negative = array[0];
    for (int i = 1; i < array_size; i++) {
        if (max_negative >= 0 && array[i] < 0) {
            max_negative = array[i];
        }
        if (array[i] > max_negative && array[i] < 0) {
            max_negative = array[i];
        }
    }
    if (max_negative >= 0) {
        return 1;
    }
    return max_negative;
}

void DeleteElementFromArray(int* &array, int &array_size, int element) {
    int* temp_array = new int[array_size];
    int new_size = 0;

    for (int i = 0; i < array_size; i++) {
        if (array[i] != element) {
            temp_array[new_size++] = array[i];
        }
    }

    delete[] array;

    if (new_size < array_size) {
        if (new_size == 0) {
            array = nullptr;
            delete[] temp_array;
        } else {
            array = new int[new_size];
            for (int i = 0; i < new_size; i++) {
                array[i] = temp_array[i];
            }
            delete[] temp_array;
        }
    } else {
        array = temp_array;
    }

    array_size = new_size;
}
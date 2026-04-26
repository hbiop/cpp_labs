
#include "../include/ThreeDimensionArrays.h"
#include "../include/TwoDimensionArrays.h"

int ***NewThreeDimensionArray(const int depth, const int rows, const int columns) {
    const auto array = new int**[depth];
    for (int i = 0; i < depth; i++) {
        array[i] = NewTwoDimensionArray(rows, columns);
    }
    return array;
}

void DeleteThreeDimensionArray(int*** array, const int depth, const int rows) {
    for (int i = 0; i < depth; i++) {
        DeleteTwoDimensionArray(array[i], rows);
    }
    delete [] array;
}

void FillThreeDimensionArrayWithNumbers(int ***array, const int depth, const int rows, const int columns, const int min, const int max) {
    for (int i = 0; i < depth; i++) {
        FillTwoDimensionArrayWithNumbers(array[i], rows, columns, min, max);
    }
}
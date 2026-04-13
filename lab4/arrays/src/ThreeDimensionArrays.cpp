
#include "../include/ThreeDimensionArrays.h"
#include "../include/TwoDimensionArrays.h"

int ***newThreeDimensionArray(int L, int M, int N) {
    auto array = new int**[L];
    for (int i = 0; i < L; i++) {
        array[i] = newTwoDimensionArray(M, N);
    }
    return array;
}

void deleteThreeDimensionArray(int*** array, int L, int M) {
    for (int i = 0; i < L; i++) {
        deleteTwoDimensionArray(array[i], M);
    }
    delete [] array;
}

void fillThreeDimensionArrayWithNumbers(int ***array, int L, int M, int N, int min, int max) {
    for (int i = 0; i < L; i++) {
        fillTwoDimensionArrayWithNumbers(array[i], M, N, min, max);
    }
}
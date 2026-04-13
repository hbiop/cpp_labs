#pragma once

int ***newThreeDimensionArray(int L, int M, int N);
void deleteThreeDimensionArray(int*** array, int L, int M);
void fillThreeDimensionArrayWithNumbers(int*** array, int L,int M, int N, int min = 0, int max = 100);
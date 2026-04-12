#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

void task1();
void task2();
void task3();
void task4();
void task5();

int *newOneDimensionArray(int N);
void fillOneDimensionArrayWithNumbers(int* array, int N, int min = 0, int max = 100);

int **newTwoDimensionArray(int M, int N);
void deleteTwoDimensionArray(int** array, int M);
void fillTwoDimensionArrayWithNumbers(int** array, int M, int N, int min = 0, int max = 100);

int ***newThreeDimensionArray(int L, int M, int N);
void deleteThreeDimensionArray(int*** array, int L, int M);
void fillThreeDimensionArrayWithNumbers(int*** array, int L,int M, int N, int min = 0, int max = 100);

int generateRandomNumber(int min, int max);
double generateRandomNumber(double min, double max);

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru");
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    while (true) {
        int N;
        cout << "Выберите задание \n "
                "1.Задание 1 \n "
                "2.Задание 2 \n "
                "3.Задание 3 \n "
                "4.Задание 4 \n "
                "5.Задание 5 \n "
                "0.Выход \n Введите номер:    ";
        cin >> N;
        switch (N) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                task5();
                break;
            case 0:
                return 0;
            default:
                cout << "Введенно не верное число";
                break;
        }
    }
}

//generators
int generateRandomNumber(const int min, const int max) {
    return std::rand() % (max - min + 1) + min;
}

//1d arrays
int *newOneDimensionArray(int N) {
    return new int[N];
}


void fillOneDimensionArrayWithNumbers(int *array, int N, int min, int max) {
    for (int i = 0; i < N; i++) {
        array[i] = generateRandomNumber(min, max);
    }
}

//2d arrays
int **newTwoDimensionArray(int M, int N) {
    auto array = new int*[M];
    for (int i = 0; i < M; i++) {
        array[i] = newOneDimensionArray(N);
    }
    return array;
}

void deleteTwoDimensionArray(int** array, int M) {
    for (int i = 0; i < M; i++) {
        delete [] array[i];
    }
    delete [] array;
}

void fillTwoDimensionArrayWithNumbers(int **array, int M, int N, int min, int max) {
    for (int i = 0; i < M; i++) {
        fillOneDimensionArrayWithNumbers(array[i], N, min, max);
    }
}

//3d arrays
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
        fillTwoDimensionArrayWithNumbers(array[i], M, N);
    }
}

//tasks
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

void task2() {}

void task3() {
    
}

void task4() {
    cout << "Задание 4. Вычислить среднее арифметическое значение элементов "
            "квадратной матрицы, лежащих слева от главной диагонали. ";
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


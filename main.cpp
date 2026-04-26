#include <iostream>
#include <ctime>
#include <windows.h>
#include "lab4/solutions/include/Solutions.h"

using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru");
    std::srand(time(nullptr));
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
                task1WithPointerArithmetic();
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


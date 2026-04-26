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
                TaskOneWithPointerArithmetic();
                break;
            case 2:
                TaskTwo();
                break;
            case 3:
                TaskThree();
                break;
            case 4:
                TaskFour();
                break;
            case 5:
                TaskFive();
                break;
            case 0:
                return 0;
            default:
                cout << "Введенно не верное число";
                break;
        }
    }
}


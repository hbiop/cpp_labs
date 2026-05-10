#include "solutions.h"

#include <cstdio>
#include <cstring>
#include <iostream>

#include "../utils/string_utils/c_string_utils.h"

void lab5::task_one() {
    char* input_string = create_c_string_from_console();

    if (!input_string || strlen(input_string) == 0) {
        delete[] input_string;
        return;
    }

    char* result_string = new char[strlen(input_string) + 1];
    int result_idx = 0;

    const char* delimiters = " ,";
    char* next_ptr = nullptr;
    char* word = strtok_s(input_string, delimiters, &next_ptr);

    while (word != nullptr) {
        bool startsWithA = false;
        if (static_cast<unsigned char>(word[0]) == 0xD0 && word[1] != '\0') {
            if (static_cast<unsigned char>(word[1]) == 0xB0 || static_cast<unsigned char>(word[1]) == 0x90) {
                startsWithA = true;
            }
        }

        if (!startsWithA) {
            for (int i = 0; word[i] != '\0'; i++) {
                result_string[result_idx++] = word[i];
            }
            result_string[result_idx++] = ' ';
        }
        word = strtok_s(nullptr, delimiters, &next_ptr);
    }

    if (result_idx > 0) {
        result_string[result_idx - 1] = '\0';
    }
    else {
        result_string[0] = '\0';
    }

    std::cout << result_string << std::endl;

    delete[] input_string;
    delete[] result_string;
}


void lab5::task_two() {

}

void lab5::task_three() {

}

void lab5::task_four() {

}

void lab5::task_five() {

}

void lab5::task_six() {

}
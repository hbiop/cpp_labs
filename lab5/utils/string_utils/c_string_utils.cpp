
#include "c_string_utils.h"

#include <iostream>

char* create_c_string() {
    return new char[100];
}

char* create_c_string_from_console() {
    int capacity = 10;
    int length = 0;
    char* buffer = new char[capacity];
    int ch;

    while ((ch = std::getchar()) != '.' && ch != EOF && ch != '\n') {
        if (length + 1 >= capacity) {
            capacity *= 2;
            char* new_buffer = new char[capacity];
            for (int i = 0; i < length; i++) {
                new_buffer[i] = buffer[i];
            }
            delete[] buffer;
            buffer = new_buffer;
        }
        buffer[length++] = static_cast<char>(ch);
    }
    buffer[length] = '\0';
    return buffer;
}
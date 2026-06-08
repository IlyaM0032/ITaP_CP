// utils.cpp
// Общий файл контрольных работ
// Студент группы 4503, Илья М, 2026

#include "utils.h"

#ifdef _WIN32
#define timegm _mkgmtime
#endif

#define RAND_MIN_ (-1000)
#define RAND_MAX_ 1000
#define MATRIX_COLUMN_WITH 6


#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>


int read_int() {
    std::string input;
    bool success = false;
    int result = 0;

    do {
        try {
            std::getline(std::cin, input);
            result = std::stoi(input);
            success = true;
        } catch (std::invalid_argument &) {
            std::cout << "Некорректный ввод. Попробуйте ещё раз: ";
        }
    } while (!success);

    return result;
}



int read_natural() {
    int result = 0;
    bool valid = false;
    do {
        result = read_int();
        valid = (result > 0);
        if (!valid) std::cout << "Полученное число не натуральное. Попробуйте ещё раз: ";
    } while (!valid);
    return result;
}

bool read_decision(bool default_decision) {
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) {
        return default_decision;
    }
    switch (input[0]) {
    case 'Y':
    case 'y':
        return true;
    case 'N':
    case 'n':
    default:
        return false;

    }
}

int random_int() {
    return RAND_MIN_ + rand() % (RAND_MAX_ - RAND_MIN_);
}




void print_matrix(const std::vector<std::vector<int>>& matrix, std::ostream& out) {
    for (auto& line : matrix) {
        for (auto& element: line) {
            out << std::setw(MATRIX_COLUMN_WITH) << element;
        }
        out << std::endl;
    }
}
// console_interface.h
// Консольный интерфейс программы
// Студент группы 4503, Илья М, 2026

#ifndef ITAP_TESTS_MAIN_MENU_H
#define ITAP_TESTS_MAIN_MENU_H
#include <vector>

enum main_menu_options {
    OPTION_EXIT = 0,
    OPTION_ENTER_MATRIX = 1,
    OPTION_SAVE_ENTER_MATRIX = 2,
    OPTION_ENTER_MATRIX_FROM_FILE = 3,
    OPTION_MAKE_ANALYSE = 4,
    OPTION_PRINT_SORTED_MATRIX = 5,
    OPTION_SAVE_SORTED_MATRIX_TO_FILE = 6,
    OPTION_START_UNIT_TESTS = 7,
};

void main_menu();

void enter_matrix(std::vector<std::vector<int>>& matrix);
void enter_matrix_from_file(std::vector<std::vector<int>>& matrix);
void make_analyse_on_matrix(const std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& result_matrix);
void save_matrix_to_file(const std::vector<std::vector<int>>& sorted_matrix);
#endif // ITAP_TESTS_MAIN_MENU_H

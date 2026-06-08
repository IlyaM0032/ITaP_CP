// main.cpp
// Точка входа
// Студент группы 4503, Илья М, 2026

#include "unit_tests.h"
#include "console_interface.h"

#include <ctime>
#include <iostream>
#include <ostream>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#endif


int main() {
#ifdef _WIN32
    system("chcp 65001");
    system("cls");
#endif
    std::srand(std::time(nullptr));
    if (make_tests()) {
        std::cout << "Тестирование пройдено успешно" << std::endl;
        main_menu();
        return EXIT_SUCCESS;
    }

    return EXIT_SUCCESS;



}
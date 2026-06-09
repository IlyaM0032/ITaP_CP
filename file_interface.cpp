// file_interface.cpp
// Файловый интерфейс программы
// Студент группы 4503, Илья М, 2026

#include "file_interface.h"

#include "utils.h"

#include <filesystem>
#include <fstream>
#include <iosfwd>
#include <iostream>

std::ofstream open_output_file() {
    while (true) {
        std::string path;
        std::cout << "Введите путь к файлу для записи: " << std::endl;
        std::getline(std::cin, path);

        if (std::filesystem::exists(path)) {
            std::cout << "Файл уже существует — перезаписать? [y/N]: ";
            if (read_decision(false) == false) continue;
        }

        std::ofstream output_file(path, std::ios::out);
        if (output_file.is_open()) {
            return output_file;
        }
        std::cout << "Не удалось открыть файл, попробуйте ещё раз" << std::endl;
    }
}

std::ifstream open_input_file() {
    while (true) {
        std::string path;
        std::cout << "Введите путь к файлу для чтения: " << std::endl;
        std::getline(std::cin, path);

        std::ifstream input_file(path, std::ios::in);
        if (input_file.is_open()) {
            return input_file;
        }
        std::cout << "Не удалось открыть файл, попробуйте ещё раз" << std::endl;
    }
}
//
// Created by ilyam0032 on 04.06.2026.
//

#include "file_interface.h"

#include "utils.h"

#include <filesystem>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <memory>

std::ofstream open_output_file() {
    // bool success = false;
    while (true) {
        std::string path;
        std::cout << "Введите путь к файлу для записи: " << std::endl;
        std::getline(std::cin, path);

        if (std::filesystem::exists(path)) {
            std::cout << "Файл уже существует — перезаписать? [y/N]: ";

            if (read_decision(false) == false) continue;
        }

        // std::ofstream output_file(path, std::ios::out);
        std::ofstream output_file(path, std::ios::out);
        if (output_file.is_open()) {
            // success = true;
            return output_file;
        }
        std::cout << "Не удалось открыть файл, попробуйте ещё раз" << std::endl;
    }
}

std::ifstream open_input_file() {
    // bool success = false;
    while (true) {
        std::string path;
        std::cout << "Введите путь к файлу для чтения: " << std::endl;
        std::getline(std::cin, path);

        std::ifstream input_file(path, std::ios::in);
        // auto input_file = std::make_unique<std::ifstream>(path, std::ios::in);
        if (input_file.is_open()) {
            // success = true;
            return input_file;
        }
        std::cout << "Не удалось открыть файл, попробуйте ещё раз" << std::endl;
    }
}
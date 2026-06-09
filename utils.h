// utils.h
// Вспомогательный функции
// Студент группы 4503, Илья М, 2026

#ifndef UTILS_H
#define UTILS_H
#include <memory>
#include <vector>


int read_int();

int read_natural();
bool read_decision();

int random_int();

void print_matrix(const std::vector<std::vector<int>>& matrix, std::ostream& out);

#endif //UTILS_H

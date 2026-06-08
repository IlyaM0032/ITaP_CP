// utils.h
// Общий файл контрольных работ
// Студент группы 4503, Илья М, 2026

#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>


int read_int();

int read_natural();
bool read_decision(bool);

int random_int();

void print_matrix(const std::vector<std::vector<int>>& matrix, std::ostream& out);

#endif //UTILS_H

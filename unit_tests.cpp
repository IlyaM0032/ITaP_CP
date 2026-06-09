// unit_tests.cpp
// Файл модульного тестирования
// Студент группы 4503, Илья М, 2026

#include <limits.h>
#include <vector>
#include <iostream>

#include "sorting_algorithms.h"

bool sorted(const std::vector<int>& v) {
    int least = -INT_MAX;
    for (auto& i : v) {
        if (least > i) {
            return false;
        }
        least = i;
    }
    return true;
}
bool make_tests() {
    bool success = true;

    std::cout << "Выполняется тестирование..." << std::endl;
    if (not sorted({1,2,3})) {
        std::cout << "Тест 1 не пройден." << std::endl;
        success = false;
    }

    if (sorted({3,2,1})) {
        std::cout << "Тест 2 не пройден." << std::endl;
        success = false;
    }

    if (not sorted({1,2,2,3})) {
        std::cout << "Тест 3 не пройден." << std::endl;
        success = false;
    }
    std::vector<int> unsorted_vector = {2, 5, 10, -1, 4, 4};

    BubbleSort bubble_sort;
    auto bubble_sorted_vector = unsorted_vector;
    bubble_sort.Sort(bubble_sorted_vector);
    if (not sorted(bubble_sorted_vector)) {
        std::cout << "Тест 4 не пройден." << std::endl;
        success = false;
    }

    SelectionSort selection_sort;
    auto selection_sorted_vector = unsorted_vector;
    selection_sort.Sort(selection_sorted_vector);
    if (not sorted(selection_sorted_vector)) {
        std::cout << "Тест 5 не пройден." << std::endl;
        success = false;
    }

    InsertionSort insertion_sort;
    auto insertion_sorted_vector = unsorted_vector;
    insertion_sort.Sort(insertion_sorted_vector);
    if (not sorted(insertion_sorted_vector)) {
        std::cout << "Тест 6 не пройден." << std::endl;
        success = false;
    }

    ShallSort shall_sort;
    auto shall_sorted_vector = unsorted_vector;
    shall_sort.Sort(shall_sorted_vector);
    if (not sorted(shall_sorted_vector)) {
        std::cout << "Тест 7 не пройден." << std::endl;
        success = false;
    }

    QuickSort quick_sort;
    auto quick_sorted_vector = unsorted_vector;
    quick_sort.Sort(quick_sorted_vector);
    if (not sorted(quick_sorted_vector)) {
        std::cout << "Тест 8 не пройден." << std::endl;
        success = false;
    }


    return success;
}


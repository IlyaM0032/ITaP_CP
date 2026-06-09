// sorting_algorithms.cpp
// Алгоритмы сортировок
// Студент группы 4503, Илья М, 2026

#include "sorting_algorithms.h"



void BubbleSort::Sort(std::vector<int>& array) {
    if (array.size() < 2) {
        return;
    }
    int previous_permutations;

    do {
        previous_permutations = permutations;
        for (int i = 0; i < array.size() - 1; i++) {
            ++comparison;
            if (array[i] > array[i + 1]) {
                ++permutations;
                std::swap(array[i], array[i + 1]);
            }
        }
    } while (permutations > previous_permutations);
}

void SelectionSort::Sort(std::vector<int>& array) {
    if (array.size() < 2) {
        return;
    }

    for (int i = 0; i < array.size() - 1; i++) {
        int selected_element = i;
        for (int j = i + 1; j < array.size() ; j++) {
            ++comparison;
            if (array[j] < array[selected_element]) {
                selected_element = j;
            }
        }
        ++comparison;
        if (selected_element != i) {
            ++permutations;
            std::swap(array[i], array[selected_element]);
        }
    }
}

void InsertionSort::Sort(std::vector<int>& array) {
    if (array.size() < 2) {
        return;
    }
    for (int i = 1; i < array.size(); i++) {
        for (int j = i; j > 0; j--) {
            ++comparison;
            if (array[j-1] >= array[j]) {
                ++permutations;
                std::swap(array[j], array[j-1]);
            } else {
                break;
            }
        }
    }
}

void ShallSort::Sort(std::vector<int> &array) {
    if (array.size() < 2) {
        return;
    }
    for (int h = array.size()/2; h > 0; h/=2) {
        for (int i = h; i < array.size(); i++) {
            // int temp = array[i];
            for (int j = i; j >= h; j -= h) {
                ++comparison;
                if (array[j-h] > array[j]) {
                    ++permutations;
                    std::swap(array[j], array[j-h]);
                } else {
                    break;
                }
            }
        }
    }
}

void QuickSort::Sort(std::vector<int>& array) {
    if (array.size() < 2) {
        return;
    }
    Sort(array, 0, array.size() - 1);
}

void QuickSort::Sort(std::vector<int>& array, const int begin, const int end) {
    if (begin < end) {
        int pivot = array[end];

        int last_smaller_than_pivot = begin - 1;
        for (int j = begin; j < end; j++) {
            ++comparison;
            if (array[j] <= pivot) {
                ++last_smaller_than_pivot;
                ++permutations;
                std::swap(array[last_smaller_than_pivot], array[j]);
            }
        }

        ++permutations;

        std::swap(array[last_smaller_than_pivot + 1], array[end]);

        int pivot_index = last_smaller_than_pivot + 1;

        Sort(array, begin, pivot_index - 1);
        Sort(array, pivot_index + 1, end);
    }
}

void sort_matrix(std::vector<std::vector<int>>& matrix, ISort& sorting_class) {
    std::vector<int> even_elements;
    for (auto& row : matrix) {
        for (auto& element : row) {
            if (element % 2 == 0) {even_elements.push_back(element);}
        }
    } // собрать все четные
    sorting_class.Sort(even_elements);
    auto even_elements_iterator = even_elements.begin();

    for (auto& row : matrix) {
        for (auto& element : row) {
            if (element % 2 == 0) {element = *even_elements_iterator++;}
        }
    } // вернуть на место

    std::vector<int> odd_elements;
    for (int column = 0; column < matrix[0].size(); column++) {
        for (int row = 0; row < matrix.size(); row++) {
            if (matrix[row][column] % 2 != 0) {
                odd_elements.push_back(matrix[row][column]);
            }
        }
    } // собрать все нечетные

    sorting_class.Sort(odd_elements);
    auto odd_elements_iterator = odd_elements.begin();

    for (int column = 0; column < matrix[0].size(); column++) {
        for (int row = 0; row < matrix.size(); row++) {
            if (matrix[row][column] % 2 != 0) {
                matrix[row][column] = *odd_elements_iterator++;
            }
        }
    } // вернуть на место
}
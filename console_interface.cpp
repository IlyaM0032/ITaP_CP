// console_interface.cpp
// Консольный интерфейс программы
// Студент группы 4503, Илья М, 2026

#include "console_interface.h"


#include "utils.h"
#include "sorting_algorithms.h"
#include "file_interface.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <optional>

#define PERM_COLUMN_WITH 23
#define COMP_COLUMN_WITH 20
#define SUMM_COLUMN_WITH 29


void main_menu() {
    std::optional<std::vector<std::vector<int>>> entered_matrix;
    std::optional<std::vector<std::vector<int>>> sorted_matrix;


    bool continue_cycle = true;
    do {
        std::cout << std::endl;
        std::cout << "1) Ввести матрицу" << std::endl;
        std::cout << "2) Сохранить введенную матрицу в файл" << std::endl;
        std::cout << "3) Ввести матрицу из файла" << std::endl;
        std::cout << "4) Отсортировать матрицу и провести анализ" << std::endl;
        std::cout << "5) Вывести отсортированную матрицу в консоль" << std::endl;
        std::cout << "6) Сохранить отсортированную матрицу в файл" << std::endl;
        // std::cout << "7) Провести тестирование программы" << std::endl;
        std::cout << "0) Выход" << std::endl;
        std::cout << std::endl;
        std::cout << "Выберите соответствующий пункт меню: ";

        bool input_again = false;
        do {
            input_again = false;
            switch (read_int()) {
            case OPTION_ENTER_MATRIX:
                if (!entered_matrix) {
                    entered_matrix.emplace();
                }
                enter_matrix(entered_matrix.value());
                break;

            case OPTION_SAVE_ENTER_MATRIX:
                if (!entered_matrix) {
                    std::cout << "Исходная матрица пуста." << std::endl;
                    break;
                }
                save_matrix_to_file(entered_matrix.value());
                break;

            case OPTION_ENTER_MATRIX_FROM_FILE:
                if (!entered_matrix) {
                    entered_matrix.emplace();
                }
                enter_matrix_from_file(entered_matrix.value());
                break;

            case OPTION_MAKE_ANALYSE:
                if (!entered_matrix) {
                    std::cout << "Исходная матрица пуста." << std::endl;
                    break;
                }
                if (!sorted_matrix) {
                    sorted_matrix.emplace();
                }
                make_analyse_on_matrix(entered_matrix.value(), sorted_matrix.value());
                break;

            case OPTION_PRINT_SORTED_MATRIX:
                if (!sorted_matrix) {
                    std::cout << "Сортировка матрицы ещё не была произведена";
                    break;
                }
                print_matrix(sorted_matrix.value(), std::cout);
                // print_sorted_matrix(sorted_matrix);
                break;

            case OPTION_SAVE_SORTED_MATRIX_TO_FILE:
                if (!sorted_matrix) {
                    std::cout << "Сортировка матрицы ещё не была произведена";
                    break;
                }
                save_matrix_to_file(sorted_matrix.value());
                break;

            case OPTION_EXIT:
                continue_cycle = false;
                break;

            default:
                std::cout << "Нет такого пункта меню. Попробуйте ещё раз: ";
                input_again = true;
            }
        } while (input_again);
    } while (continue_cycle);
}


void enter_matrix(std::vector<std::vector<int>>& matrix) {
    // 1) Получить поличество столюцов
    // 2) получить количество строк
    // 3) заполнить случайными значениями?
    // 4) нет - заполнить вручную
    std::cout << "Введите количество строк N" << std::endl;
    int rows = read_natural();
    std::cout << "Введите количество строк M" << std::endl;
    int columns = read_natural();

    matrix.assign(rows, std::vector<int>(columns, 0));
    std::cout << "Ввести " << rows*columns<< " значений вручную? [y/N]" << std::endl;
    bool decision = read_decision(false);


    for (size_t row = 0; row < rows; row++) {
        for (size_t column = 0; column < columns; column++) {
            if (decision) {
                std::cout << "Введите значение [" << row+1 << "][" << column+1 << "] : " << std::endl;
                matrix[row][column] = read_int();
            } else {
                matrix[row][column] = random_int();
            }

        }
    }
    std::cout << "Ввод успешно завершен!" << std::endl;
}
void enter_matrix_from_file(std::vector<std::vector<int>>& matrix) {
    std::cout << "Перед получением матрицы из файла укажите её размерность" << std::endl;
    std::cout << "Введите количество строк N" << std::endl;
    int rows = read_natural();
    std::cout << "Введите количество строк M" << std::endl;
    int columns = read_natural();

    matrix.assign(rows, std::vector<int>(columns, 0));

    std::ifstream file = open_input_file();
    bool insufficient_values = false;
    for (size_t row = 0; row < rows; row++) {
        for (size_t column = 0; column < columns; column++) {
            int value = 0;
            if (insufficient_values) {
                matrix[row][column] = 0;
                continue;
            }
            if (!(file >> value)) {
                if (file.eof()) {
                    std::cout << "Значений в файле меньше чем требуется для заполнения матрицы. Недостающие элементы были заполнены нулями." << std::endl;
                    insufficient_values = true;
                }
                else {
                    std::cout << "Ошибка чтения в позиции " << row * columns + column << ". Матрица была заполнена частично" << std::endl;
                    return;
                }
            }
            matrix[row][column] = value;
        }
    }
    std::cout << "Ввод успешно завершен!" << std::endl;
    file.close();
}

void make_analyse_on_matrix(const std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& result_matrix) {
    // вывести исходную матрицу
    std::cout << "Исходная матрица: " << std::endl;
    print_matrix(matrix, std::cout);
    std::cout << std::endl;

    // 1) скопировать, отсортировать пузырьковой сортировкой
    // вывести отсортированную, вывести статистику по методу

    auto bubble_sorted_matrix = matrix;
    BubbleSort bubble_sort;
    sort_matrix(bubble_sorted_matrix, bubble_sort);
    std::cout << "Матрица, отсортированная пузырьковой сортировкой: " << std::endl;
    print_matrix(bubble_sorted_matrix, std::cout);
    std::cout << std::endl;
    std::cout << "Количество сравнений элементов: " << bubble_sort.get_comparisons() << std::endl;
    std::cout << "Количество перестановок элементов: " << bubble_sort.get_permutations() << std::endl;



    // 2) скопировать, отсортировать сортировкой отбором
    // вывести отсортированную, вывести статистику по методу

    auto selection_sorted_matrix = matrix;
    SelectionSort selection_sort;
    sort_matrix(selection_sorted_matrix, selection_sort);
    std::cout << "Матрица, отсортированная сортировкой выбором: " << std::endl;
    print_matrix(selection_sorted_matrix, std::cout);
    std::cout << std::endl;
    std::cout << "Количество сравнений элементов: " << selection_sort.get_comparisons() << std::endl;
    std::cout << "Количество перестановок элементов: " << selection_sort.get_permutations() << std::endl;

    if (bubble_sorted_matrix!= selection_sorted_matrix) {
        std::cout << "Ошибка, матрицы отсортированные пузырьком и выбором не совпадают!" << std::endl;
        return;
    }

    // 3) скопировать, отсортировать сортировкой вставкой
    // вывести отсортированную, вывести статистику по методу

    auto insertion_sorted_matrix = matrix;
    InsertionSort insertion_sort;
    sort_matrix(insertion_sorted_matrix, insertion_sort);
    std::cout << "Матрица, отсортированная сортировкой вставкой: " << std::endl;
    print_matrix(insertion_sorted_matrix, std::cout);
    std::cout << std::endl;
    std::cout << "Количество сравнений элементов: " << insertion_sort.get_comparisons() << std::endl;
    std::cout << "Количество перестановок элементов: " << insertion_sort.get_permutations() << std::endl;

    if (selection_sorted_matrix!= insertion_sorted_matrix) {
        std::cout << "Ошибка, матрицы отсортированные выбором и вставкой не совпадают!" << std::endl;
        return;
    }

    // 4) скопировать, отсортировать сортировкой Шелла
    // вывести отсортированную, вывести статистику по методу

    auto shall_sorted_matrix = matrix;
    ShallSort shall_sort;
    sort_matrix(shall_sorted_matrix, shall_sort);
    std::cout << "Матрица, отсортированная сортировкой Шелла: " << std::endl;
    print_matrix(shall_sorted_matrix, std::cout);
    std::cout << std::endl;
    std::cout << "Количество сравнений элементов: " << shall_sort.get_comparisons() << std::endl;
    std::cout << "Количество перестановок элементов: " << shall_sort.get_permutations() << std::endl;

    if (insertion_sorted_matrix!= shall_sorted_matrix) {
        std::cout << "Ошибка, матрицы отсортированные вставкой и Шеллом не совпадают!" << std::endl;
        return;
    }

    // 5) скопировать, отсортировать быстрой сортировкой
    // вывести отсортированную, вывести статистику по методу

    auto quick_sorted_matrix = matrix;
    QuickSort quick_sort;
    sort_matrix(quick_sorted_matrix, quick_sort);
    std::cout << "Матрица, отсортированная быстрой сортировкой: " << std::endl;
    print_matrix(quick_sorted_matrix, std::cout);
    std::cout << std::endl;
    std::cout << "Количество сравнений элементов: " << quick_sort.get_comparisons() << std::endl;
    std::cout << "Количество перестановок элементов: " << quick_sort.get_permutations() << std::endl;
    std::cout << std::endl;

    if (shall_sorted_matrix!= quick_sorted_matrix) {
        std::cout << "Ошибка, матрицы отсортированные Шеллом и быстрой не совпадают!" << std::endl;
        return;
    }

    std::cout << "Сравнение методов сортировки: " << std::endl;
    std::cout << "┌────────────────────────┬──────────────────────┬─────────────────────────┬───────────────────────────────┐" << std::endl;
    std::cout << "│ Алгоритм сортировки    │ Количество сравнений │ Количество перестановок │ Суммарное количество операций │" << std::endl;
    std::cout << "├────────────────────────┼──────────────────────┼─────────────────────────┼───────────────────────────────┤" << std::endl;
    std::cout << "│ Пузырьковая сортировка │ "
    << std::setw(COMP_COLUMN_WITH) << bubble_sort.get_comparisons() << " │ "
    << std::setw(PERM_COLUMN_WITH) << bubble_sort.get_permutations() << " │ "
    << std::setw(SUMM_COLUMN_WITH) << bubble_sort.get_permutations() + bubble_sort.get_comparisons() << " │" << std::endl;
    std::cout << "├────────────────────────┼──────────────────────┼─────────────────────────┼───────────────────────────────┤" << std::endl;
    std::cout << "│ Сортировка выбором     │ "
    << std::setw(COMP_COLUMN_WITH) << selection_sort.get_comparisons() << " │ "
    << std::setw(PERM_COLUMN_WITH) << selection_sort.get_permutations() << " │ "
    << std::setw(SUMM_COLUMN_WITH) << selection_sort.get_permutations() + selection_sort.get_comparisons() << " │" << std::endl;
    std::cout << "├────────────────────────┼──────────────────────┼─────────────────────────┼───────────────────────────────┤" << std::endl;
    std::cout << "│ Сортировка вставкой    │ "
    << std::setw(COMP_COLUMN_WITH) << insertion_sort.get_comparisons() << " │ "
    << std::setw(PERM_COLUMN_WITH) << insertion_sort.get_permutations() << " │ "
    << std::setw(SUMM_COLUMN_WITH) << insertion_sort.get_permutations() + insertion_sort.get_comparisons() << " │" << std::endl;
    std::cout << "├────────────────────────┼──────────────────────┼─────────────────────────┼───────────────────────────────┤" << std::endl;
    std::cout << "│ Сортировка Шелла       │ "
    << std::setw(COMP_COLUMN_WITH) << shall_sort.get_comparisons() << " │ "
    << std::setw(PERM_COLUMN_WITH) << shall_sort.get_permutations() << " │ "
    << std::setw(SUMM_COLUMN_WITH) << shall_sort.get_permutations() + shall_sort.get_comparisons() << " │" << std::endl;
    std::cout << "├────────────────────────┼──────────────────────┼─────────────────────────┼───────────────────────────────┤" << std::endl;
    std::cout << "│ Быстрая сортировка     │ "
    << std::setw(COMP_COLUMN_WITH) << quick_sort.get_comparisons() << " │ "
    << std::setw(PERM_COLUMN_WITH) << quick_sort.get_permutations() << " │ "
    << std::setw(SUMM_COLUMN_WITH) << quick_sort.get_permutations() + quick_sort.get_comparisons() << " │" << std::endl;
    std::cout << "└────────────────────────┴──────────────────────┴─────────────────────────┴───────────────────────────────┘" << std::endl;

    result_matrix = std::move(quick_sorted_matrix);
}

// void print_sorted_matrix(std::vector<std::vector<int>>& sorted_matrix) {
//     if (!sorted_matrix) {
//         std::cout << "Сортировка матрицы ещё не была произведена." << std::endl;
//         return;
//     }
//     std::cout << "Отсортированная матрица:" << std::endl;
//     print_matrix(sorted_matrix.value(), std::cout);
// }

void save_matrix_to_file(const std::vector<std::vector<int>>& sorted_matrix) {
    if (sorted_matrix.empty()) {
        std::cout << "Матрица пуста" << std::endl;
        return;
    }
    auto output_file = open_output_file();
    print_matrix(sorted_matrix, output_file);
    std::cout << "Успешно!" << std::endl;
    output_file.close();
}




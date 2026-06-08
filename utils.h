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

#define DATE_FORMAT "%d.%m.%Y %H:%M"
#define DATE_EXAMPLE "31.12.1999 23:59"

class IShowable {
    public:
    virtual ~IShowable() = default;
    virtual std::string show() const = 0;
};

template <typename T> void print_showables_list(const std::list<std::shared_ptr<T>>& list) {
    if (list.empty()) {
        std::cout << "Список пуст" << std::endl;
    } else {
        for (const std::shared_ptr<T>& item : list) {
            std::cout << item->show() << std::endl;
        }
    }
}


int read_int();
double read_double();
int read_natural();
char read_char();
bool read_decision(bool);

int random_int();

time_t read_time();
std::string time_t_to_string(time_t t);

void print_matrix(const std::vector<std::vector<int>>& matrix, std::ostream& out);

#endif //UTILS_H

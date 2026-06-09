// sorting_algorithms.h
// Алгоритмы сортировок
// Студент группы 4503, Илья М, 2026


#ifndef ITAP_CP_SORTING_ALGORITHMS_H
#define ITAP_CP_SORTING_ALGORITHMS_H
#include <vector>



class ISort {
protected:
    unsigned long long comparison = 0;
    unsigned long long permutations = 0;

public:
    virtual ~ISort() = default;
    virtual void Sort(std::vector<int>& array) = 0;

    unsigned long long get_comparisons() const { return comparison; }
    unsigned long long get_permutations() const { return permutations; }
};

class BubbleSort : public ISort {
    public:
    void Sort(std::vector<int>& array) override;
};
class SelectionSort : public ISort {
    public:
    void Sort(std::vector<int>& array) override;
};
class InsertionSort : public ISort {
    public:
    void Sort(std::vector<int>& array) override;
};
class ShallSort : public ISort {
    public:
    void Sort(std::vector<int>& array) override;
};
class QuickSort : public ISort {
    void Sort(std::vector<int>& array, int begin, int end);
    public:
    void Sort(std::vector<int>& array) override;
};

void sort_matrix(std::vector<std::vector<int>>& matrix, ISort& sorting_class);

#endif // ITAP_CP_SORTING_ALGORITHMS_H

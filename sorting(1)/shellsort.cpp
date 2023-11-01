// TODO: Write your code here

#ifndef SORTING_H
#define SORTING_H

#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
class Sorting {
private:
    static void printArray(T* start, T* end)
    {
        int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";
        cout << endl;
    }

public:
    // TODO: Write your code here
    static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total);
    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases);
};
#endif /* SORTING_H */


template <class T>
static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) {
    // TODO
    T* first = start + segment_idx;
    T* current = first + cur_segment_total;
    while(current < end) {
        auto tmp = current;
        T key = *current;
        while(tmp != first && key < *(tmp - cur_segment_total)) {
            *tmp = *(tmp - cur_segment_total);
            tmp = tmp - cur_segment_total;
        }
        *tmp = key;
        current += cur_segment_total;
    }
}

template <class T>
static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
    // TODO
    // Note: You must print out the array after sorting segments to check whether your algorithm is true.
    while(--num_phases >= 0) {
        for(int i = 0; i < num_segment_list[num_phases]; i++)
            sortSegment(start, end, i, num_segment_list[num_phases]);
        cout << num_segment_list[num_phases] << " segments:";
        for(auto tmp = start; tmp != end; tmp++) cout << ' ' << *tmp;
        cout << endl;
    }
}
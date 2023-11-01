// implement static method selectionSort in class Sorting to sort an array in ascending order.  After each selection, we will print out a list to check (using printArray). 


#include <iostream>
using namespace std;

template <class T>
class Sorting
{
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void selectionSort(T *start, T *end);
};

template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    T* head = start;
    int n = end - start;
    while(head != end-1) {
        T* minNode = head;
        T* tmp = head;
        while(tmp != end-1) {
            tmp++;
            if(*tmp < *minNode) minNode = tmp;
        }
        T data = *minNode;
        *minNode = *head;
        *head = data;
        printArray(start, end);
        n--;
        head++;
    }
    
}
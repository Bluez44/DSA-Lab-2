// Implement all methods in class Stack with template type T. The description of each method is written as comment in frame code.


#ifndef STACK_H
#define STACK_H
// #include "DLinkedList.h"
template<class T>
class Stack {
protected:
    DLinkedList<T> list;
public:
    Stack() {}
    void push(T item) ;
    T pop() ;
    T top() ;
    bool empty() ;
    int size() ;
    void clear() ;
};

#endif


// You can use all methods in class DLinkedList without implementing them again. The description of class DLinkedList is written as comment in frame code.

template <class T>
class DLinkedList 
{
public:
    class Node;     //forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList() ;
    ~DLinkedList();
    void add(const T& e);
    void add(int index, const T& e);
    T removeAt(int index);
    bool removeItem(const T& removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T& e);
    int indexOf(const T& item);
    bool contains(const T& item);
};
template<class T>
void Stack<T>::push(T item) {
    // TODO: Push new element into the top of the stack
    list.add(item);
}
template<class T>
T Stack<T>::pop() {
    // TODO: Remove an element on top of the stack
    return list.removeAt(list.size()-1);
}
template<class T>
T Stack<T>::top() {
    // TODO: Get value of the element on top of the stack
    return list.get(list.size()-1);
}

template<class T>
bool Stack<T>::empty() {
    // TODO: Determine if the stack is empty
    return list.empty();
}

template<class T>
int Stack<T>::size() {
    // TODO: Get the size of the stack
    return list.size();
}

template<class T>
void Stack<T>::clear() {
    // TODO: Clear all elements of the stack
    list.clear();
}
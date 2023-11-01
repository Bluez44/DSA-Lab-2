// Implement all methods in class Queue with template type T. The description of each method is written as comment in frame code.


#ifndef QUEUE_H
#define QUEUE_H
// #include "DLinkedList.h"
template<class T>
class Queue {
protected:
    DLinkedList<T> list;
public:
    Queue() {}
    void push(T item) ;
    T pop() ;
    T top() ;
    bool empty() ;
    int size() ;
    void clear() ;
};

#endif /* QUEUE_H */


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
void Queue<T>::push(T item) {
    // TODO: Push new element into the end of the queue
    list.add(item);
}
template<class T>
T Queue<T>::pop() {
    // TODO: Remove an element in the head of the queue
    return list.removeAt(0);
        
}
template<class T>
T Queue<T>::top() {
    // TODO: Get value of the element in the head of the queue
    return list.get(0);
        
}
template<class T>
bool Queue<T>::empty() {
    // TODO: Determine if the queue is empty
    return list.empty();
        
}
template<class T>
int Queue<T>::size() {
    // TODO: Get the size of the queue
     return list.size();   
}
template<class T>
void Queue<T>::clear() {
    // TODO: Clear all elements of the queue
    list.clear();
    
}
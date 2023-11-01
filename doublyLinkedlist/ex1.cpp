// Implement methods add, size in template class DLinkedList (which implements List ADT) representing the doubly linked list with type T with the initialized frame. The description of each method is given in the code.

#include<bits/stdc++.h>
using namespace std;

template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList();
    ~DLinkedList();
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };

};

template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* newnode = new Node(e);
    if(count == 0) {
        head = tail = newnode;
    }
    else {
        tail->next = newnode;
        newnode->previous = tail;
        tail = tail->next;
    }
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    if(index < 0) return;
    if(index >= count) return add(e);
    Node* tmp = head;
    Node* newnode = new Node(e);
    if(index == 0) {
        head->previous = newnode;
        newnode->next = head;
        head = head->previous;
        count++; return;
    }
    for(int i = 0; i < index; i++) {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    newnode->previous = tmp;
    tmp->next->previous = newnode;
    tmp->next = newnode;
    count++;
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}

int main() {
    DLinkedList<int> list;
    int size = 10;
    for(int idx=0; idx < size; idx++){
        list.add(0, idx);
    }
    // cout << list.toString();
    return 0;
}
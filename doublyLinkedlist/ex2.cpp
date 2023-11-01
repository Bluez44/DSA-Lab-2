// Implement methods get, set, empty, indexOf, contains in template class DLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.
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
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item);
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


template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if(index < 0 || index > count) return -1;
    if(index == 0) return head->data;
    if(index == count) return tail->data;
    Node* tmp = head;
    for(int i = 0; i < index; i++) {
        tmp = tmp->next;
    }
    return tmp->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if(index < 0 || index > count) return;
    if(index == 0) head->data = e;
    if(index == count) tail->data = e;
    Node* tmp = head;
    for(int i = 0; i < index; i++) tmp = tmp->next;
    tmp->data = e;
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return (count == 0);
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node* tmp = head;
    for(int i = 0; i < count; i++) {
        if(tmp->data == item) return i;
        tmp = tmp->next;
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    Node* tmp = head;
    for(int i = 0; i  < count; i ++) {
        if(tmp->data == item) return true;
        tmp = tmp->next;
    }
    return false;
}
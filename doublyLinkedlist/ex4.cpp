// Implement methods removeAt, removeItem, clear in template class SLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.
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
    T       removeAt(int index);
    bool    removeItem(const T &item);
    void    clear();
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
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    T result;

    if(index < 0 || index > count || count == 0) throw out_of_range("");

    else if(count == 1){
        result = head->data;
        delete head;
        head =tail = nullptr;
    }

    else if(index == 0){

        result = head->data;
        Node* tmp = head;
        head = head->next;

        delete tmp;
    }
    else{

        index --;
        Node* tmp = head;

        while(index){
            tmp = tmp->next;
            index --;
        }
        if(tmp->next->next){
            Node* d = tmp->next;
            tmp->next = tmp->next->next;
            result = d->data;
            delete d;
        }
        else{

            tail = tmp;
            Node* d = tmp->next;
            tmp->next = nullptr;
            result = d->data;
            delete d;
        }
    }
    count --;
    return result;
    
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    int index = indexOf(item);
    if(index == -1 ) return false;
    removeAt(index);
    return true;
}

template<class T>
void DLinkedList<T>::clear(){
    /* Remove all elements in list */
    Node* tmp = head;
    while(tmp){
        tmp = tmp->next;
        delete head;
        head = tmp;
    }
    tail = head = NULL;
    count = 0;
}

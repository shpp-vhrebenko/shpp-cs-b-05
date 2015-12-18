#pragma once
#include <conio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

// Implementation of a simply-connected linear type list(LIFO/FIFO).
template<class T>
class MyList{
    class Node{
    public:
        T value;
        Node *next;
    };
    Node* head, *tail;
    int count;

    void merge(Node *a, Node *b, Node **c);

    void split(Node *src, Node **low, Node **high);

    void mergeSort(Node **head);

public:
    // Constructors ----------------------------------------------------------------------------

    // Default constructor
    MyList();

    // The copy constructor
    MyList(const MyList& sourceList);

    //Destructor--------------------------------------------------------------------------------
    ~MyList();
    //------------------------------------------------------------------------------------------

    // iterator class---------------------------------------------------------------------------
    class iterator{
    private:
        Node * itPtr;
    public:
        iterator(): itPtr(0){}
        iterator(Node * n): itPtr(n){}


        Node * get(int index = 0){
            int i = 0;
            while (i < index && itPtr->next) {
                itPtr = itPtr->next;
                i++;

            }
            return itPtr;
        }



        T & operator*(){
            return itPtr->value;
        }

        T * operator->(){
            return itPtr->value;
        }

        iterator & operator++(){
            itPtr = itPtr->next;
            return *this;
        }

        iterator & operator++(int){
            iterator tmp = *this;
            itPtr = itPtr->next;
            return tmp;
        }

        bool operator==(iterator const & it){
            return itPtr == it.itPtr;
        }

        bool operator!=(iterator const & it){
            return itPtr != it.itPtr;
        }
    };


    class const_iterator{
    private:
        const Node * itPtr;
    public:
        const_iterator()
            : itPtr(0){}
        const_iterator (Node *n)
            : itPtr(n){}


        T operator*(){
            return itPtr->value;
        }

        const_iterator & operator++(){
            itPtr = itPtr->next;
            return *this;
        }

        const_iterator & operator++(int){
            const_iterator tmp = *this;
            itPtr = itPtr->next;
            return tmp;
        }

        bool operator==(const_iterator const & it){
            return itPtr == it.itPtr;
        }

        bool operator!=(const_iterator const & it){
            return itPtr != it.itPtr;
        }
    };

    //Iteration---------------------------------------------------------------------------------

    //Const iterator beginning of the list.
    const_iterator const_begin()const;

    //Const iterator end of the list.
    const_iterator const_end()const;

    //Iterator beginning of the list.
    iterator begin();

    //Iterator end of the list.
    iterator end();

    // Methods ------------------------------------------------------------------------------------

    // Adding an item to the top of the list.
    void add_front(const T& value);

    // Adding an element to the end of the list.
    void add_back(const T& value);

    // Get a pointer to the first element of the list.
    T& front();

    // Display list.
    void show();

    // Removing an item from the beginning of the list.
    void pop_front();

    // Removing an item from the end of the list.
    void pop_back();

    // Insert elements in the middle of the list.
    void insert(int index,const T & value);

    // Removing Elements from the middle of the list.
    void remove(int index);

    // The number of items in the list.
    int size();

    // Is the list is empty.
    bool empty();

    // Clearing the list.
    void clear();

    // Sort the list.
    void sort();

    // Get a reference to a specific item in the list of the index.
    T & get(int index);

    // Setting the value of a list item by index.
    void set(int index, T value);

    // It is equal to the list
    bool isEqual(MyList const & list);

    //Overloaded operators-------------------------------------------------------------------------
    MyList & operator=(MyList const & list);

    bool operator==(MyList & list);

    bool operator!=(MyList & list);

    T & operator[](int i);

};


template<class T>
MyList<T>::MyList(){
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template<class T>
MyList<T>::MyList(const MyList& sourceList): head(nullptr),tail(nullptr),count(0)
{
    Node *tmp = sourceList.head;
    while(tmp != nullptr){

        this->add_back(tmp->value);
        tmp = tmp->next;
    }
}

template<class T>
void MyList<T>::add_front(const T& value){
    Node *tmp = new Node;
    tmp->value = value;
    if(head == nullptr){
        tmp->next = nullptr;
        head = tmp;
        tail = tmp;
    }
    else{
        tmp->next =head;
        head = tmp;
    }

    count++;
}

template<class T>
void MyList<T>::add_back(const T& value){
    Node *tmp = new Node;
    tmp->value = value;
    tmp->next = nullptr;
    if(head==nullptr){
        head = tail =  tmp;
    }
    else{
        tail->next=tmp;
        tail = tmp;
    }
    count++;
}



template<class T>
void MyList<T>::show(){
    if(!empty()){
        Node *temp = head;
        while(temp != nullptr){
            cout<<temp -> value<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    else{
        cout<<"Empty List!!!"<<endl;
    }
}

template<class T>
void MyList<T>::pop_front(){
    if(empty()){
        cerr<<"Error [pop_front].The list is empty.The program will be clossed"<<endl;
        exit(EXIT_FAILURE);
    }
    else{
        Node *temp = head->next;
        if((head != nullptr)&&(temp != nullptr)){
            delete head;
            head = temp;
            count--;
        }
        else if((head != nullptr)&&(temp == nullptr)){
            delete head;
            head = nullptr;
            tail = nullptr;
            count = 0;
        }
    }

}

template<class T>
void MyList<T>::pop_back(){
    if(empty()){
        cerr<<"Error [pop_back].The list is empty.The program will be clossed"<<endl;
        exit(EXIT_FAILURE);
    }
    else{
        if(size()>1){
            Node *temp;
            temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            temp->next = nullptr;
            delete tail;
            tail = temp;
            count--;
        }
        else{
            delete head;
            head = nullptr;
            tail = nullptr;
            count = 0;
        }

    }

}


template<class T>
int MyList<T>::size(){
    return count;
}

template<class T>
bool MyList<T>::empty() {
    return (size() == 0);
}

template<class T>
void MyList<T>::clear() {
    while(!empty())
        pop_back();
}

template<class T>
MyList<T>::~MyList(){
    while(head != nullptr){
        Node *temp = head->next;
        delete head;
        head = temp;
    }

}

template<class T>
void MyList<T>::merge(Node *a, Node *b, Node **c) {
    Node tmp;
    *c = NULL;
    if (a == NULL) {
        *c = b;
        return;
    }
    if (b == NULL) {
        *c = a;
        return;
    }
    if (a->value < b->value) {
        *c = a;
        a = a->next;
    } else {
        *c = b;
        b = b->next;
    }
    tmp.next = *c;
    while (a && b) {
        if (a->value < b->value) {
            (*c)->next = a;
            a = a->next;
        } else {
            (*c)->next = b;
            b = b->next;
        }
        (*c) = (*c)->next;
    }
    if (a) {
        while (a) {
            (*c)->next = a;
            (*c) = (*c)->next;
            a = a->next;
        }
    }
    if (b) {
        while (b) {
            (*c)->next = b;
            (*c) = (*c)->next;
            b = b->next;
        }
    }
    *c = tmp.next;
}

template<class T>
void MyList<T>::split(Node *src, Node **low, Node **high) {
    Node *fast = NULL;
    Node *slow = NULL;

    if (src == NULL || src->next == NULL) {
        (*low) = src;
        (*high) = NULL;
        return;
    }

    slow = src;
    fast = src->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    (*low) = src;
    (*high) = slow->next;
    slow->next = NULL;
}

template<class T>
void MyList<T>::mergeSort(Node **head) {
    Node *low  = NULL;
    Node *high = NULL;
    if ((*head == NULL) || ((*head)->next == NULL)) {
        return;
    }
    split(*head, &low, &high);
    mergeSort(&low);
    mergeSort(&high);
    merge(low, high, head);
}

template<class T>
T& MyList<T>::front(){
    if(head == nullptr){
        return nullptr;
    }
    else{
        return head->value;
    }
}

template<class T>
void MyList<T>::sort(){
    mergeSort(&head);
}


template<class T>
void MyList<T>::insert(int index,const T & value){
    if(index == 0){
        add_front(value);
        return;
    }
    if(index >= (count-1)){
        add_back(value);
        return;
    }
    iterator it = begin();
    Node * current = it.get(index);
    Node *tmp = nullptr;
    tmp = new Node;
    tmp->value = value;
    if (current->next) {
        tmp->next = current->next;
    } else {
        tmp->next = nullptr;
    }
    current->next = tmp;
    count++;

}

template<class T>
void MyList<T>::remove(int index){
    if(empty()){
        std::cerr<<"Error[remove].Empty List!!!The program will be clossed"<<endl;
        exit(EXIT_FAILURE);
    }
    if (index == 0){
        pop_front();
        return;
    }
    if (index == (count - 1)){
        pop_back();
        return;
    }
    iterator it = begin();
    Node * current = it.get(index);
    Node *elm  = current->next;

    current->next = elm->next;
    delete elm;

    count--;
}

template<class T>
T & MyList<T>::get(int index){
    iterator it = begin();
    if (it.get(index) == nullptr){
        std::cerr << "Error[get].You try get nonexistent element. The program will be clossed";
        exit (EXIT_FAILURE);
    }
    return *it;
}

template<class T>
void MyList<T>::set(int index, T value){
    iterator it = begin();
    Node * current = it.get(index);
    if (current == nullptr){
        std::cerr << "Error[get].You try set value to nonexistent element. The program will be clossed";
        exit (EXIT_FAILURE);
    }
    current->value = value;
}

template<class T>
bool MyList<T>::isEqual(MyList const & list){
    if(this->count != list.count)
        return false;
    for(const_iterator lIt = const_begin(), rIt = list.const_begin(); lIt != const_end(); ++lIt, ++rIt){
        if(*lIt != *rIt)
            return false;
    }
    return true;
}

template<class T>
typename MyList<T>::MyList & MyList<T>::operator=(MyList const & list){
    if(this != &list){
        clear();
        head = 0;
        tail = 0;
        count = 0;
        Node * current = list.head;
        for(int i = 0; i < list.count; ++i){
            add_back(current->value);
            current = current->next;
        }

    }
    return *this;
}

template<class T>
bool MyList<T>::operator==(MyList & list){
    return isEqual(list);
}

template<class T>
bool MyList<T>::operator!=(MyList  & list){
    return !isEqual(list);
}

template<class T>
T & MyList<T>::operator[](int i){
    return get(i);
}

template<class T>
typename MyList<T>::iterator MyList<T>::begin(){
    return iterator(head);
}

template<class T>
typename MyList<T>::iterator MyList<T>::end() {
    return iterator(tail->next);
}


template<class T>
typename MyList<T>::const_iterator MyList<T>::const_begin() const{
    return const_iterator(head);
}

template<class T>
typename MyList<T>::const_iterator MyList<T>::const_end() const{
    return const_iterator(tail->next);
}
template<class T>
std::istream& operator>>(std::istream & stream, MyList<T> & list){
    for (int i = 0; i < list.size(); ++i){
        stream >> list.get(i);
    }
    return stream;
}

template<class T>
std::ostream& operator<<(std::ostream & stream, MyList<T> & list){
    stream << "(";
    for (int i = 0; i < list.size() - 1; ++i){
        stream << list.get(i) << ", ";
    }
    stream << list.get(list.size() - 1) << ")";
    return stream;
}

// doublelist.h

#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()

template <typename T>
struct DoubleNode {
// the default access mode and default inheritance mode are public
    T value;
    DoubleNode *next, *prev;
    // konstruktor domyslny (niepotrzebny)
    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T& item, DoubleNode *nptr=nullptr, DoubleNode *pptr=nullptr)
        : value(item), next(nptr), prev(pptr) {} // konstruktor
    ~DoubleNode() {} // destruktor
};


template <typename T>
class DoubleList {
    DoubleNode<T> *head, *tail;
public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList(); // tu trzeba wyczyscic wezly  

    DoubleList(const DoubleList& other); // copy constructor 
    // usage:   DoubleList<int> list2(list1);

    DoubleList& operator=(const DoubleList& other); // copy assignment operator, return *this 
    // usage:   list2 = list1;

    bool empty() const { 
        return head == nullptr; 
        }
    int size() const; // O(n) bo trzeba policzyc
    void push_front(const T& item); // O(1)
    void push_front(T&& item);
    void push_back(const T& item); // O(1)
    T& front() const { return head->value; } // zwraca poczatek, nie usuwa
    T& back() const { return tail->value; } // zwraca koniec, nie usuwa
    void pop_front(); // usuwa poczatek O(1)
    void pop_back(); // usuwa koniec O(1)
    void clear(); // czyszczenie listy z elementow O(n)
    void display(); // O(n)
    void display_reversed(); // O(n)

    // Operacje z indeksami. NIEOBOWIAZKOWE
    // T& operator[](int pos); // podstawienie L[pos]=item, odczyt L[pos]
    // const T& operator[](int pos) const; // dostep do obiektu const
    // void erase(int pos);
    // int index(const T& item); // jaki index na liscie (-1 gdy nie ma) O(n)
    // void insert(int pos, const T& item); // inserts item before pos,
    // void insert(int pos, T&& item); // inserts item before pos,
    // // Jezeli pos=0, to wstawiamy na poczatek.
    // // Jezeli pos=size(), to wstawiamy na koniec.
};

template <typename T>
void DoubleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new DoubleNode<T>(item, head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
}

template <typename T>
void DoubleList<T>::push_front(T&& item) {
    if (!empty()) {
        head = new DoubleNode<T>(std::move(item), head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(std::move(item));
    }
}


//destruktor
template<typename T>
DoubleList<T>::~DoubleList(){
    for(DoubleNode<T>* temp; !empty(); ){
        temp = head->next;
        delete head;
        head = temp;
    }
}

//konstruktor kopiujacy
template <typename T>
DoubleList<T>::DoubleList(const DoubleList& other){
    if(this!=&other){
        head = nullptr;
        tail = nullptr;
        DoubleNode<T> *temp = other.head;
        while(temp!=nullptr){
            push_back(temp->value);
            temp = temp->next;
        }
    }
}

//operator =
template <typename T>
DoubleList<T>& DoubleList<T>::operator=(const DoubleList& other){
    if(this!=&other){
        head = nullptr;
        tail = nullptr;
        DoubleNode<T> *temp = other.head;
        while(temp!=nullptr){
            push_back(temp->value);
            temp = temp->next;
        }
    }
    return *this;
}

//metode size()
template <typename T>
int DoubleList<T>::size() const{
    if(empty()){
        return 0;
    }
    if(head==tail){
        return 1;
    }
    int DLLsize = 0;
    DoubleNode<T>* temp = head;
    while(temp!=nullptr){
        DLLsize++;
        temp = temp->next;
    }
    return DLLsize;
}

//metoda push_back()
template <typename T>
void DoubleList<T>::push_back(const T& item){
    DoubleNode<T>* newNode = new DoubleNode<T>(item);
    if(empty()){
        tail = newNode;
        head = newNode;
    }else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

//metoda pop_front()
template <typename T>
void DoubleList<T>::pop_front(){
    assert(!empty());

    DoubleNode<T>* temp = head;
    
    if(head==tail){
        head = nullptr;
        tail = nullptr;
    }else{
        head = temp->next;
        head->prev = nullptr;
    }
    delete temp;
}
//metoda pop_back()
template <typename T>
void DoubleList<T>::pop_back(){
    assert(!empty());

    DoubleNode<T>* temp = tail;

    if(head==tail){
        head = nullptr;
        tail = nullptr;
    }else{
        tail = temp->prev;
        tail->next = nullptr;
    }
    delete temp;
}

//metoda clear()
template <typename T>
void DoubleList<T>::clear(){
    assert(!empty());
    DoubleNode<T>* temp = head;
    while(temp !=nullptr){
        temp = head->next;
        delete head;
        head = temp;
    }
}

//metoda display()
template <typename T>
void DoubleList<T>::display(){
    DoubleNode<T> *temp =  head;
    while(temp!=nullptr){
        std::cout<<temp->value<<" ";
        temp = temp->next;
    }
}

//metoda display_reversed()
template <typename T>
void DoubleList<T>::display_reversed(){
    assert(!empty());

    DoubleNode<T>* before = head;
    DoubleNode<T>* current = head->next;
    DoubleNode<T>* after = head->next->next;

    while(current != nullptr) {
        if(before->prev == nullptr) {
            before->prev = current;
            before->next = nullptr;
            tail = before;
        }
        current->next = before;
        current->prev = after;
        before = current;
        current = after;
        if(after != nullptr) {
                after = after->next;
        }
    }
    head = before;
    display();
}


#endif
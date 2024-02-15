#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>     
#include <cassert>    
template <typename T>
struct SingleNode {

    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {}
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    ~SingleNode() {} 
};

template <typename T>

class SingleList {
    SingleNode<T> *head, *tail;

public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList();

    SingleList(const SingleList& other);

    SingleList& operator=(const SingleList& other);

    bool empty() const { 
        return head == nullptr; 
        }

    int size() const; 
    void push_front(const T& item); 
    void push_back(const T& item);
    T& front() const { 
        return head->value; 
        } 
    T& back() const { 
        return tail->value; 
        } 
    void pop_front();
    void pop_back(); 
    void clear();
    void display(); 
    void reverse(); 

};

template <typename T>
SingleList<T>::~SingleList() {
    for (SingleNode<T> *node; !empty(); ) {
        node = head->next;
        delete head;
        head = node; 
    }

}

template <typename T>
void SingleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new SingleNode<T>(item, head);
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::push_back(const T& item) {
    if (!empty()) {
        tail->next = new SingleNode<T>(item);
        tail = tail->next;
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::display() {
    SingleNode<T> *node = head;
    while (node != nullptr){
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void SingleList<T>::pop_front() {
    assert(!empty());
    SingleNode<T> *node = head; 
    if (head == tail) { 
        head = tail = nullptr;
    } else { 
        head = head->next;
    }
    delete node;
}

template <typename T>
void SingleList<T>::pop_back() {
    assert(!empty());
    SingleNode<T> *node = tail; 
    if (head == tail) { 
        head = tail = nullptr;
    } else { 
        SingleNode<T> *before=head;
        while (before->next != tail) {
            before = before->next;
        }
        tail = before;
        tail->next = nullptr;
    }
    delete node;
}

//Napisane funkcje 

template <typename T>
int SingleList<T>::size() const {
    if(empty()==true){
        return 0;
    }
    if(head==tail){
        return 1;
    }
    int size = 0;
    SingleNode<T> *temp = head;
    while(temp!=nullptr){
        size++;
        temp = temp->next;
    }
    return size;
}

template <typename T>
void SingleList<T>::reverse() {

    assert(!empty());
    SingleNode<T> *temp = head;
    head = tail;
    tail = temp;

    SingleNode<T> *after = tail->next;
    SingleNode<T> *before = new SingleNode<T>;
    before = nullptr;

    while(temp!=nullptr){
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
}

template <typename T>
void SingleList<T>::clear(){
    
    assert(!empty());

    SingleNode<T>* temp = new SingleNode<T>;

    while(temp!=nullptr){
        temp = head->next;
        delete head;
        head = temp;
    }
}

//Konstruktor kopiujacy i operator przypisania =

template <typename T>
SingleList<T>::SingleList(const SingleList& other){
    if(this!=&other){
        head = nullptr;
        tail = nullptr;
        SingleNode<T>* temp = other.head;
        while(temp!=nullptr){
            push_back(temp->value);
            temp = temp->next;
        }
    }
}

template <typename T>
SingleList<T>& SingleList<T>::operator=(const SingleList& other){
    if(this!=&other){
        head = nullptr;
        tail = nullptr;
        SingleNode<T>* temp = other.head;
        while(temp!=nullptr){
        push_back(temp->value);
        temp = temp->next;
        }
    }
    return *this;
}

#endif
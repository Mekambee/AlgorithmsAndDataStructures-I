
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>    
#include <cassert>    
#include <algorithm>

template <typename T>

class ArrayList {
    T* tab;
    int msize; 
    int last; 
    
    public:
    ArrayList(int s=10) : msize(s), last(0) {
        assert( s > 0 );
        tab = new T[s];
        assert( tab != nullptr );
    } 

    ~ArrayList() { 
        delete [] tab; 
        }

    ArrayList(const ArrayList& other) : msize(other.msize), last(other.last){
        tab = new T[msize];
        for(int i=0; i<last;i++){
            tab[i] = other.tab[i];
        }
    }


    ArrayList& operator=(const ArrayList& other){
        {
        if(this != &other){
            delete[] tab;
            msize = other.msize;
            last = other.last;
            tab = new T[msize];
            for (int i = 0; i < last; i++) {
                tab[i] = other.tab[i];
            }
        }
        return *this;
    }
    }

    ArrayList& operator=(ArrayList&& other){
        if(this != &other){
            delete[] tab;
            tab = other.tab;
            msize = other.msize;
            last = other.last;
            other.tab = nullptr;
            other.msize = 0;
            other.last = 0;
        }
        return *this;
    }

    bool empty() const { 
        return last == 0; 
        }

    bool full() const { 
        return last == msize; 
        }

    int size() const { 
        return last;
        } 

    int max_size() const { 
        return msize; 
        } 

    void push_front(const T& item){
        assert(!full());
            for(int i = last; i > 0; i--){ 
                tab[i] = tab[i-1];
            }
            tab[0] = item;
            last++;
    }

    void push_back(const T& item){
        assert(!full());
        tab[last] = item;
        last++;
    }

    T& front(){
        assert(!empty());
        return tab[0]; 
    }

    T& back(){
        assert(!empty());
        return tab[last-1];
    }

    void pop_front(){
        assert(!empty());
        for(int i=0; i<last-1;i++){
            tab[i] = tab[i+1];
        }
        last--;
    }

    void pop_back(){
        assert(!empty());
        last--;
    }

    void clear(){
        last=0;
    }

    void display(){
        for(int i = 0; i < last; ++i){
            std::cout << tab[i] << " ";
        }
        std::cout << std::endl;
    }

    void reverse(){
        assert(!empty());
        int listStart = 0;
        int listEnd = last -1;
        while(listStart<listEnd){
            std::swap(tab[listStart],tab[listEnd]);
            listStart++;
            listEnd--;
        }
    }

    void sort(){
        assert(!empty());
        std::sort(tab, tab + last, std::less_equal<T>());
    }

    T& operator[](int pos){
        assert(indexCheck(pos));
        return tab[pos];
    }

    const T& operator[](int pos) const{
        assert(indexCheck(pos));
        return tab[pos];
    } 

    void erase(int pos){
        assert(indexCheck(pos));
        for(int i = pos; i<last-1;i++){
            tab[i] = tab[i+1];  
        }
        last--;    
    }

    int index(const T& item){
        for(int i =0;i<last;i++){
            if(tab[i]==item){
                return i;
                }
            }
            return -1;
        }

    void insert(int pos, const T& item){
        assert(indexCheck(pos));
        assert(!full());
        for(int i = last; i > pos; i--){
            tab[i] = tab[i-1];
        }
        tab[pos] = item;
        last++;
    } 

    void insert(int pos, T&& item){
        assert(indexCheck(pos));
        assert(!full());

        if(pos==0){
            push_front(item);
            return;
        }

        if(pos==last){
            push_back(item);
            return;
        }

        for(int i = last; i > pos; i--){
        tab[i] = tab[i - 1];
            }
        tab[pos] = item;
        last++;
    }

    friend std::ostream& operator<<(std::ostream& os, const ArrayList& L) {
        for (int i=0; i < L.last; ++i) { 
            os << L.tab[i] << " ";  
        }
        return os;
    } 

    bool indexCheck(int pos){
        if(pos>=0 && pos<=last){
            return true;
        }else{
            return false;
        }
    }
};

#endif
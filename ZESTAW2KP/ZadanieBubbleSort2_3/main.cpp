#include <iostream>
#include <cassert>
#include <algorithm>

template <typename T>

void swapElements(T &aRef, T &bRef){
    T temp = aRef;
    aRef = bRef;
    bRef = temp;
}

template <typename T>


void bubbleSort(T *ptr, int left, int right){
    for(int i = left; i<right ; i++){
        for(int j = left; j < right-i; j++){
            if(ptr[j] > ptr[j+1]){
                swapElements(ptr[j], ptr[j+1]);
            }
        }
    }
}


int main(){
    int myArr[] = {1, 8, 3, 6, 2, 9, 7, 4, 5};
    
    int myArrSize = sizeof(myArr)/sizeof(myArr[0]);
    int left = 0;
    int right = myArrSize-1;
    
    bubbleSort(myArr, left, right);
    
    assert(std::is_sorted(std::begin(myArr), std::end(myArr)));

    for(auto& item : myArr){
        std::cout<<item<<",";
    }
}


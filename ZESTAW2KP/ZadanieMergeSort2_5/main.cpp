#include <iostream>
#include <cassert>
#include <algorithm>


template <typename T>

void merge(T *ptr, int left, int mid, int right){

    int leftArraySize = mid - left + 1;
    int rightArraySize = right - mid;
    
    T leftCopiedArray[leftArraySize];
    T rightCopiedArray[rightArraySize];
    
    for(int i=0; i<leftArraySize;i++){
        leftCopiedArray[i] = ptr[left + i]; 
    }
    for(int i=0; i<rightArraySize;i++){
        rightCopiedArray[i] = ptr[mid + 1 + i]; 
    }

    int index = left;
    int i=0;
    int j=0;

    while(i<leftArraySize && j<rightArraySize){
        if(leftCopiedArray[i]<=rightCopiedArray[j]){
            ptr[index] = leftCopiedArray[i];
            index++;
            i++;
        }else{
            ptr[index] = rightCopiedArray[j];
            index++;
            j++;
        }
    }

    while(i<leftArraySize){
        ptr[index] = leftCopiedArray[i];
        i++;
        index++;
    }

    while(j<rightArraySize){
        ptr[index] = rightCopiedArray[j];
        j++;
        index++;
    }
}

template <typename T>


void mergeSort(T *ptr, int left, int right){

    if(left>=right) return;
    
    int mid = left + (right - left) /2;
    mergeSort(ptr, left, mid); 
    mergeSort(ptr, mid+1, right);
    merge(ptr, left, mid, right);
}

int main(){
    int myArr[] = {1, 8, 3, 6, 2, 9, 7, 4, 5};
    
    int myArrSize = sizeof(myArr)/sizeof(myArr[0]);
    int left = 0;
    int right = myArrSize-1;
    
    mergeSort(myArr, left, right);
    
    assert(std::is_sorted(std::begin(myArr), std::end(myArr)));
    
    for(auto& item : myArr){
        std::cout<<item<<",";
    }
}
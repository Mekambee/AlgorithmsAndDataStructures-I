#include <iostream>
#include "myqueue.h"

int main(){
    MyQueue<int> myQ;
    myQ.push(5);
    myQ.push(3);
    myQ.push(7);
    myQ.push(4);
    myQ.push(9);
    myQ.push(2);
    myQ.push(1);
    myQ.push(6);
    myQ.push(8);

    std::cout<<"Bazowa kolejka na bazie tablicy cyklicznej, wypełniona elementami metodą push(), wypisywanie kolejek metoda display()"<<std::endl;
    myQ.display();

    MyQueue<int> copiedQ(myQ);
    std::cout<<"Uzycie konstruktora kopiującego: "<<std::endl;
    copiedQ.display();

    MyQueue<int> operCopiedQ;
    operCopiedQ = myQ;
    std::cout<<"Uzycie operatora kopiującego: "<<std::endl;
    operCopiedQ.display();

    std::cout<<"Czy pusta? : "<<myQ.empty()<<std::endl;
    std::cout<<"Czy pełna? : "<<myQ.full()<<std::endl;
    std::cout<<"Rozmiar kolejki: "<<myQ.size()<<std::endl;
    std::cout<<"Maksymalny rozmiar kolejki: "<<myQ.max_size()<<std::endl;
    std::cout<<"Pierwszy element (head) : "<<myQ.front()<<std::endl;
    std::cout<<"Ostatni element (tail) : "<<myQ.back()<<std::endl;

    std::cout<<"Kolejka po pop(): "<<std::endl;
    myQ.pop();
    myQ.display();

    MyQueue<int> movedQ(std::move(myQ));
    std::cout<<"Uzycie konstruktora przenoszącego: "<<std::endl;
    movedQ.display();

    MyQueue<int> operMovedQ;
    operMovedQ = std::move(movedQ);
    std::cout<<"Uzycie operatora przenoszącego: "<<std::endl;
    operMovedQ.display();

    std::cout<<"Kolejka po wyczyszczeniu: "<<std::endl;
    myQ.clear();    
    myQ.display();







}
#include <iostream>
#include "mypriorqueue.h"

int main(){
    MyPriorityQueue<int> mypriorQ;
    mypriorQ.push(5);
    mypriorQ.push(3);
    mypriorQ.push(7);
    mypriorQ.push(4);
    mypriorQ.push(9);
    mypriorQ.push(2);
    mypriorQ.push(1);
    mypriorQ.push(6);
    mypriorQ.push(8);

    std::cout<<"Bazowa kolejka na bazie vectora i kopca, wypełniona elementami metodą push(), wypisywanie kolejek metoda display()"<<std::endl;
    mypriorQ.display();

    MyPriorityQueue<int> copiedQ(mypriorQ);
    std::cout<<"Uzycie konstruktora kopiującego: "<<std::endl;
    copiedQ.display();

    MyPriorityQueue<int> operCopiedQ;
    operCopiedQ = mypriorQ;
    std::cout<<"Uzycie operatora kopiującego: "<<std::endl;
    operCopiedQ.display();

    std::cout<<"Czy pusta? : "<<mypriorQ.empty()<<std::endl;
    std::cout<<"Rozmiar kolejki: "<<mypriorQ.size()<<std::endl;
    std::cout<<"Element najwiekszy: "<<mypriorQ.top()<<std::endl;


    std::cout<<"Kolejka po pop() (Usuniecie elemementu najwiekszego): "<<std::endl;
    mypriorQ.pop();
    mypriorQ.display();

    MyPriorityQueue<int> movedQ(std::move(mypriorQ));
    std::cout<<"Uzycie konstruktora przenoszącego: "<<std::endl;
    movedQ.display();

    MyPriorityQueue<int> operMovedQ;
    operMovedQ = std::move(movedQ);
    std::cout<<"Uzycie operatora przenoszącego: "<<std::endl;
    operMovedQ.display();

    std::cout<<"Kolejka po wyczyszczeniu: "<<std::endl;
    mypriorQ.clear();    
    mypriorQ.display();


}
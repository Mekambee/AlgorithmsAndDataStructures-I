#include <iostream>
#include "doublelist.h"


int main(){
    
std::cout<<"Lista podwojnie wiazana uzupelniona metodami push_back() i push_front(), wyswietlanie list metodą display()"<<std::endl;
DoubleList<int> dll;
dll.push_front(5);
dll.push_front(8);
dll.push_front(4);
dll.push_back(3);
dll.push_back(1);
dll.push_back(6);
dll.push_front(2);
dll.push_back(7);
dll.push_back(9);

dll.display();

DoubleList<int> copiedDLL(dll);
std::cout<<std::endl<<"Uzycie konstruktora kopiującego: "<<std::endl;
copiedDLL.display();

DoubleList<int> operCopiedDLL;
operCopiedDLL = dll;
std::cout<<std::endl<<"Uzycie operatora = "<<std::endl;
operCopiedDLL.display();

std::cout<<std::endl<<"Pierwszy item: "<<dll.front()<<std::endl;
std::cout<<"Ostatni item: "<<dll.back()<<std::endl;
std::cout<<"Rozmiar listy: "<<dll.size()<<std::endl;
std::cout<<"Czy pusta? : "<<dll.empty()<<std::endl;

std::cout<<"Lista po pop_front(): "<<std::endl;
dll.pop_front();
dll.display();

std::cout<<std::endl<<"Lista po pop_back(): "<<std::endl;
dll.pop_back();
dll.display();

std::cout<<std::endl<<"Reverse i display listy: "<<std::endl;
dll.display_reversed();

std::cout<<std::endl<<"Lista po wyczyszczeniu: "<<std::endl;
dll.clear();
dll.display();


}
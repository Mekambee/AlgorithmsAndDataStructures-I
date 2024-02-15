#include <iostream>
#include "singlelist.h"

int main(){

SingleList<int> linkedList;
linkedList.push_front(5);
linkedList.push_front(2);
linkedList.push_back(3);
linkedList.push_back(1);
linkedList.push_front(6);
linkedList.push_front(7);
linkedList.push_back(8);
linkedList.push_front(4);

std::cout<<std::endl<<"Wyswietlanie metodą display: "<<std::endl<<std::endl;

std::cout<<"Poczatkowa lista (wstawienie elementow przez push_back i push_front): "<<std::endl;
linkedList.display();

SingleList<int> consCopiedLL(linkedList);
std::cout<<"Lista skopiowana konstruktorem: "<<std::endl;
consCopiedLL.display();

SingleList<int> operCopiedLL;
operCopiedLL = linkedList;
std::cout<<"Lista skopiowana operatorem = : "<<std::endl;
operCopiedLL.display();

std::cout<<"Pierwszy item: "<<linkedList.front()<<std::endl;
std::cout<<"Ostatni item: "<<linkedList.back()<<std::endl;
std::cout<<"Rozmiar listy: "<<linkedList.size()<<std::endl;

std::cout<<"Reverse listy: "<<std::endl;
linkedList.reverse();
linkedList.display();


std::cout<<"Lista po pop_front(): "<<std::endl;
linkedList.pop_front();
linkedList.display();

std::cout<<"Lista po pop_back(): "<<std::endl;
linkedList.pop_back();
linkedList.display();

std::cout<<"Czy pusta? : "<<linkedList.empty()<<std::endl;

std::cout<<"Lista po wyczyszczeniu: "<<std::endl;
linkedList.clear();
linkedList.display();


}
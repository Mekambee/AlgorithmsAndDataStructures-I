#include <iostream>
#include "mydeque.h"

int main(){

MyDeque<int> mdq(20);
mdq.push_back(5);
mdq.push_back(4);
mdq.push_front(2);
mdq.push_front(7);
mdq.push_back(3);
mdq.push_back(1);
mdq.push_front(6);
mdq.push_front(9);
mdq.push_back(8);

std::cout<<"Bazowa kolejka dwustronna, wypełniona metodami push_back() i push_front(), wypisywanie kolejek metodą display()"<<std::endl;
mdq.display();

MyDeque<int> CopiedMDQ(mdq);
std::cout<<"Uzycie konstruktora kopiującego: "<<std::endl;
CopiedMDQ.display();

MyDeque<int> operCopiedMDQ;
operCopiedMDQ = mdq;
std::cout<<"Uzycie operatora = "<<std::endl;
operCopiedMDQ.display();

std::cout<<"Czy pusta? : "<<mdq.empty()<<std::endl;
std::cout<<"Czy pełna? : "<<mdq.full()<<std::endl;
std::cout<<"Rozmiar kolejki: "<<mdq.size()<<std::endl;
std::cout<<"Maksymalny rozmiar kolejki: "<<mdq.max_size()<<std::endl;
std::cout<<"Pierwszy element (head) : "<<mdq.front()<<std::endl;
std::cout<<"Ostatni element (tail) : "<<mdq.back()<<std::endl;

std::cout<<"Kolejka po pop_front(): "<<std::endl;
mdq.pop_front();
mdq.display();

std::cout<<"Kolejka po pop_back(): "<<std::endl;
mdq.pop_back();
mdq.display();

std::cout<<"Kolejka po wyczyszczeniu: "<<std::endl;
mdq.clear();
mdq.display();

}

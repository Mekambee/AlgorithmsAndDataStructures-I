#include <iostream>
#include <vector>
#include "arraylist.h"

int main(){

ArrayList<int> arrayList(20);
arrayList.push_back(5);
arrayList.push_front(3);
arrayList.push_back(6);
arrayList.push_back(4);
arrayList.push_back(1);
arrayList.push_front(2);
arrayList.push_front(7);

std::cout<<"Listy z przykladowym uzyciem metod i operatorow wypisywane operatorem przeciazeniem operatora << "<<std::endl;


std::cout<<"Poczatkowa Lista wstawiajac na koniec i poczatek (push_back(), push_front()): "<<arrayList<<std::endl;

ArrayList<int> copiedArrayListCon(arrayList);

std::cout<<"Uzycie konstruktora kopiujacego: "<<copiedArrayListCon<<std::endl;

ArrayList<int> copiedArrayList(20);

copiedArrayList = arrayList;

std::cout<<"Uzycie operatora kopiujacego: "<<copiedArrayList<<std::endl;

ArrayList<int> movedArrayList(20);
movedArrayList = std::move(arrayList);

std::cout<<"Uzycie operatora przenoszącego: "<<movedArrayList<<std::endl;

std::cout<<"Pierwszy element: "<<movedArrayList.front()<<std::endl;

std::cout<<"Ostatni element: "<<movedArrayList.back()<<std::endl;

movedArrayList.pop_front();

std::cout<<"Usuniecie pierwszego z listy: "<<movedArrayList<<std::endl;

movedArrayList.pop_back();

std::cout<<"Usuniecie ostatniego z listy: "<<movedArrayList<<std::endl;

movedArrayList.reverse();

std::cout<<"Reverse listy: "<<movedArrayList<<std::endl;

movedArrayList.sort();

std::cout<<"Posortowanie listy: "<<movedArrayList<<std::endl;

std::cout<<"Display: "<<std::endl;

movedArrayList.display();

movedArrayList[1] = 7;

std::cout<<"Wstawienie na pozycje 1 elementu 7 operatorem[]: "<<movedArrayList<<std::endl;

movedArrayList.insert(0,3);

std::cout<<"Wstawienie na pozycje 0 elementu 3 metoda insert(): "<<movedArrayList<<std::endl;

movedArrayList.erase(5);

std::cout<<"Usuniecie elementu o indexie 5 metoda erase(): "<<movedArrayList<<std::endl;

std::cout<<"Index elementu 7: "<<movedArrayList.index(7)<<std::endl;

movedArrayList.clear();

std::cout<<"Wyczyszczenie listy: "<<movedArrayList<<std::endl;

}
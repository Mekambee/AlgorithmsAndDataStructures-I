#include <iostream>
#include <cassert>
#include "polynomials.h"

int main(){

    int wspolczynniki_1[] = {0,2,0,2,6,1};
    int wspolczynniki_2[] = {1,4,5,0,4};
    int wspolczynniki_3[] = {1,4,5,0,4,0};

    
    int tabSize1 = sizeof(wspolczynniki_1) / sizeof(wspolczynniki_1[0]);
    int tabSize2 = sizeof(wspolczynniki_2) / sizeof(wspolczynniki_2[0]);
    int tabSize3 = sizeof(wspolczynniki_3) / sizeof(wspolczynniki_3[0]);

    Poly<int> wielomian_1(wspolczynniki_1, tabSize1);
    Poly<int> wielomian_2(wspolczynniki_2, tabSize2);
    Poly<int> wielomian_3(wspolczynniki_3, tabSize3);

    std::cout<<"Wielomian_1: "<<wielomian_1;
    std::cout<<"Wielomian_2: "<<wielomian_2;
    std::cout<<"Wielomian_3: "<<wielomian_3;

    std::cout<<"Rozmiar wielomianu_1: "<<wielomian_1.getSize()<<std::endl;
    std::cout<<"Stopien wielomianu 1: "<<wielomian_1.deegree()<<std::endl;
    std::cout<<"Dodawanie wielomianu_1 + wielomianu_2 : "<<wielomian_1 + wielomian_2;
    std::cout<<"Odejmowanie wielomianu_2 - wielomianu_1 : "<<wielomian_2 - wielomian_1;
    std::cout<<"Mnozenie wielomianu_1 * wielomianu_2 : "<<wielomian_1 * wielomian_2;

    std::cout<<"Uzycie algorytmu hornera w wielomianie_1 dla x = 1 : wynik  -->  "<<wielomian_1.algorytmHornera(1)<<std::endl;
    std::cout<<"Uzycie algorytmu hornera w wielomianie_1 dla x = 2 : wynik  -->  "<<wielomian_1.algorytmHornera(2)<<std::endl;

    std::cout<<"Uzycie operatora porównania == dla takich samych wielomianów 2 i 3 : "<<(wielomian_3==wielomian_2)<<std::endl;
    std::cout<<"Uzycie operatora porównania != dla takich samych wielomianów 2 i 3 : "<<(wielomian_3!=wielomian_2)<<std::endl;

    std::cout<<"Uzycie operatora [], w celu znalezenia współczynnika przy potędze 4 w wielomianie_1, szukana wartość --->  "<<wielomian_1[4]<<std::endl;
    std::cout<<"isZero(), wielomian_1 -->  "<<wielomian_1.isZero()<<std::endl;

}
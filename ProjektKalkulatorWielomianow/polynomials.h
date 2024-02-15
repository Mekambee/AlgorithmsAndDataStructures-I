#ifndef POLYNOMIALS_H
#define POLYNOMIALS_H

#include <cassert>

template <typename T>
class Poly {

private:
    T* wspolczynnikiWielomianu;
    int tabSize;

public:

    Poly() : wspolczynnikiWielomianu(), tabSize(0){}

    ~Poly() {delete[] wspolczynnikiWielomianu;}

    Poly(T* tab_wspolczynnikow, int size) : tabSize(size) {
        wspolczynnikiWielomianu = new T[size];
        std::copy(tab_wspolczynnikow, tab_wspolczynnikow + size, wspolczynnikiWielomianu);
    }
    
    Poly(const Poly& other) : wspolczynnikiWielomianu(new T[other.tabSize]), tabSize(other.tabSize) {
    std::copy(other.wspolczynnikiWielomianu, other.wspolczynnikiWielomianu + tabSize, wspolczynnikiWielomianu);
}

    bool isZero(){
        return tabSize == 0;
    }

    int getSize(){
        return tabSize;
    }

    int deegree() {
    for (int i = tabSize - 1; i >= 0; --i) {
        if (wspolczynnikiWielomianu[i] != T{}) {
            return i; 
        }
    }
    return 0; 
    }


void clear() {
    int ostatniNiezerowy = tabSize - 1;
    while (ostatniNiezerowy >= 0 && wspolczynnikiWielomianu[ostatniNiezerowy] == T{}) {
        --ostatniNiezerowy;
    }

    if (ostatniNiezerowy == -1) {
        delete[] wspolczynnikiWielomianu;
        wspolczynnikiWielomianu = nullptr;
        tabSize = 0;
    }

    int nowyRozmiar = ostatniNiezerowy + 1;
    T* nowaTablica = new T[nowyRozmiar];
    for (int i = 0; i < nowyRozmiar; ++i) {
        nowaTablica[i] = wspolczynnikiWielomianu[i];
    }

    delete[] wspolczynnikiWielomianu;
    wspolczynnikiWielomianu = nowaTablica;
    tabSize = nowyRozmiar;
}
    Poly operator+(const Poly& other) const {
        int sizeWynikowy = std::max(tabSize, other.tabSize);
        T* wielomianWynikowy = new T[sizeWynikowy];

        for(int i = 0 ; i < sizeWynikowy ; i++){

        T wspolczynnik1 = (i < tabSize) ? wspolczynnikiWielomianu[i] : T{};
        T wspolczynnik2 = (i < other.tabSize) ? other.wspolczynnikiWielomianu[i] : T{};
        wielomianWynikowy[i] = wspolczynnik1 + wspolczynnik2;

        }
        Poly res(wielomianWynikowy, sizeWynikowy);
        delete[] wielomianWynikowy;
        res.clear();
        return res;
    }

    Poly operator-(const Poly& other) const {
        int sizeWynikowy = std::max(tabSize, other.tabSize);
        T* wielomianWynikowy = new T[sizeWynikowy];

        for(int i = 0 ; i < sizeWynikowy ; i++){
        T wspolczynnik1 = (i < tabSize) ? wspolczynnikiWielomianu[i] : T{};
        T wspolczynnik2 = (i < other.tabSize) ? other.wspolczynnikiWielomianu[i] : T{};

        wielomianWynikowy[i] = wspolczynnik1 - wspolczynnik2;
            }
        Poly res(wielomianWynikowy, sizeWynikowy);
        delete[] wielomianWynikowy;
        res.clear();
        return res;
        }

    Poly operator*(const Poly& other) const {
    
    if(tabSize == 0 || other.tabSize ==0) return Poly();

    int sizeWynikowy = tabSize + other.tabSize;
    T* wielomianWynikowy = new T[sizeWynikowy]{};
    
    for(int i = 0; i < tabSize ; i++){
        for(int j = 0; j < other.tabSize; j++){
            wielomianWynikowy[i + j] += wspolczynnikiWielomianu[i] * other.wspolczynnikiWielomianu[j];
        }
    }
    Poly result(wielomianWynikowy, sizeWynikowy);
    delete[] wielomianWynikowy;
    result.clear();
    return result;
    }

    T algorytmHornera(const T& x) const {

    if(tabSize == 0){
        return T{};
    }

    T wynikHornera = wspolczynnikiWielomianu[tabSize - 1];  

    for (int i = tabSize - 2; i >= 0; --i) { 
        wynikHornera = wynikHornera * x + wspolczynnikiWielomianu[i];
    }

    return wynikHornera;
}

    bool operator==(const Poly& other) const {
        return ((*this - other).isZero()); 
    }
    
    bool operator!=(const Poly& other) const {
        return (!(*this - other).isZero());
    }

    T operator[](const int& power) const {
        assert(power<tabSize && power>-1);
        return wspolczynnikiWielomianu[power];
    }

    friend std::ostream& operator<<(std::ostream& os, const Poly& wielomian) {
    if (wielomian.tabSize == 0) {
        os << "Wielomian jest pusty --> 0";
    } else {
        int start = wielomian.tabSize - 1;
        if (wielomian.wspolczynnikiWielomianu[start] == T{}) {
            --start; 
        }

        for (int i = start; i >= 0; i--) {
            if (wielomian.wspolczynnikiWielomianu[i] != T{}) {
                if (i != start) { 
                    os << " ";
                    os << (wielomian.wspolczynnikiWielomianu[i] < T{} ? " - " : " + ");
                } else if (wielomian.wspolczynnikiWielomianu[i] < T{}) {
                    os << "-"; 
                }
                os << std::abs(wielomian.wspolczynnikiWielomianu[i]);
                if (i > 0) {
                    os << "x^" << i;
                }
            }
        }
    }
    os << std::endl;
    return os;
    }
    };

    





































#endif
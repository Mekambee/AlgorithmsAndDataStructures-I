Kamil Piechota
Projekt Zaliczeniowy , Algorytmy i Struktury Danych I
-----------------------------------------------------------------------------------------------------------------------

/*
Implementacja wielomianów na bazie tablic (szablon, współczynniki typu T). Działania na wielomianach: dodawanie (operator+), odejmowanie (operator-), mnożenie (operator*), obliczanie wartości wielomianu (algorytm Hornera), porównywanie (operator==, operator!=), wyświetlanie. Wielomiany są równe, gdy ich różnica jest wielomianem zerowym. Klasa Poly przechowuje tablicę współczynników i implementuje działania. Przydają się funkcje clear(), is_zero(), operator[] (odczyt współczynnika przy danej potędze x).
*/
-----------------------------------------------------------------------------------------------------------------------

Zadanie polegało na tym, aby odtworzyć własności wielomianów takie jak dodawanie, odejmowanie, mnożenie, czy np. wyliczanie wartości wielomianu poprzez algorytm Hornera na bazie tablic o współczynnikach typu T. Elementy w tych tablicach, które są polem klasy Poly odpowiadają za wartości współczynników wielomianów, a ich indeksy za potęgi przy x.

Program składa się z pliku głównego main.cpp, w którym zostały zaprezentowane funkcjonalności kodu, poprzez utworzenie instancji klasy Poly, oraz wywołanie na nich metod i operatorów, które należało zaimplementować. Implementacja całej klasy Poly wraz z wszystkimi polami, metodami, oraz przeciążanymi operatorami znajduje się w pliku nagłówkowym polynomials.h 
-----------------------------------------------------------------------------------------------------------------------

Aby dokonać kompilacji oraz uruchomić program implementujący zadanie projektowe opisane powyżej należy użyc komendy: make
Aby usunąć pliki po kompilacji : make clean
-----------------------------------------------------------------------------------------------------------------------

Krótki opis implementacji:

-----------------------------------------------------------------------------------------------------------------------
Konstruktory:

Konstruktor domyślny Poly()

Inicjuje pusty wielomian bez współczynników (wspolczynnikiWielomianu jest puste), a tabSize ustawia na 0.

Konstruktor z parametrami Poly(T* tab_wspolczynnikow, int size)

Tworzy wielomian na podstawie dostarczonej tablicy współczynników i kopiuje je jako atrybuty w naszej klasie.

Konstruktor kopiujący Poly(const Poly& other)

Tworzy kopię obiektu klasy Poly.

Destruktor ~Poly()

Zwalnia pamięć zaalokowaną dla tablicy wspolczynnikiWielomianu.

-----------------------------------------------------------------------------------------------------------------------
Przeciążone operatory:

Dodawanie Poly operator+(const Poly& other)

//Dodaje dwa wielomiany, zwracając wynik jako nowy wielomian.

Odejmowanie Poly operator-(const Poly& other)

//Odejmuje dwa wielomiany, zwracając wynik jako nowy wielomian.

Mnożenie Poly operator*(const Poly& other)

//Mnoży dwa wielomiany zwracając wynik jako nowy wielomian.

bool operator==(const Poly& other)

//Sprawdza, czy dwa wielomiany są równe, wykorzystując operator (-) i metodę isZero().

bool operator!=(const Poly& other)

//Sprawdza, czy dwa wielomiany nie są równe tą samą metodą.

T operator[](const int& power)

//Zwraca współczynnik przy danej potędze wielomianu.

operator<<(std::ostream& os, const Poly& wielomian)

//Umożliwia wypisanie wielomianu na standardowe wyjście.

-----------------------------------------------------------------------------------------------------------------------
Metody:

bool isZero()

//Sprawdza, czy wielomian jest zerowy (czyli czy tabSize jest równy 0).

int getSize()

//Zwraca rozmiar tablicy współczynników (tabSize).

int deegree()

//Zwraca stopień wielomianu, czyli najwyższą potęgę z niezerowym współczynnikiem.

void clear()

//Usuwa wszystkie zbędne zerowe współczynniki na końcu wielomianu.

T algorytmHornera(const T& x)
//Oblicza wartość wielomianu dla podanego argumentu x używając algorytmu Hornera.

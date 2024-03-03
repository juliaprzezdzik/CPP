/*
Zaimplementuj klasę wektora Iwektor3D liczb typu int o rozmiarze 3, które wewnętrznie przechowywane są w postaci alokowanej dynamicznie tablicy (a nie std::vectora !) uwzględniając:

konstruktory (w tym kopiujący)
destruktor,
oraz następujące przeładowane operatory:

operator przypisania,
operatory + i - (dodawanie i odejmowanie wektorów),
operator mnożenia przez liczbę całkowitą (powinien umożliwiać mnożenie z obu stron),
operator mnożenia wektora przez wektor (iloczyn skalarny),
operator [] (powinien umożliwiać zarówno pobieranie jak i ustawienie składowej wektora),
jednoargumentowy operator - (zamiana na wektor przeciwny).
<< wstawianie wektora do strumienia wyjściowego.
Następnie zainicjuj dwa wektory:

v1=(2,2,2) i v2=(1,1,1)

i wypisz na standardowe wyjście wynik następujących operacji (w tej kolejności !):

v1+v2
v1-v2
v1*2
2*v1
v1*v2
v1[0]==(v2[0]=2*v2[0])
v1[0]!=(v2[0]=2*v2[0])
-v2
Wszystkie wyniki wyprowadź na ekran operatorem <<.
*/

#include <iostream>

using namespace std;

class Iwektor3D {
        int *tab;
    public:
        Iwektor3D();
        Iwektor3D(int a, int b, int c);
        ~Iwektor3D();
        Iwektor3D operator+(const Iwektor3D& w);
        Iwektor3D operator-(const Iwektor3D& w);
        Iwektor3D operator*(int v)const;
        friend Iwektor3D operator*(int v, const Iwektor3D& w);
        Iwektor3D operator*(const Iwektor3D& w); //iloczyn skalarny!!!!
        friend ostream& operator<<(ostream& os, const Iwektor3D& w); 
        Iwektor3D operator-();
        Iwektor3D(const Iwektor3D& w); //konstruktor kopiujacy
        Iwektor3D& operator=(const Iwektor3D& w); //operator przypisania
        const int& operator[](int index)const; //operator indeksowania dla pobierania wartosci
        int& operator[](int index); //operator indeksowania dla ustawiania wartosci
};

Iwektor3D::Iwektor3D(){
    tab = new int[3];
}

Iwektor3D::Iwektor3D(int a, int b, int c){
    tab = new int[3];
    tab[0] = a; 
    tab[1] = b;
    tab[2] = c;
}

Iwektor3D::~Iwektor3D(){
    delete[] tab;
}

Iwektor3D Iwektor3D::operator+(const Iwektor3D& w){
    Iwektor3D W(this->tab[0]+w.tab[0], this->tab[1]+w.tab[1], this->tab[2]+w.tab[2]);
    return W;
}

Iwektor3D Iwektor3D::operator-(const Iwektor3D& w){
    Iwektor3D W(this->tab[0]-w.tab[0], this->tab[1]-w.tab[1], this->tab[2]-w.tab[2]);
    return W;
}

Iwektor3D Iwektor3D::operator*(int v)const{
    Iwektor3D W(this->tab[0]*v, this->tab[1]*v, this->tab[2]*v);
    return W;
}

Iwektor3D operator*(int v, const Iwektor3D& w){
    Iwektor3D W(w.tab[0]*v, w.tab[1]*v, w.tab[2]*v);
    return W;
}

Iwektor3D Iwektor3D::operator*(const Iwektor3D& w){
    Iwektor3D W(this->tab[0]*w.tab[0], this->tab[1]*w.tab[1], this->tab[2]*w.tab[2]);
    return W;
}

ostream& operator<<(ostream& os, const Iwektor3D& w){
    os << "(" << w.tab[0] << ", " << w.tab[1] << ", " << w.tab[2] << ")" << endl;
    return os;
}

Iwektor3D Iwektor3D::operator-(){
    Iwektor3D W(-this->tab[0], -this->tab[1], this->tab[2]);
    return W;
}

Iwektor3D::Iwektor3D(const Iwektor3D& w){
    tab = new int[3];
    this->tab[0] = w.tab[0];
    this->tab[1] = w.tab[1];
    this->tab[2] = w.tab[2];
}

Iwektor3D& Iwektor3D::operator=(const Iwektor3D& w){
    if(this != &w){
        tab[0] = w.tab[0];
        tab[1] = w.tab[1];
        tab[2] = w.tab[2];
    }
    return *this;
}

int& Iwektor3D::operator[](int index){
    return tab[index];
}

const int& Iwektor3D::operator[](int index)const{
    return tab[index];
}


int main(){

    Iwektor3D v1(2,2,2);
    Iwektor3D v2(1,1,1);
    cout << v1 + v2;
    cout << v1 - v2;
    cout<< v1 * 2;
    cout << 2 * v1;
    cout << v1 * v2; 
    cout << (v1[0]==(v2[0]=2*v2[0]));
    cout << (v1[0]!=(v2[0]=2*v2[0]));
    cout << -v2;

    return 0;
}

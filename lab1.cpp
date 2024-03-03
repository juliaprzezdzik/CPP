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
        int operator*(const Iwektor3D& w);
        Iwektor3D operator-();
        Iwektor3D operator*(int val);
        void print_wektor()const;

};

Iwektor3D::Iwektor3D(){
    tab = new int[3];
    for(int i = 0; i < 3; i++){
        tab[i] = 0;
    }
}

void Iwektor3D::print_wektor()const{
    cout << tab[0] << " " << tab[1] << " " << tab[2] << endl;
}

Iwektor3D::Iwektor3D(int a, int b, int c){
    tab = new int[3];
    tab[0] = a;
    tab[1] = b;
    tab[2] = c;
}

Iwektor3D::~Iwektor3D(){
    delete tab;
}

Iwektor3D Iwektor3D::operator+(const Iwektor3D& w){
    int a = this->tab[0] + w.tab[0];
    int b = this->tab[1] + w.tab[1];
    int c = this->tab[2] + w.tab[2];
    Iwektor3D W;
    W.tab[0] = a;
    W.tab[1] = b;
    W.tab[2] = c; 
    return W;
}

Iwektor3D Iwektor3D::operator-(const Iwektor3D& w){
    int a = this->tab[0] - w.tab[0];
    int b = this->tab[1] - w.tab[1];
    int c = this->tab[2] - w.tab[2];
    Iwektor3D W;
    W.tab[0] = a;
    W.tab[1] = b;
    W.tab[2] = c; 
    return W;
}

int Iwektor3D::operator*(const Iwektor3D& w){
    int wynik;
    wynik = this->tab[0] * w.tab[0] + this->tab[1] * w.tab[1] + this->tab[2] * w.tab[2];
    return wynik;
}

Iwektor3D Iwektor3D::operator-(){
    Iwektor3D W;
    for(int i = 0; i < 3; i++)
        W.tab[i] = this->tab[i] * (-1);
    return W;
}

Iwektor3D Iwektor3D::operator*(int val){
    Iwektor3D W;
    for(int i = 0; i < 3; i++){
        W.tab[i] = this->tab[i]*val;
    }
    return W;
}


int main (void){
    Iwektor3D v1(2,2,2);
    v1.print_wektor();
    Iwektor3D v2(1,1,1);
    v2.print_wektor();
    Iwektor3D v3 = v1 + v2;
    v3.print_wektor();
    Iwektor3D v4 = v1 - v2;
    v4.print_wektor();
    Iwektor3D v5 = v1*2; 
    v5.print_wektor();
    //Iwektor3D v6 = 2*v1;
    int w = v1*v2;
    cout << w << endl;
    Iwektor3D v8 = -v2;
    v8.print_wektor();
    return 0;
}

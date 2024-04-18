/**
 * @file lab1.cpp
 * @brief klasa wektora Iwektor3D typu int o rozmiarze 3 wraz z odpowiednimi metodami
 */

#include <iostream>

using namespace std;

/**
 * @class Iwektor3D
 * @brief klasa reprezentuje wektor trojwymiarowy
 */
class Iwektor3D {
    int *tab; /**< wskaznik na tablice przechowujaca wspolrzedne wektora */
public:
    /**
     * @brief konstruktor domsylny
     */
    Iwektor3D();

    /**
     * @brief konstruktor tworzacy wektor
     * @param a - pierwsza wspolrzedna
     * @param b - druga wspolrzedna
     * @param c - trzecia wspolrzedna
     */
    Iwektor3D(int a, int b, int c);

    /**
     * @brief destruktor
     */
    ~Iwektor3D();

    /**
     * @brief operator dodawania
     */
    Iwektor3D operator+(const Iwektor3D& w);

    /**
     * @brief operator odejmowania
     */
    Iwektor3D operator-(const Iwektor3D& w);

    /**
     * @brief operator mnozenia
     */
    Iwektor3D operator*(int v)const;

    /**
     * @brief funkcja mnozaca operator razy liczbe typu int
     */
    friend Iwektor3D operator*(int v, const Iwektor3D& w);

    /**
     * @brief operator do mnozenia skalarnego dwoch wektorow 
     */
    int operator*(const Iwektor3D& w);

    /**
     * @brief operator umozliwiajacy wypisywanie danych do strumienia wyjscia 
     */
    friend ostream& operator<<(ostream& os, const Iwektor3D& w);

    /**
     * @brief operator sluzacy do zmieniania wektora na przeciwny
     */
    Iwektor3D operator-();

    /**
     * @brief konstruktor kopiujacy
     */
    Iwektor3D(const Iwektor3D& w);

    /**
     * @brief operator przypisania
     */
    Iwektor3D& operator=(const Iwektor3D& w);

    /**
     * @brief operator indeksowania do pobierania wartosci
     */
    const int& operator[](int index)const;

    /**
     * @brief operator indeksowania do ustawiania wartosci
     */
    int& operator[](int index);
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

int Iwektor3D::operator*(const Iwektor3D& w){
    int a = (this->tab[0] * w.tab[0]) + (this->tab[1] * w.tab[1]) + (this->tab[1] * w.tab[1]);
    return a;
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

#pragma once
#include <string>
#include <iostream>

class Series {
        std::string name;
        int size;
        double *tab;
    public:
        Series(std::string name, int size);
        Series(const Series& s);
        Series& operator=(const Series& S);
        double& operator[](int value);
        ~Series();
};

Series::Series(std::string name, int size) : name(name), size(size) {
    tab = new double[2];
}

inline Series::Series(const Series &s)
{
    this->name = s.name;
    this->size = s.size;
    for(int i = 0; i < size; i++){
        tab[i] = s.tab[i];
    }
}

Series& Series::operator=(const Series& S){
    if(this != &S){
        delete[] tab;
        this->name = S.name;
        this->size = S.size;
        tab = new double[size];
        for(int i = 0; i < size; i++){
            tab[i] = S.tab[i];
        }
    }
    return *this;
}

inline double& Series::operator[](int index)
{
    if (index < 0 || index >= size) {
        std::cerr << "Indeks poza zakresem" << std::endl;
        exit(1); 
    }
    return tab[index];
}

Series::~Series(){
    delete[] tab;
}

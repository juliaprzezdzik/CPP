#include "Monitor.h"
#include <iostream>
#include <thread>

//Każdy element macierzy wynikowej jest obliczany w oddzielnym wątku, którego zhaszowany identyfikator jest wypisywany na ekran,
// tak jak to pokazano na wydruku poniżej.
//
//Wskazówka:
//Do zhaszowania identyfikatora wątku użyj poniższych instrukcji:
//std::hash<std::thread::id> hasher;
//long id =hasher(std::this_thread::get_id());


Base::Base(std::string name) : name(name) {}

void Base::make(std::string name) {}

void Base::remove() {}

void Base::edit() {}

Base::~Base() {}

Folder::Folder() {}
        
void Folder::make(std::string name) {
    W.push_back(name);
    std::hash<std::thread::id> hasher;
    long id =hasher(std::this_thread::get_id());
    std::cout << "dodawanie elementu do struktury w watku " << id << std::endl;
}
        
void Folder::remove() {
    W.pop_back();
}
        
void Folder::edit() {}
        
Folder::~Folder() {}

Subfolder::Subfolder() {}

void Subfolder::make(std::string name){}

void Subfolder::remove(){}
        
void Subfolder::edit(){}
       
Subfolder::~Subfolder(){}

File::File(){}
        
void File::make(std::string name){}
        
void File::remove(){}
        
void File::edit(){}
        
File::~File(){}



/***notatki do projektu**
 * addmonitor path i reszta - wpisz funkcje do zarzadzania monitorowaniem w terminalu, wtedy wykona sie okreslona funkcja (?)
 * asynchronicznie = rownoczesne wypisywanie wszystkich/wiekszosci watkow (?)
 * 
 * **/

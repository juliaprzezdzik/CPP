/**
 * @file Mebel.h
 * @brief Definicja klasy Mebel oraz dziedziczących z niej klas.
 */

#ifndef MEBEL_H
#define MEBEL_H

#include <iostream>

/**
 * @brief Klasa bazowa reprezentująca mebel.
 */
class Mebel {
public:
    /**
     * @brief Konstruktor klasy Mebel.
     * @param szerokość Szerokość mebla.
     * @param wysokość Wysokość mebla.
     * @param długość Długość mebla.
     */
    Mebel(int szerokość, int wysokość, int długość) 
        : szerokość(szerokość), wysokość(wysokość), długość(długość) {}

    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~Mebel() = default;

    /**
     * @brief Wirtualna metoda wyświetlająca informacje o meblu.
     * @param os Strumień wyjściowy.
     * @param m Mebel do wyświetlenia.
     * @return Strumień wyjściowy.
     */
    friend std::ostream& operator<<(std::ostream& os, const Mebel& m);

protected:
    int szerokość; ///< Szerokość mebla.
    int wysokość; ///< Wysokość mebla.
    int długość; ///< Długość mebla.
};

#endif // MEBEL_H

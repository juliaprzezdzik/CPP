/**
 * @file Lozko.h
 * @brief Definicja klasy Lozko dziedziczącej po klasie Mebel.
 */

#ifndef LOZKO_H
#define LOZKO_H

#include "Mebel.h"

/**
 * @brief Klasa reprezentująca łóżko, dziedzicząca po klasie Mebel.
 */
class Lozko : public Mebel {
public:
    /**
     * @brief Konstruktor klasy Lozko.
     * @param szerokość Szerokość mebla.
     * @param wysokość Wysokość mebla.
     * @param długość Długość mebla.
     * @param szerokośćSpania Szerokość spania.
     */
    Lozko(int szerokość, int wysokość, int długość, int szerokośćSpania)
        : Mebel(szerokość, wysokość, długość), szerokośćSpania(szerokośćSpania) {}

    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~Lozko() = default;

    /**
     * @brief Wirtualna metoda wyświetlająca informacje o łóżku.
     * @param os Strumień wyjściowy.
     * @param l Łóżko do wyświetlenia.
     * @return Strumień wyjściowy.
     */
    friend std::ostream& operator<<(std::ostream& os, const Lozko& l);

protected:
    int szerokośćSpania; ///< Szerokość spania.
};

#endif // LOZKO_H

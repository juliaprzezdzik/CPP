/**
 * @file Sofa.h
 * @brief Definicja klasy Sofa dziedziczącej po klasie Mebel.
 */

#ifndef SOFA_H
#define SOFA_H

#include "Mebel.h"

/**
 * @brief Klasa reprezentująca sofę, dziedzicząca po klasie Mebel.
 */
class Sofa : public Mebel {
public:
    /**
     * @brief Konstruktor klasy Sofa.
     * @param szerokość Szerokość mebla.
     * @param wysokość Wysokość mebla.
     * @param długość Długość mebla.
     * @param siedzisko Wysokość siedziska.
     */
    Sofa(int szerokość, int wysokość, int długość, int siedzisko)
        : Mebel(szerokość, wysokość, długość), siedzisko(siedzisko) {}

    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~Sofa() = default;

    /**
     * @brief Wirtualna metoda wyświetlająca informacje o sofie.
     * @param os Strumień wyjściowy.
     * @param s Sofa do wyświetlenia.
     * @return Strumień wyjściowy.
     */
    friend std::ostream& operator<<(std::ostream& os, const Sofa& s);

protected:
    int siedzisko; ///< Wysokość siedziska.
};

#endif // SOFA_H

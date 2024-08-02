/**
 * @file Kanapa.h
 * @brief Definicja klasy Kanapa dziedziczącej po klasach Sofa i Lozko.
 */

#ifndef KANAPA_H
#define KANAPA_H

#include "Sofa.h"
#include "Lozko.h"

/**
 * @brief Klasa reprezentująca kanapę, dziedziczącą po klasach Sofa i Lozko.
 */
class Kanapa : public Sofa, public Lozko {
public:
    /**
     * @brief Konstruktor klasy Kanapa.
     * @param szerokość Szerokość mebla.
     * @param wysokość Wysokość mebla.
     * @param długość Długość mebla.
     * @param siedzisko Wysokość siedziska.
     * @param szerokośćSpania Szerokość spania.
     */
    Kanapa(int szerokość, int wysokość, int długość, int siedzisko, int szerokośćSpania)
        : Mebel(szerokość, wysokość, długość), Sofa(szerokość, wysokość, długość, siedzisko), Lozko(szerokość, wysokość, długość, szerokośćSpania) {}

    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~Kanapa() = default;

    /**
     * @brief Wirtualna metoda wyświetlająca informacje o kanapie.
     * @param os Strumień wyjściowy.
     * @param k Kanapa do wyświetlenia.
     * @return Strumień wyjściowy.
     */
    friend std::ostream& operator<<(std::ostream& os, const Kanapa& k);

protected:
    using Sofa::siedzisko;
    using Lozko::szerokośćSpania;
};

#endif // KANAPA_H

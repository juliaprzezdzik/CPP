#include "Mebel.h"

/**
 * @brief Implementacja operatora << dla klasy Mebel.
 * @param os Strumień wyjściowy.
 * @param m Mebel do wyświetlenia.
 * @return Strumień wyjściowy.
 */
std::ostream& operator<<(std::ostream& os, const Mebel& m) {
    os << "Mebel: sz:" << m.szerokość 
       << " wys:" << m.wysokość 
       << " dl:" << m.długość;
    return os;
}

#include "Lozko.h"

/**
 * @brief Implementacja operatora << dla klasy Lozko.
 * @param os Strumień wyjściowy.
 * @param l Łóżko do wyświetlenia.
 * @return Strumień wyjściowy.
 */
std::ostream& operator<<(std::ostream& os, const Lozko& l) {
    os << "Lozko: " << static_cast<const Mebel&>(l) 
       << " sz.spania: " << l.szerokośćSpania;
    return os;
}

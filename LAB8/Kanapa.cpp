#include "Kanapa.h"

/**
 * @brief Implementacja operatora << dla klasy Kanapa.
 * @param os Strumień wyjściowy.
 * @param k Kanapa do wyświetlenia.
 * @return Strumień wyjściowy.
 */
std::ostream& operator<<(std::ostream& os, const Kanapa& k) {
    os << "Kanapa: jako Mebel: " << static_cast<const Mebel&>(k) 
       << " jako Sofa: " << static_cast<const Sofa&>(k) 
       << " jako Lozko: " << static_cast<const Lozko&>(k);
    return os;
}

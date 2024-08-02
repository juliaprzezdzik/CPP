#include "Sofa.h"

/**
 * @brief Implementacja operatora << dla klasy Sofa.
 * @param os Strumień wyjściowy.
 * @param s Sofa do wyświetlenia.
 * @return Strumień wyjściowy.
 */
std::ostream& operator<<(std::ostream& os, const Sofa& s) {
    os << "Sofa: " << static_cast<const Mebel&>(s) 
       << " siedzisko: " << s.siedzisko;
    return os;
}

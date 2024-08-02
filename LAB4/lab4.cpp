#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

/**
 * @class Stack
 * @brief Klasa reprezentująca stos.
 *
 * Klasa implementuje stos, który może być inicjalizowany za pomocą
 * zmiennej liczby parametrów, listy lub innego stosu. Udostępnia
 * metody do dodawania elementów oraz wypisywania zawartości stosu.
 */
class Stack {
private:
    std::vector<int> stack; ///< Wektor przechowujący elementy stosu.

public:
    /**
     * @brief Konstruktor klasy Stack.
     *
     * Inicjalizuje stos z przekazanymi parametrami. Może przyjmować
     * liczby całkowite, listę lub inny stos.
     *
     * @param args Elementy stosu. Mogą być liczbami całkowitymi, listą
     *             lub innym obiektem klasy Stack.
     */
    Stack(std::initializer_list<int> args) {
        for (int el : args) {
            stack.push_back(el);
        }
    }

    Stack(const Stack& other) : stack(other.stack) {}

    /**
     * @brief Dodaje element do stosu.
     *
     * @param element Element do dodania (liczba całkowita).
     */
    void push(int element) {
        stack.push_back(element);
    }

    /**
     * @brief Wypisuje zawartość stosu.
     */
    void print() const {
        for (int el : stack) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
};

/**
 * @class SortedStack
 * @brief Klasa reprezentująca posortowany stos.
 *
 * Klasa dziedziczy po klasie Stack i zapewnia, że elementy stosu
 * są zawsze posortowane. Umożliwia dodawanie elementów w taki sposób,
 * aby zachować porządek sortowania.
 */
class SortedStack : public Stack {
public:
    /**
     * @brief Konstruktor klasy SortedStack.
     *
     * Inicjalizuje posortowany stos z przekazanymi parametrami.
     *
     * @param args Elementy stosu. Mogą być liczbami całkowitymi, listą
     *             lub innym obiektem klasy Stack.
     */
    SortedStack(std::initializer_list<int> args) : Stack(args) {
        std::sort(stack.begin(), stack.end());
    }

    /**
     * @brief Dodaje element do posortowanego stosu.
     *
     * Element jest dodawany w taki sposób, aby zachować porządek
     * sortowania.
     *
     * @param element Element do dodania (liczba całkowita).
     */
    void push(int element) {
        Stack::push(element);
        std::sort(stack.begin(), stack.end());
    }
};

/**
 * @brief Oblicza średni rozmiar posortowanego stosu.
 *
 * Wypełnia stos liczbami całkowitymi losowymi z przedziału [0,100]
 * i oblicza średnią długość posortowanego stosu po 100 powtórzeniach.
 *
 * @return Średni rozmiar posortowanego stosu.
 */
double calculate_average_sorted_stack_size() {
    const int num_tests = 100;
    const int num_values = 100;
    const int range_max = 100;
    double total_size = 0;

    for (int i = 0; i < num_tests; ++i) {
        SortedStack s;
        for (int j = 0; j < num_values; ++j) {
            s.push(rand() % (range_max + 1));
        }
        total_size += s.size(); // Wymaga dodania metody size() w SortedStack
    }

    return total_size / num_tests;
}

/**
 * @brief Funkcja główna.
 *
 * Testuje działanie klas Stack i SortedStack oraz oblicza
 * średni rozmiar posortowanego stosu.
 *
 * @return Kod zakończenia programu.
 */
int main() {
    srand(time(0)); // Inicjalizacja generatora liczb losowych

    Stack s1 = {1, 2, 3};
    Stack s2 = {4, 5, 6};
    Stack s3 = s1;

    s1.push(7);
    s2.push(8);
    s3.push(9);

    std::cout << "Stos s1: ";
    s1.print();
    std::cout << "Stos s2: ";
    s2.print();
    std::cout << "Stos s3: ";
    s3.print();

    double avg_size = calculate_average_sorted_stack_size();
    std::cout << "Średni rozmiar posortowanego stosu: " << avg_size << std::endl;

    return 0;
}


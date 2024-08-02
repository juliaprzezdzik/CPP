/**
 * @file Logical.h
 * @brief Definicja klas do operacji logicznych.
 */

#ifndef LOGICAL_H
#define LOGICAL_H

#include <iostream>

/**
 * @brief Klasa bazowa dla operacji logicznych z dwoma argumentami.
 */
class TwoArg {
public:
    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~TwoArg() = default;

    /**
     * @brief Wirtualna metoda do obliczania wyniku operacji logicznej z dwoma argumentami.
     * @param a Pierwszy argument.
     * @param b Drugi argument.
     * @return Wynik operacji logicznej.
     */
    virtual bool result(bool a, bool b) const = 0;
};

/**
 * @brief Klasa bazowa dla operacji logicznych z jednym argumentem.
 */
class OneArg {
public:
    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~OneArg() = default;

    /**
     * @brief Wirtualna metoda do obliczania wyniku operacji logicznej z jednym argumentem.
     * @param a Argument.
     * @return Wynik operacji logicznej.
     */
    virtual bool result(bool a) const = 0;
};

/**
 * @brief Klasa pomocnicza do oceny operacji logicznych.
 */
class Logical {
public:
    /**
     * @brief Metoda statyczna do obliczania wyniku operacji logicznej z dwoma argumentami.
     * @param op Obiekt operacji logicznej.
     * @param a Pierwszy argument.
     * @param b Drugi argument.
     * @return Wynik operacji logicznej.
     */
    static bool eval(const TwoArg& op, bool a, bool b) {
        return op.result(a, b);
    }

    /**
     * @brief Metoda statyczna do obliczania wyniku operacji logicznej z jednym argumentem.
     * @param op Obiekt operacji logicznej.
     * @param a Argument.
     * @return Wynik operacji logicznej.
     */
    static bool eval(const OneArg& op, bool a) {
        return op.result(a);
    }
};

/**
 * @brief Klasa implementująca operację logiczną OR.
 */
class OR : public TwoArg {
public:
    /**
     * @brief Oblicza wynik operacji logicznej OR dla dwóch argumentów.
     * @param a Pierwszy argument.
     * @param b Drugi argument.
     * @return Wynik operacji logicznej OR.
     */
    bool result(bool a, bool b) const override {
        return a || b;
    }
};

/**
 * @brief Klasa implementująca operację logiczną AND.
 */
class AND : public TwoArg {
public:
    /**
     * @brief Oblicza wynik operacji logicznej AND dla dwóch argumentów.
     * @param a Pierwszy argument.
     * @param b Drugi argument.
     * @return Wynik operacji logicznej AND.
     */
    bool result(bool a, bool b) const override {
        return a && b;
    }
};

/**
 * @brief Klasa implementująca operację logiczną XOR.
 */
class XOR : public TwoArg {
public:
    /**
     * @brief Oblicza wynik operacji logicznej XOR dla dwóch argumentów.
     * @param a Pierwszy argument.
     * @param b Drugi argument.
     * @return Wynik operacji logicznej XOR.
     */
    bool result(bool a, bool b) const override {
        return a != b;
    }
};

/**
 * @brief Klasa implementująca operację logiczną NOT.
 */
class NOT : public OneArg {
public:
    /**
     * @brief Oblicza wynik operacji logicznej NOT dla jednego argumentu.
     * @param a Argument.
     * @return Wynik operacji logicznej NOT.
     */
    bool result(bool a) const override {
        return !a;
    }
};

#endif // LOGICAL_H

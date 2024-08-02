#include<iostream>
#include "Logical.h"



/// @brief funkcja do otrzymywania rezultatu operacji logicznej
/// @param op referencja do obiektu klasy TwoArg
/// @param b1 zmienna typu bool
/// @param b2 zmienna typu bool
/// @return wynik operacji logicznej
bool Logical::eval(const TwoArg& op, bool b1, bool b2){
    return op.result(b1, b2);
 }

 /// @brief druga implementacja funkcji eval
 /// @param op referencja do obiektu klasy TwoArg
 /// @param b1 zmienna typu bool
 /// @return wynik operacji
 bool Logical::eval(const TwoArg& op, bool b1){
    return op.result(b1, true);
 }

 /// @brief do przeprowadzania operacji logicznej "or"
 /// @param op1 zmienna typu bool
 /// @param op2 zmienna typu bool
 /// @return wynik operacji logicznej or
 bool OR::result(bool op1, bool op2)const{
    return (op1 || op2);
 }

 /// @brief do przeprowadzania operacji logicznej "and"
 /// @param op1 zmienna typu bool
 /// @param op2 zmienna typu bool
 /// @return wynik operacji logicznej and
 bool AND::result(bool op1, bool op2)const {
    return(op1 && op2);
 }

 /// @brief do przeprowadzania operacji logicznej "xor"
 /// @param op1 zmienna typu bool
 /// @param op2 zmienna typu bool
 /// @return wynik operacji logicznej xor
 bool XOR::result(bool op1, bool op2)const {
    return(op1 != op2);
 } 

  /// @brief do przeprowadzania operacji logicznej "not"
  /// @param op1 zmienna typu bool
  /// @param op2 zmienna typu bool
  /// @return wynik operacji logicznej not
  bool NOT::result(bool op1, bool op2 = true)const {
    return(-op1);
 } 

 

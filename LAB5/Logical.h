#pragma once

///@brief Klasa reprezentujaca operacje dwuargumentowe
class TwoArg{
    public:
        virtual bool result(bool op1, bool op2)const = 0;
};

/// @brief klasa reprezentujaca operacje logiczne 
class Logical{
    public:
        static bool eval(const TwoArg& op, bool b1, bool b2);
        static bool eval(const TwoArg& op, bool b1);

};

/// @brief klasa OR dziedzicaca publicznie po TwoArg
class OR: public TwoArg{
    public:
        bool result(bool op1, bool op2)const override;
};

/// @brief klasa AND dziedzicaca publicznie po TwoArg
class AND: public TwoArg{
    public:
        bool result(bool op1, bool op2)const override;
};

/// @brief klasa XOR dziedzicaca publicznie po TwoArg
class XOR: public TwoArg{
    public:
        bool result(bool op1, bool op2)const override;
};

/// @brief klasa NOT dziedzicaca publicznie po TwoArg
class NOT: public TwoArg{
    public:
        bool result(bool op1, bool op2)const override;
};

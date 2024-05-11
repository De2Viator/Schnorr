#ifndef SCHNORR_MATHOPERATIONS_H
#define SCHNORR_MATHOPERATIONS_H
#include "iostream"
typedef long long number;
class MathOperations {
public:
    static number generateRandomNumber(number from, number to);
    static number makePower(number base, number exponent);
    static number makePowerMod(number a, number n, number m);
};


#endif

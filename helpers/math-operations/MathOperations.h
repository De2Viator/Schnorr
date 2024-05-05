//
// Created by Yurij on 02.05.2024.
//

#ifndef SCHNORR_MATHOPERATIONS_H
#define SCHNORR_MATHOPERATIONS_H
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>
typedef boost::multiprecision::cpp_int number;
class MathOperations {
public:
    static number generateRandomNumber(number from, number to);
    static number makePower(number base, number exponent);
    static number makePowerMod(number a, number n, number m);
};


#endif //SCHNORR_MATHOPERATIONS_H

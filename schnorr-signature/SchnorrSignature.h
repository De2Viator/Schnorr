#ifndef SCHNORR_SCHNORRSIGNATURE_H
#define SCHNORR_SCHNORRSIGNATURE_H
#include "../helpers/math-operations/MathOperations.h"

class SchnorrSignature {
    number generateQ();
    number generateP(number l, number q);
    number generateL();
    number generateG(number l,number p);
    number generateX(number q);
    number generateY(number g, number x, number p);
    number generateK(number q);
    number generateR(number k, number g, number p);
    number generateE(std::string M, number r);
    size_t generateH(std::string M);
    number generateS(number k, number e, number q);
    number generateRy(number g, number y, number s, number e, number p);
public:
    void generateKeys();
    void signMessage();
    void verifyMessage();
};

#endif

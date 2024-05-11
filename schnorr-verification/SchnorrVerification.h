#ifndef SCHNORR_VERIFICATION_H
    #define SCHNORR_VERIFICATION_H
    #include "../helpers/math-operations/MathOperations.h"
    #define t 8
    class SchnorrVerification {
    private:
        number generateP();
        number generateQ();
        number generateG(number q, number p);
        number generateW(number q);
        number generateY(number g, number q, number w, number p);
        number generateR(number q);
        number generateX(number g, number r, number p);
        number generateE();
        number generateS(number r, number e, number q);
        number generateZ(number g, number s, number y, number e, number p);
    public:
        SchnorrVerification() {}
        void generateKeys();
        void check();
    };
#endif

#include <iostream>
#include "SchnorrVerification.h"

number SchnorrVerification::generateP() {
    return 48731;
}

number SchnorrVerification::generateQ() {
    return 443;
}

number SchnorrVerification::generateG(number q, number p) {
    number g = 2;
    while ((MathOperations::makePowerMod(g, q, p) != 1)) ++g;
    return g;
}

number SchnorrVerification::generateW(number q) {
    number w = InputHelper::getValidatedInteger();
    if (q < w) {
        std::cerr << "Your w is bigger than q" << std::endl;
    }
    return w;
}

number SchnorrVerification::generateY(number g, number q, number w, number p) {
    return MathOperations::makePowerMod(g, q - w, p);
}

number SchnorrVerification::generateR(number q) {
    return MathOperations::generateRandomNumber(1, q - 1);
}

number SchnorrVerification::generateX(number g, number r, number p) {
    return MathOperations::makePowerMod(g, r, p);
}

number SchnorrVerification::generateE() {
    return MathOperations::generateRandomNumber(0, MathOperations::makePower(2, t) - 1);
}

number SchnorrVerification::generateS(number r, number e, number q) {
    std::cout<<"Enter W:";
    number w = InputHelper::getValidatedInteger();
    return (r + w * e) % q;
}

number SchnorrVerification::generateZ(number g, number s, number y, number e, number p) {
    return (MathOperations::makePowerMod(g, s, p) * MathOperations::makePowerMod(y, e, p)) % p;
}

void SchnorrVerification::generateKeys() {
    number p = generateP();
    number q = generateQ();
    number g = generateG(q, p);
    std::cout << "Q:" << q << std::endl;
    std::cout << "Private key:";
    number w = generateW(q);
    number y = generateY(g, q, w, p);
    std::cout << "W:" << w << std::endl;
    std::cout << "Open key:" << std::endl;
    std::cout << "P:" << p << std::endl;
    std::cout << "Q:" << q << std::endl;
    std::cout << "G:" << g << std::endl;
    std::cout << "Y:" << y << std::endl;
}

void SchnorrVerification::check() {
    std::cout<<"Enter P:";
    number p = InputHelper::getValidatedInteger();
    std::cout<<"Enter Q:";
    number q = InputHelper::getValidatedInteger();
    std::cout<<"Enter G:";
    number g = InputHelper::getValidatedInteger();
    std::cout<<"Enter Y:";
    number y = InputHelper::getValidatedInteger();

    number r = generateR(q);
    number x = generateX(g, r, p);
    number e = generateE();
    number s = generateS(r, e, q);
    number z = generateZ(g, s, y, e, p);
    if (x == z) {
        std::cout << "Verification is correct" << std::endl;
    } else {
        std::cerr << "Verification is incorrect" << std::endl;
    }
}

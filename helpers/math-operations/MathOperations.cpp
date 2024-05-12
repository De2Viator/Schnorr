#include "MathOperations.h"
number MathOperations::generateRandomNumber(number from, number to) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<number> dist(from, to);
    return dist(gen);
}

number MathOperations::makePower(number base, number exponent) {
    number result = base;
    number expCounter = 1;
    while (expCounter < exponent) {
        result *= base;
        expCounter++;
    }
    return result;
}

number MathOperations::makePowerMod(number a, number n, number m) {
    number c = 1;
    number n_prime = 0;

    while (n_prime < n) {
        n_prime++;
        c = (c * a) % m;
    }
    return c;
}

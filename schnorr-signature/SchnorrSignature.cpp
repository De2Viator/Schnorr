#include "SchnorrSignature.h"
number SchnorrSignature::generateQ() {
    return 103;
}
number SchnorrSignature::generateP(number l, number q) {
    return l*q+1;
}
number SchnorrSignature::generateL() {
    return 22;
}
number SchnorrSignature::generateG(number l,number p) {
    number f = 2;
    number g = MathOperations::makePowerMod(f,l,p);
    return g;
}
number SchnorrSignature::generateX(number q) {
    return MathOperations::generateRandomNumber(1,q-1);
}
number SchnorrSignature::generateY(number g, number x, number p) {
    return MathOperations::makePowerMod(g,x,p);
}
number SchnorrSignature::generateK(number q) {
    return MathOperations::generateRandomNumber(1,q-1);
}
number SchnorrSignature::generateR(number k, number g, number p) {
    return MathOperations::makePowerMod(g,k,p);
}
number SchnorrSignature::generateE(std::string M, number r) {
    std::string hashStr = std::to_string(generateH(M + std::to_string(r)));
    std::string firstThreeChars = hashStr.substr(0, 3);
    return std::stoull(firstThreeChars);
}
size_t SchnorrSignature::generateH(std::string M) {
    std::hash<std::string> H;
    size_t hashValue = H(M);
    return hashValue;
}
number SchnorrSignature::generateS(number k, number e, number q) {
    number x = 0;
    std::cout<<"X:";
    std::cin>>x;
    number s = (k-x*e)%q;
    if(s < 0) s+=q;
    return s;
}
number SchnorrSignature::generateRy(number g, number y, number s, number e, number p) {
    return (MathOperations::makePowerMod(g,s,p)  * MathOperations::makePowerMod(y,e,p)) % p;
}
void SchnorrSignature::generateKeys() {
    number l = generateL();
    number q = generateQ();
    number p = generateP(l,q);
    number g = generateG(l,p);
    number x = generateX(q);
    number y = generateY(g,x,p);
    std::cout<<"P:"<<p<<std::endl;
    std::cout<<"Q:"<<q<<std::endl;
    std::cout<<"G:"<<g<<std::endl;
    std::cout<<"X:"<<x<<std::endl;
    std::cout<<"Y:"<<y<<std::endl;
}
void SchnorrSignature::signMessage() {
    std::cout<<"Signing"<<std::endl;
    number q = 0;
    number p = 0;
    number g = 0;
    std::cout<<"P:";
    std::cin>>p;
    std::cout<<"Q:";
    std::cin>>q;
    std::cout<<"G:";
    std::cin>>g;
    number k = generateK(q);
    number r = generateR(k,g,p);
    std::string M;
    std::cout<<"Enter your message:";
    std::cin>>M;
    number e = generateE(M,r);
    std::cout<<"E:"<<e<<std::endl;
    number s = generateS(k,e,q);
    std::cout<<"S:"<<s<<std::endl;
}
void SchnorrSignature::verifyMessage() {
    std::cout<<"Verify:"<<std::endl;
    number g = 0;
    number s = 0;
    number y = 0;
    number e = 0;
    number p = 0;
    std::cout<<"G:";
    std::cin>>g;
    std::cout<<"S:";
    std::cin>>s;
    std::cout<<"Y:";
    std::cin>>y;
    std::cout<<"E:";
    std::cin>>e;
    std::cout<<"P:";
    std::cin>>p;
    std::string M;
    std::cout<<"Enter your message:";
    std::cin>>M;
    number Ry = generateRy(g,y,s,e,p);
    number Ey = generateE(M,Ry);
    if(Ey == e) {
        std::cout<<"Signature is valid"<<std::endl;
    } else {
        std::cout<<"Signature isn't valid"<<std::endl;
    }
}

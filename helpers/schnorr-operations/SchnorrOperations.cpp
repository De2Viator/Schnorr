//
// Created by Yurij on 05.05.2024.
//

#include "SchnorrOperations.h"
void SchnorrOperations::showOperations() {
    char operations[OPERATIONS_AMOUNT][MAX_NAME_LENGTH] = {
            "Generate key for Schnorr verification",
            "Verificate Schnorr verification",
            "Generate Schnorr signature key",
            "Sign message",
            "Verify Schnorr signature"
    };
    for (unsigned short i = 1; i <= OPERATIONS_AMOUNT; i++) {
        std::cout<<i<<". "<<operations[i-1]<<std::endl;
    }
    unsigned i = 0;
    std::cout<<"Enter action number: ";
    std::cin>>i;
    Actions action = static_cast<Actions>(i);
    doAction(action);
}
void SchnorrOperations::doAction(Actions action) {
    SchnorrVerification schnorrVerification;
    SchnorrSignature schnorrSignature;
    switch (action) {
        case GENERATE_KEYS_FOR_VERIFICATION: {
            schnorrVerification.generateKeys();
            break;
        }
        case VERIFICATION: {
            schnorrVerification.check();
            break;
        }
        case GENERATE_SCHNORR_SIGNATURE_KEYS: {
            schnorrSignature.generateKeys();
            break;
        }
        case SIGNING: {
            schnorrSignature.signMessage();
            break;
        }
        case VERIFYING_SCHNORR_SIGNATURE: {
            schnorrSignature.verifyMessage();
            break;
        }
    }
}

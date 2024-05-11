#ifndef SCHNORR_SCHNORROPERATIONS_H
#define SCHNORR_SCHNORROPERATIONS_H
#define OPERATIONS_AMOUNT 5
#define MAX_NAME_LENGTH 50
#include "iostream"
#include "../../schnorr-verification/SchnorrVerification.h"
#include "../../schnorr-signature/SchnorrSignature.h"
enum Actions {GENERATE_KEYS_FOR_VERIFICATION = 1,
              VERIFICATION = 2,
              GENERATE_SCHNORR_SIGNATURE_KEYS = 3,
              SIGNING = 4,
              VERIFYING_SCHNORR_SIGNATURE = 5};
class SchnorrOperations {
    static void doAction(Actions action);
public:
    static void showOperations();
};


#endif

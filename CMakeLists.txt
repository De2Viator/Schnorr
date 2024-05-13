cmake_minimum_required(VERSION 3.5)
project(schnorr)

add_executable(schnorr main.cpp
        schnorr-verification/SchnorrVerification.cpp
        schnorr-verification/SchnorrVerification.h
        helpers/math-operations/MathOperations.cpp
        helpers/math-operations/MathOperations.h
        schnorr-signature/SchnorrSignature.cpp
        schnorr-signature/SchnorrSignature.h
        helpers/schnorr-operations/SchnorrOperations.cpp
        helpers/schnorr-operations/SchnorrOperations.h
        helpers/input-operations/InputOperations.cpp
        helpers/input-operations/InputOperations.h)

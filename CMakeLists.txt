cmake_minimum_required(VERSION 3.5)
project(schnorr)

set(BOOST_ROOT "D:/Boost")
find_package(Boost REQUIRED)

add_executable(schnorr main.cpp
        schnorr-verification/SchnorrVerification.cpp
        schnorr-verification/SchnorrVerification.h
        helpers/math-operations/MathOperations.cpp
        helpers/math-operations/MathOperations.h
        schnorr-signature/SchnorrSignature.cpp
        schnorr-signature/SchnorrSignature.h
        helpers/schnorr-operations/SchnorrOperations.cpp
        helpers/schnorr-operations/SchnorrOperations.h)

target_link_libraries(schnorr Boost::boost)

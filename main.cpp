/*
    Copyright 2023 Patricia Antlitz
*/
#include <iostream>
#include <bitset>
#include "FibLFSR.hpp"
// #include "FibLFSR.cpp"

int main(int argc, char const *argv[]) {
    // given seed
    std::string seed = "1011011000110110";
    FibLFSR flfsr(seed);
    // initial bit set to 0, this will ensure the desired output
    int bit = 0;

    std::cout << "step():" << std::endl;
    // 10 loops of step()
    for (int i = 0; i < 10; i++) {
        bit = flfsr.step();
        std::cout << flfsr << " " << bit << std::endl;
    }

    // reset the seed to run generate()
    flfsr = FibLFSR(seed);
    std::cout << std::endl << "generate():" << std::endl;

    for (int i = 0; i < 7; ++i) {
        std::cout << flfsr << " " << flfsr.generate(5) << std::endl;
    }

    return 0;
}

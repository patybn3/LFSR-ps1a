// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// test.cpp for PS1a
// updated 5/12/2022

#include <iostream>
#include <string>
#include "FibLFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testStepInstr1) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

BOOST_AUTO_TEST_CASE(testEdgeCasesStep) {
  FibLFSR seedOnes("11111111");
  FibLFSR seedZeros("00000000");
  FibLFSR seedAlt("01010101");

  BOOST_REQUIRE_EQUAL(seedOnes.step(), 0);
  BOOST_REQUIRE_EQUAL(seedOnes.step(), 0);
  BOOST_REQUIRE_EQUAL(seedOnes.step(), 0);
  BOOST_REQUIRE_EQUAL(seedOnes.step(), 1);
  BOOST_REQUIRE_EQUAL(seedOnes.step(), 1);
  BOOST_REQUIRE_EQUAL(seedOnes.step(), 0);

  BOOST_REQUIRE_EQUAL(seedZeros.step(), 0);
  BOOST_REQUIRE_EQUAL(seedZeros.step(), 0);
  BOOST_REQUIRE_EQUAL(seedZeros.step(), 0);
  BOOST_REQUIRE_EQUAL(seedZeros.step(), 0);
  BOOST_REQUIRE_EQUAL(seedZeros.step(), 0);
  BOOST_REQUIRE_EQUAL(seedZeros.step(), 0);

  BOOST_REQUIRE_EQUAL(seedAlt.step(), 0);
  BOOST_REQUIRE_EQUAL(seedAlt.step(), 0);
  BOOST_REQUIRE_EQUAL(seedAlt.step(), 0);
  BOOST_REQUIRE_EQUAL(seedAlt.step(), 0);
  BOOST_REQUIRE_EQUAL(seedAlt.step(), 1);
  BOOST_REQUIRE_EQUAL(seedAlt.step(), 0);
}

BOOST_AUTO_TEST_CASE(testStepInstr2) {
  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE_EQUAL(l2.generate(9), 51);
}

BOOST_AUTO_TEST_CASE(stressTest) {
  // stress test, does the code work if a lot of bits
  // is generated?
  FibLFSR stressTest("1011011000110110");
  BOOST_CHECK_NO_THROW(stressTest.generate(1000));
}

BOOST_AUTO_TEST_CASE(testPerformance) {
  // generate a large number of bits
  std::string seed = "1011011000110110";
  FibLFSR flfsr(seed);
  // and measure execution time using the clock
  clock_t start = clock();
  // 1 million bits
  int r = flfsr.generate(1000000);
  clock_t end = clock();

  double elapse = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  std::cout << elapse << std::endl;
  BOOST_CHECK(r != 0);
}

BOOST_AUTO_TEST_CASE(testErrorHandling) {
  // strings that are not binary numbers
  BOOST_CHECK_THROW(FibLFSR empty(""), std::invalid_argument);
  BOOST_CHECK_THROW(FibLFSR invalid("AABBCCDDEEFFGGHH"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testConsistency) {
  // ensure program produces consistent outputs
  std::string seed = "1011011000110110";
  std::string seqOne;
  std::string seqTwo;

  FibLFSR flfsr(seed);

  // we will generate in two separate runs and reset the seed
  // midway
  for (int i = 0; i < 10; i++) {
    seqOne += std::to_string(flfsr.step());
  }

  flfsr = FibLFSR(seed);

  for (int i = 0; i < 10; i++) {
    seqTwo += std::to_string(flfsr.step());
  }

  BOOST_CHECK_EQUAL(seqOne, seqTwo);
}

#include <catch.hpp>

#include <bitter_readwrite.hpp>

namespace bitter {
    namespace test {
        SCENARIO("bits can be read from a target") {
            GIVEN("a single byte with all zeros") {
                const char byte = 0b00000000;

                WHEN("when a bit reader is created to read it") {
                    BitReader bitReader(&byte, sizeof(byte));

                    WHEN("bits 0 through 7 (inclusive) are read") {
                        THEN("it should always return Bit::Zero") {
                            REQUIRE(bitReader.getBitNumber(0) == Bit::Zero);
                            REQUIRE(bitReader.getBitNumber(1) == Bit::Zero);
                            REQUIRE(bitReader.getBitNumber(2) == Bit::Zero);
                            REQUIRE(bitReader.getBitNumber(3) == Bit::Zero);
                            REQUIRE(bitReader.getBitNumber(4) == Bit::Zero);
                            REQUIRE(bitReader.getBitNumber(5) == Bit::Zero);
                            REQUIRE(bitReader.getBitNumber(6) == Bit::Zero);
                            REQUIRE(bitReader.getBitNumber(7) == Bit::Zero);
                        } 
                    }
                }
            }

            GIVEN("a single byte with all ones") {
                const char byte = 0b11111111;

                WHEN("when a bit reader is created to read it") {
                    BitReader bitReader(&byte, sizeof(byte));

                    WHEN("bits 0 through 7 (inclusive) are read") {
                        THEN("it should always return Bit::One") {
                            REQUIRE(bitReader.getBitNumber(0) == Bit::One);
                            REQUIRE(bitReader.getBitNumber(1) == Bit::One);
                            REQUIRE(bitReader.getBitNumber(2) == Bit::One);
                            REQUIRE(bitReader.getBitNumber(3) == Bit::One);
                            REQUIRE(bitReader.getBitNumber(4) == Bit::One);
                            REQUIRE(bitReader.getBitNumber(5) == Bit::One);
                            REQUIRE(bitReader.getBitNumber(6) == Bit::One);
                            REQUIRE(bitReader.getBitNumber(7) == Bit::One);
                        }
                    }
                }
            }
        } 
    }
}


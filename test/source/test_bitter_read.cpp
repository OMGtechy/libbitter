#include <catch.hpp>

#include <cstdint>

#include <bitter_read.hpp>

namespace bitter {
    namespace test {
        SCENARIO("bits can be read from a target") {
            GIVEN("a single byte with all zeros") {
                constexpr uint8_t byte = 0b00000000;

                WHEN("bits 0 through 7 (inclusive) are read") {
                    THEN("it should always return Bit::Zero") {
                        REQUIRE(bitter::getBit(&byte, 0) == Bit::Zero);
                        REQUIRE(bitter::getBit(&byte, 1) == Bit::Zero);
                        REQUIRE(bitter::getBit(&byte, 2) == Bit::Zero);
                        REQUIRE(bitter::getBit(&byte, 3) == Bit::Zero);
                        REQUIRE(bitter::getBit(&byte, 4) == Bit::Zero);
                        REQUIRE(bitter::getBit(&byte, 5) == Bit::Zero);
                        REQUIRE(bitter::getBit(&byte, 6) == Bit::Zero);
                        REQUIRE(bitter::getBit(&byte, 7) == Bit::Zero);
                    } 
                }
            }

            GIVEN("a single byte with all ones") {
                constexpr uint8_t byte = 0b11111111;

                WHEN("bits 0 through 7 (inclusive) are read") {
                    THEN("it should always return Bit::One") {
                        REQUIRE(bitter::getBit(&byte, 0) == Bit::One);
                        REQUIRE(bitter::getBit(&byte, 1) == Bit::One);
                        REQUIRE(bitter::getBit(&byte, 2) == Bit::One);
                        REQUIRE(bitter::getBit(&byte, 3) == Bit::One);
                        REQUIRE(bitter::getBit(&byte, 4) == Bit::One);
                        REQUIRE(bitter::getBit(&byte, 5) == Bit::One);
                        REQUIRE(bitter::getBit(&byte, 6) == Bit::One);
                        REQUIRE(bitter::getBit(&byte, 7) == Bit::One);
                    }
                }
            }

            GIVEN("a single byte with a complex bit pattern") {
                constexpr uint8_t byte = 0b01100011;

                WHEN("bits 0 through 7 (inclusive) are read") {
                    THEN("the correct values should be returned") {
                        REQUIRE(bitter::getBit(&byte, 0) == Bit::One);
                        REQUIRE(bitter::getBit(&byte, 1) == Bit::One);
                        REQUIRE(bitter::getBit(&byte, 2) == Bit::Zero);
                        REQUIRE(bitter::getBit(&byte, 3) == Bit::Zero);
                        REQUIRE(bitter::getBit(&byte, 4) == Bit::Zero);
                        REQUIRE(bitter::getBit(&byte, 5) == Bit::One);
                        REQUIRE(bitter::getBit(&byte, 6) == Bit::One);
                        REQUIRE(bitter::getBit(&byte, 7) == Bit::Zero);
                    }
                }
            }

            GIVEN("multiple bytes") {
                constexpr uint8_t bytes[] = { 0b01010101, 0b10101010, 0b11110000, 0b00001111 };

                WHEN("each bit is read") {
                    THEN("the correct values should be returned") {
                        // byte 0
                        REQUIRE(bitter::getBit(&bytes, 0) == Bit::One);
                        REQUIRE(bitter::getBit(&bytes, 1) == Bit::Zero);
                        REQUIRE(bitter::getBit(&bytes, 2) == Bit::One);
                        REQUIRE(bitter::getBit(&bytes, 3) == Bit::Zero);
                        REQUIRE(bitter::getBit(&bytes, 4) == Bit::One);
                        REQUIRE(bitter::getBit(&bytes, 5) == Bit::Zero);
                        REQUIRE(bitter::getBit(&bytes, 6) == Bit::One);
                        REQUIRE(bitter::getBit(&bytes, 7) == Bit::Zero);

                        // byte 1
                        REQUIRE(bitter::getBit(&bytes, 8) == Bit::Zero);
                        REQUIRE(bitter::getBit(&bytes, 9) == Bit::One);
                        REQUIRE(bitter::getBit(&bytes, 10) == Bit::Zero);
                        REQUIRE(bitter::getBit(&bytes, 11) == Bit::One);
                        REQUIRE(bitter::getBit(&bytes, 12) == Bit::Zero);
                        REQUIRE(bitter::getBit(&bytes, 13) == Bit::One);
                        REQUIRE(bitter::getBit(&bytes, 14) == Bit::Zero);
                        REQUIRE(bitter::getBit(&bytes, 15) == Bit::One);

                        // byte 2
                        REQUIRE(bitter::getBit(&bytes, 16) == Bit::Zero);
                        REQUIRE(bitter::getBit(&bytes, 17) == Bit::Zero);
                        REQUIRE(bitter::getBit(&bytes, 18) == Bit::Zero);
                        REQUIRE(bitter::getBit(&bytes, 19) == Bit::Zero);
                        REQUIRE(bitter::getBit(&bytes, 20) == Bit::One);
                        REQUIRE(bitter::getBit(&bytes, 21) == Bit::One);
                        REQUIRE(bitter::getBit(&bytes, 22) == Bit::One);
                        REQUIRE(bitter::getBit(&bytes, 23) == Bit::One);

                        // byte 3
                        REQUIRE(bitter::getBit(&bytes, 24) == Bit::One);
                        REQUIRE(bitter::getBit(&bytes, 25) == Bit::One);
                        REQUIRE(bitter::getBit(&bytes, 26) == Bit::One);
                        REQUIRE(bitter::getBit(&bytes, 27) == Bit::One);
                        REQUIRE(bitter::getBit(&bytes, 28) == Bit::Zero);
                        REQUIRE(bitter::getBit(&bytes, 29) == Bit::Zero);
                        REQUIRE(bitter::getBit(&bytes, 30) == Bit::Zero);
                        REQUIRE(bitter::getBit(&bytes, 31) == Bit::Zero);
                    }
                }
            }
        } 
    }
}


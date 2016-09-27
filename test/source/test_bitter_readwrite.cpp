#include <catch.hpp>

#include <cstdint>

#include <bitter_readwrite.hpp>

namespace bitter {
    namespace test {
        SCENARIO("bits can be read from a target") {
            GIVEN("a single byte with all zeros") {
                constexpr uint8_t byte = 0b00000000;

                WHEN("when a bit reader is created to read it") {
                    const BitReader bitReader(&byte, sizeof(byte));

                    WHEN("bits 0 through 7 (inclusive) are read") {
                        THEN("it should always return Bit::Zero") {
                            REQUIRE(bitReader.getBit(0) == Bit::Zero);
                            REQUIRE(bitReader.getBit(1) == Bit::Zero);
                            REQUIRE(bitReader.getBit(2) == Bit::Zero);
                            REQUIRE(bitReader.getBit(3) == Bit::Zero);
                            REQUIRE(bitReader.getBit(4) == Bit::Zero);
                            REQUIRE(bitReader.getBit(5) == Bit::Zero);
                            REQUIRE(bitReader.getBit(6) == Bit::Zero);
                            REQUIRE(bitReader.getBit(7) == Bit::Zero);
                        } 
                    }
                }
            }

            GIVEN("a single byte with all ones") {
                constexpr uint8_t byte = 0b11111111;

                WHEN("when a bit reader is created to read it") {
                    const BitReader bitReader(&byte, sizeof(byte));

                    WHEN("bits 0 through 7 (inclusive) are read") {
                        THEN("it should always return Bit::One") {
                            REQUIRE(bitReader.getBit(0) == Bit::One);
                            REQUIRE(bitReader.getBit(1) == Bit::One);
                            REQUIRE(bitReader.getBit(2) == Bit::One);
                            REQUIRE(bitReader.getBit(3) == Bit::One);
                            REQUIRE(bitReader.getBit(4) == Bit::One);
                            REQUIRE(bitReader.getBit(5) == Bit::One);
                            REQUIRE(bitReader.getBit(6) == Bit::One);
                            REQUIRE(bitReader.getBit(7) == Bit::One);
                        }
                    }
                }
            }

            GIVEN("a single byte with a complex bit pattern") {
                constexpr uint8_t byte = 0b01100011;

                WHEN("a bit reader is created to read it") {
                    const BitReader bitReader(&byte, sizeof(byte));

                    WHEN("bits 0 through 7 (inclusive) are read") {
                        THEN("the correct values should be returned") {
                            REQUIRE(bitReader.getBit(0) == Bit::One);
                            REQUIRE(bitReader.getBit(1) == Bit::One);
                            REQUIRE(bitReader.getBit(2) == Bit::Zero);
                            REQUIRE(bitReader.getBit(3) == Bit::Zero);
                            REQUIRE(bitReader.getBit(4) == Bit::Zero);
                            REQUIRE(bitReader.getBit(5) == Bit::One);
                            REQUIRE(bitReader.getBit(6) == Bit::One);
                            REQUIRE(bitReader.getBit(7) == Bit::Zero);
                        }
                    }
                }
            }

            GIVEN("multiple bytes") {
                constexpr uint8_t bytes[] = { 0b01010101, 0b10101010, 0b11110000, 0b00001111 };

                WHEN("a bit reader is created to read them") {
                    const BitReader bitReader(&bytes, sizeof(bytes));

                    WHEN("each bit is read") {
                        THEN("the correct values should be returned") {
                            // byte 0
                            REQUIRE(bitReader.getBit(0) == Bit::One);
                            REQUIRE(bitReader.getBit(1) == Bit::Zero);
                            REQUIRE(bitReader.getBit(2) == Bit::One);
                            REQUIRE(bitReader.getBit(3) == Bit::Zero);
                            REQUIRE(bitReader.getBit(4) == Bit::One);
                            REQUIRE(bitReader.getBit(5) == Bit::Zero);
                            REQUIRE(bitReader.getBit(6) == Bit::One);
                            REQUIRE(bitReader.getBit(7) == Bit::Zero);

                            // byte 1
                            REQUIRE(bitReader.getBit(8) == Bit::Zero);
                            REQUIRE(bitReader.getBit(9) == Bit::One);
                            REQUIRE(bitReader.getBit(10) == Bit::Zero);
                            REQUIRE(bitReader.getBit(11) == Bit::One);
                            REQUIRE(bitReader.getBit(12) == Bit::Zero);
                            REQUIRE(bitReader.getBit(13) == Bit::One);
                            REQUIRE(bitReader.getBit(14) == Bit::Zero);
                            REQUIRE(bitReader.getBit(15) == Bit::One);

                            // byte 2
                            REQUIRE(bitReader.getBit(16) == Bit::Zero);
                            REQUIRE(bitReader.getBit(17) == Bit::Zero);
                            REQUIRE(bitReader.getBit(18) == Bit::Zero);
                            REQUIRE(bitReader.getBit(19) == Bit::Zero);
                            REQUIRE(bitReader.getBit(20) == Bit::One);
                            REQUIRE(bitReader.getBit(21) == Bit::One);
                            REQUIRE(bitReader.getBit(22) == Bit::One);
                            REQUIRE(bitReader.getBit(23) == Bit::One);

                            // byte 3
                            REQUIRE(bitReader.getBit(24) == Bit::One);
                            REQUIRE(bitReader.getBit(25) == Bit::One);
                            REQUIRE(bitReader.getBit(26) == Bit::One);
                            REQUIRE(bitReader.getBit(27) == Bit::One);
                            REQUIRE(bitReader.getBit(28) == Bit::Zero);
                            REQUIRE(bitReader.getBit(29) == Bit::Zero);
                            REQUIRE(bitReader.getBit(30) == Bit::Zero);
                            REQUIRE(bitReader.getBit(31) == Bit::Zero);
                        }
                    }
                }
            }
        } 
    }
}


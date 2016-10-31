#include <catch.hpp>

#include <cstdint>

#include <bitter_write.hpp>

namespace bitter {
    namespace test {
        SCENARIO("bits can be written to the target") {
            GIVEN("a single byte with all zeros") {
                uint8_t byte = 0b00000000;

                WHEN("bit 0 is set to 1 and the others are set to 0") {
                    bitter::setBit(&byte, 0, Bit::One);
                    bitter::setBit(&byte, 1, Bit::Zero);
                    bitter::setBit(&byte, 2, Bit::Zero);
                    bitter::setBit(&byte, 3, Bit::Zero);
                    bitter::setBit(&byte, 4, Bit::Zero);
                    bitter::setBit(&byte, 5, Bit::Zero);
                    bitter::setBit(&byte, 6, Bit::Zero);
                    bitter::setBit(&byte, 7, Bit::Zero);

                    THEN("the byte (when interpreted as a uint8_t) is equal to one") {
                        REQUIRE(byte == 1);
                    }
                }
            }

            GIVEN("a single byte with all ones") {
                uint8_t byte = 0b11111111;

                WHEN("bit 7 is set to 0 and the others are set to 1") {
                    bitter::setBit(&byte, 0, Bit::One);
                    bitter::setBit(&byte, 1, Bit::One);
                    bitter::setBit(&byte, 2, Bit::One);
                    bitter::setBit(&byte, 3, Bit::One);
                    bitter::setBit(&byte, 4, Bit::One);
                    bitter::setBit(&byte, 5, Bit::One);
                    bitter::setBit(&byte, 6, Bit::One);
                    bitter::setBit(&byte, 7, Bit::Zero);

                    THEN("the byte (when interpreted as a uint8_t) is equal to 127") {
                        REQUIRE(byte == 127);
                    }
                }
            }

            GIVEN("a single byte with a complex bit pattern") {
                uint8_t byte = 0b01101001;
                REQUIRE(byte == 105);

                WHEN("some of the bits are set") {
                    THEN("the byte (when interpreted as a uint8_t) changes accordingly") {
                        bitter::setBit(&byte, 0, Bit::Zero);
                        REQUIRE(byte == 104);

                        bitter::setBit(&byte, 1, Bit::Zero);
                        REQUIRE(byte == 104);

                        bitter::setBit(&byte, 3, Bit::Zero);
                        REQUIRE(byte == 96);

                        bitter::setBit(&byte, 5, Bit::One);
                        REQUIRE(byte == 96);

                        bitter::setBit(&byte, 7, Bit::One);
                        REQUIRE(byte == 224);
                    }
                }
            }

            GIVEN("multiple bytes") {
                uint8_t bytes[] = { 0b11000011, 0b11001100, 0b00110011 };
                REQUIRE(bytes[0] == 195);
                REQUIRE(bytes[1] == 204);
                REQUIRE(bytes[2] == 51);

                WHEN("the bits are written to") {
                    THEN("the byte values change accordingly") {
                        bitter::setBit(bytes, 0, Bit::Zero);
                        REQUIRE(bytes[0] == 194);
                        REQUIRE(bytes[1] == 204);
                        REQUIRE(bytes[2] == 51);

                        bitter::setBit(bytes, 1, Bit::One);
                        REQUIRE(bytes[0] == 194);
                        REQUIRE(bytes[1] == 204);
                        REQUIRE(bytes[2] == 51);

                        bitter::setBit(bytes, 6, Bit::Zero);
                        REQUIRE(bytes[0] == 130);
                        REQUIRE(bytes[1] == 204);
                        REQUIRE(bytes[2] == 51);

                        bitter::setBit(bytes, 7, Bit::One);
                        REQUIRE(bytes[0] == 130);
                        REQUIRE(bytes[1] == 204);
                        REQUIRE(bytes[2] == 51);

                        bitter::setBit(bytes, 8, Bit::One);
                        REQUIRE(bytes[0] == 130);
                        REQUIRE(bytes[1] == 205);
                        REQUIRE(bytes[2] == 51);

                        bitter::setBit(bytes, 10, Bit::Zero);
                        REQUIRE(bytes[0] == 130);
                        REQUIRE(bytes[1] == 201);
                        REQUIRE(bytes[2] == 51);

                        bitter::setBit(bytes, 11, Bit::Zero);
                        REQUIRE(bytes[0] == 130);
                        REQUIRE(bytes[1] == 193);
                        REQUIRE(bytes[2] == 51);

                        bitter::setBit(bytes, 15, Bit::Zero);
                        REQUIRE(bytes[0] == 130);
                        REQUIRE(bytes[1] == 65);
                        REQUIRE(bytes[2] == 51);

                        bitter::setBit(bytes, 16, Bit::Zero);
                        REQUIRE(bytes[0] == 130);
                        REQUIRE(bytes[1] == 65);
                        REQUIRE(bytes[2] == 50);

                        bitter::setBit(bytes, 18, Bit::One);
                        REQUIRE(bytes[0] == 130);
                        REQUIRE(bytes[1] == 65);
                        REQUIRE(bytes[2] == 54);

                        bitter::setBit(bytes, 22, Bit::One);
                        REQUIRE(bytes[0] == 130);
                        REQUIRE(bytes[1] == 65);
                        REQUIRE(bytes[2] == 118);

                        bitter::setBit(bytes, 23, Bit::Zero);
                        REQUIRE(bytes[0] == 130);
                        REQUIRE(bytes[1] == 65);
                        REQUIRE(bytes[2] == 118);
                    }
                }
            }
        }
    }
}


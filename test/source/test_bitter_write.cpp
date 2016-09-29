#include <catch.hpp>

#include <cstdint>

#include <bitter_write.hpp>

namespace bitter {
    namespace test {
        SCENARIO("bits can be written to the target") {
            GIVEN("a single byte with all zeros") {
                uint8_t byte = 0b00000000;

                WHEN("a bit writer is created to write to it") {
                    BitWriter bitWriter(&byte, sizeof(byte));

                    WHEN("bit 0 is set to 1 and the others are set to 0") {
                        bitWriter.setBit(0, Bit::One);
                        bitWriter.setBit(1, Bit::Zero);
                        bitWriter.setBit(2, Bit::Zero);
                        bitWriter.setBit(3, Bit::Zero);
                        bitWriter.setBit(4, Bit::Zero);
                        bitWriter.setBit(5, Bit::Zero);
                        bitWriter.setBit(6, Bit::Zero);
                        bitWriter.setBit(7, Bit::Zero);

                        THEN("the byte (when interpreted as a uint8_t) is equal to one") {
                            REQUIRE(byte == 1);
                        }
                    }
                }
            }

            GIVEN("a single byte with all ones") {
                uint8_t byte = 0b11111111;

                WHEN("a bit writer is created to write to it") {
                    BitWriter bitWriter(&byte, sizeof(byte));

                    WHEN("bit 7 is set to 0 and the others are set to 1") {
                        bitWriter.setBit(0, Bit::One);
                        bitWriter.setBit(1, Bit::One);
                        bitWriter.setBit(2, Bit::One);
                        bitWriter.setBit(3, Bit::One);
                        bitWriter.setBit(4, Bit::One);
                        bitWriter.setBit(5, Bit::One);
                        bitWriter.setBit(6, Bit::One);
                        bitWriter.setBit(7, Bit::Zero);

                        THEN("the byte (when interpreted as a uint8_t) is equal to 127") {
                            REQUIRE(byte == 127);
                        }
                    }
                }
            }

            GIVEN("a single byte with a complex bit pattern") {
                uint8_t byte = 0b01101001;
                REQUIRE(byte == 105);

                WHEN("a bit writer is created to write to it") {
                    BitWriter bitWriter(&byte, sizeof(byte));

                    WHEN("some of the bits are set") {
                        THEN("the byte (when interpreted as a uint8_t) changes accordingly") {
                            bitWriter.setBit(0, Bit::Zero);
                            REQUIRE(byte == 104);

                            bitWriter.setBit(1, Bit::Zero);
                            REQUIRE(byte == 104);

                            bitWriter.setBit(3, Bit::Zero);
                            REQUIRE(byte == 96);

                            bitWriter.setBit(5, Bit::One);
                            REQUIRE(byte == 96);

                            bitWriter.setBit(7, Bit::One);
                            REQUIRE(byte == 224);
                        }
                    }
                }
            }

            GIVEN("multiple bytes") {
                uint8_t bytes[] = { 0b11000011, 0b11001100, 0b00110011 };
                REQUIRE(bytes[0] == 195);
                REQUIRE(bytes[1] == 204);
                REQUIRE(bytes[2] == 51);

                WHEN(" a bit writer is created to write to them") {
                    BitWriter bitWriter(&bytes, sizeof(bytes));

                    WHEN("the bits are written to") {
                        THEN("the byte values change accordingly") {
                            bitWriter.setBit(0, Bit::Zero);
                            REQUIRE(bytes[0] == 194);
                            REQUIRE(bytes[1] == 204);
                            REQUIRE(bytes[2] == 51);

                            bitWriter.setBit(1, Bit::One);
                            REQUIRE(bytes[0] == 194);
                            REQUIRE(bytes[1] == 204);
                            REQUIRE(bytes[2] == 51);

                            bitWriter.setBit(6, Bit::Zero);
                            REQUIRE(bytes[0] == 130);
                            REQUIRE(bytes[1] == 204);
                            REQUIRE(bytes[2] == 51);

                            bitWriter.setBit(7, Bit::One);
                            REQUIRE(bytes[0] == 130);
                            REQUIRE(bytes[1] == 204);
                            REQUIRE(bytes[2] == 51);

                            bitWriter.setBit(8, Bit::One);
                            REQUIRE(bytes[0] == 130);
                            REQUIRE(bytes[1] == 205);
                            REQUIRE(bytes[2] == 51);

                            bitWriter.setBit(10, Bit::Zero);
                            REQUIRE(bytes[0] == 130);
                            REQUIRE(bytes[1] == 201);
                            REQUIRE(bytes[2] == 51);

                            bitWriter.setBit(11, Bit::Zero);
                            REQUIRE(bytes[0] == 130);
                            REQUIRE(bytes[1] == 193);
                            REQUIRE(bytes[2] == 51);

                            bitWriter.setBit(15, Bit::Zero);
                            REQUIRE(bytes[0] == 130);
                            REQUIRE(bytes[1] == 65);
                            REQUIRE(bytes[2] == 51);

                            bitWriter.setBit(16, Bit::Zero);
                            REQUIRE(bytes[0] == 130);
                            REQUIRE(bytes[1] == 65);
                            REQUIRE(bytes[2] == 50);

                            bitWriter.setBit(18, Bit::One);
                            REQUIRE(bytes[0] == 130);
                            REQUIRE(bytes[1] == 65);
                            REQUIRE(bytes[2] == 54);

                            bitWriter.setBit(22, Bit::One);
                            REQUIRE(bytes[0] == 130);
                            REQUIRE(bytes[1] == 65);
                            REQUIRE(bytes[2] == 118);

                            bitWriter.setBit(23, Bit::Zero);
                            REQUIRE(bytes[0] == 130);
                            REQUIRE(bytes[1] == 65);
                            REQUIRE(bytes[2] == 118);
                        }
                    }
                }
            }
        }
    }
}


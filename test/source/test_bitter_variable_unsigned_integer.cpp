#include <catch.hpp>

#include <bitter_variable_unsigned_integer.hpp>

#include <array>

namespace bitter {
    namespace test {
        SCENARIO("VariableUnsignedInteger can be used like an intrinsic unsigned int") {
            GIVEN("a 1 byte VariableUnsignedInteger instance") {
                VariableUnsignedInteger instance(1);

                WHEN("valid values are assigned to it") {
                    THEN("logical operators should yield correct results") {
                        instance = 42;

                        REQUIRE(instance == 42);
                        REQUIRE(! (instance != 42));
                        REQUIRE(42 == instance);
                        REQUIRE(! (42 != instance));

                        REQUIRE(instance != 180);
                        REQUIRE(! (instance == 180));
                        REQUIRE(180 != instance);
                        REQUIRE(! (180 == instance));

                        REQUIRE(instance < 43);
                        REQUIRE(! (instance < 42));
                        REQUIRE(43 > instance);
                        REQUIRE(! (42 > instance));

                        REQUIRE(instance <= 42);
                        REQUIRE(instance <= 100);
                        REQUIRE(! (instance <= 10));
                        REQUIRE(42 >= instance);
                        REQUIRE(100 >= instance);
                        REQUIRE(! (10 >= instance));

                        instance = 0;

                        REQUIRE(instance == 0);
                        REQUIRE(! (instance != 0));
                        REQUIRE(0 == instance);
                        REQUIRE(! (0 != instance));

                        REQUIRE(instance != 42);
                        REQUIRE(! (instance == 42));
                        REQUIRE(42 != instance);
                        REQUIRE(! (42 == instance));

                        REQUIRE(instance < 10);
                        REQUIRE(! (instance < 0));
                        REQUIRE(10 > instance);
                        REQUIRE(! (0 > instance));

                        REQUIRE(instance <= 0);
                        REQUIRE(instance <= 123);
                        REQUIRE(0 >= instance);
                        REQUIRE(123 >= instance);

                        instance = 255;

                        REQUIRE(instance == 255);
                        REQUIRE(! (instance != 255));
                        REQUIRE(255 == instance);
                        REQUIRE(! (255 != instance));

                        REQUIRE(instance != 0);
                        REQUIRE(! (instance == 0));
                        REQUIRE(0 != instance);
                        REQUIRE(! (0 == instance));

                        REQUIRE(instance < 256);
                        REQUIRE(! (instance < 255));
                        REQUIRE(256 > instance);
                        REQUIRE(! (255 > instance));

                        REQUIRE(instance <= 255);
                        REQUIRE(instance <= 260);
                        REQUIRE(! (instance <= 254));
                        REQUIRE(255 >= instance);
                        REQUIRE(260 >= instance);
                        REQUIRE(! (254 >= instance));
                    }
                }
            }

            GIVEN("a 3 byte VariableUnsignedInteger instance") {
                VariableUnsignedInteger instance(3);

                WHEN("valid values are assigned to it") {
                    THEN("it should be equal to the value assigned "
                         "and not equal to others") {
                        instance = 500;

                        REQUIRE(instance == 500);
                        REQUIRE(! (instance != 500));
                        REQUIRE(500 == instance);
                        REQUIRE(! (500 != instance));

                        REQUIRE(instance != 42);
                        REQUIRE(! (instance == 42));
                        REQUIRE(42 != instance);
                        REQUIRE(! (42 == instance));

                        REQUIRE(instance < 510);
                        REQUIRE(! (instance < 500));
                        REQUIRE(510 > instance);
                        REQUIRE(! (500 > instance));

                        REQUIRE(instance <= 500);
                        REQUIRE(instance <= 510);
                        REQUIRE(! (instance <= 123));
                        REQUIRE(500 >= instance);
                        REQUIRE(510 >= instance);
                        REQUIRE(! (123 >= instance));

                        instance = 16777215;

                        REQUIRE(instance == 16777215);
                        REQUIRE(! (instance != 16777215));
                        REQUIRE(16777215 == instance);
                        REQUIRE(! (16777215 != instance));

                        REQUIRE(instance != 500);
                        REQUIRE(! (instance == 500));
                        REQUIRE(500 != instance);
                        REQUIRE(! (500 == instance));

                        REQUIRE(instance < 16777217);
                        REQUIRE(! (instance < 167));
                        REQUIRE(16777217 > instance);
                        REQUIRE(! (167 > instance));

                        REQUIRE(instance <= 16777215);
                        REQUIRE(instance <= 16777217);
                        REQUIRE(! (instance <= 4));
                        REQUIRE(16777215 >= instance);
                        REQUIRE(16777517 >= instance);
                        REQUIRE(! (4 >= instance));

                        instance = 65536;

                        REQUIRE(instance == 65536);
                        REQUIRE(! (instance != 65536));
                        REQUIRE(65536 == instance);
                        REQUIRE(! (65536 != instance));

                        REQUIRE(instance != 16777215);
                        REQUIRE(! (instance == 16777215));
                        REQUIRE(16777215 != instance);
                        REQUIRE(! (16777215 == instance));

                        REQUIRE(instance < 70000);
                        REQUIRE(! (instance < 60000));
                        REQUIRE(70000 > instance);
                        REQUIRE(! (60000 > instance));

                        REQUIRE(instance <= 65536);
                        REQUIRE(instance <= 123123);
                        REQUIRE(! (instance <= 321));
                        REQUIRE(65536 >= instance);
                        REQUIRE(123123 >= instance);
                        REQUIRE(! (321 >= instance));

                        instance = 256;

                        REQUIRE(instance == 256);
                        REQUIRE(! (instance != 256));
                        REQUIRE(256 == instance);
                        REQUIRE(! (256 != instance));

                        REQUIRE(instance != 16777215);
                        REQUIRE(! (instance == 16777215));
                        REQUIRE(16777215 != instance);
                        REQUIRE(! (16777215 == instance));

                        REQUIRE(instance < 257);
                        REQUIRE(! (instance < 255));
                        REQUIRE(257 > instance);
                        REQUIRE(! (255 > instance));

                        REQUIRE(instance <= 256);
                        REQUIRE(instance <= 257);
                        REQUIRE(! (instance <= 255));
                        REQUIRE(256 >= instance);
                        REQUIRE(257 >= instance);
                        REQUIRE(! (255 >= instance));
                    }
                }
            }

            GIVEN("2 initialised instances of the same size") {
                VariableUnsignedInteger instanceA(3);
                instanceA = 12;

                VariableUnsignedInteger instanceB(3);
                instanceB = 19;

                WHEN("one is assigned to the other") {
                    instanceA = instanceB;

                    THEN("they are both considered equal") {
                        REQUIRE(instanceA == instanceB);
                        REQUIRE(! (instanceA != instanceB));
                        REQUIRE(instanceB == instanceA);
                        REQUIRE(! (instanceB != instanceA));

                        REQUIRE(instanceA >= instanceB);
                        REQUIRE(instanceB >= instanceA);
                        REQUIRE(instanceA <= instanceB);
                        REQUIRE(instanceB <= instanceA);

                        REQUIRE(! (instanceA > instanceB));
                        REQUIRE(! (instanceB > instanceA));
                        REQUIRE(! (instanceA < instanceB));
                        REQUIRE(! (instanceB < instanceA));
                    }

                    THEN("they should both equal the same number") {
                        REQUIRE(instanceA == 19);
                        REQUIRE(! (instanceA != 19));
                        REQUIRE(19 == instanceA);
                        REQUIRE(! (19 != instanceA));

                        REQUIRE(instanceA >= 19);
                        REQUIRE(19 >= instanceA);
                        REQUIRE(instanceA <= 19);
                        REQUIRE(19 <= instanceA);

                        REQUIRE(! (instanceA > 19));
                        REQUIRE(! (19 > instanceA));
                        REQUIRE(! (instanceA < 19));
                        REQUIRE(! (19 < instanceA));

                        REQUIRE(instanceB == 19);
                        REQUIRE(! (instanceB != 19));
                        REQUIRE(19 == instanceB);
                        REQUIRE(! (19 != instanceB));

                        REQUIRE(instanceB >= 19);
                        REQUIRE(19 >= instanceB);
                        REQUIRE(instanceB <= 19);
                        REQUIRE(19 <= instanceB);

                        REQUIRE(! (instanceB > 19));
                        REQUIRE(! (19 > instanceB));
                        REQUIRE(! (instanceB < 19));
                        REQUIRE(! (19 < instanceB));
                    }
                }
            }

            GIVEN("2 initialised instances of the different size") {
                VariableUnsignedInteger instanceA(4);
                instanceA = 7;

                VariableUnsignedInteger instanceB(2);
                instanceB = 100;

                WHEN("one is assigned to the other") {
                    instanceA = instanceB;

                    THEN("they are both considered equal") {
                        REQUIRE(instanceA == instanceB);
                        REQUIRE(! (instanceA != instanceB));
                        REQUIRE(instanceB == instanceA);
                        REQUIRE(! (instanceB != instanceA));

                        REQUIRE(instanceA >= instanceB);
                        REQUIRE(instanceB >= instanceA);
                        REQUIRE(instanceA <= instanceB);
                        REQUIRE(instanceB <= instanceA);

                        REQUIRE(! (instanceA > instanceB));
                        REQUIRE(! (instanceB > instanceA));
                        REQUIRE(! (instanceA < instanceB));
                        REQUIRE(! (instanceB < instanceA));
                    }

                    THEN("they should both equal the same number") {
                        REQUIRE(instanceA == 100);
                        REQUIRE(! (instanceA != 100));
                        REQUIRE(100 == instanceA);
                        REQUIRE(! (100 != instanceA));

                        REQUIRE(instanceA >= 100);
                        REQUIRE(100 >= instanceA);
                        REQUIRE(instanceA <= 100);
                        REQUIRE(100 <= instanceA);

                        REQUIRE(! (instanceA > 100));
                        REQUIRE(! (100 > instanceA));
                        REQUIRE(! (instanceA < 100));
                        REQUIRE(! (100 < instanceA));

                        REQUIRE(instanceB == 100);
                        REQUIRE(! (instanceB != 100));
                        REQUIRE(100 == instanceB);
                        REQUIRE(! (100 != instanceB));

                        REQUIRE(instanceB >= 100);
                        REQUIRE(100 >= instanceB);
                        REQUIRE(instanceB <= 100);
                        REQUIRE(100 <= instanceB);

                        REQUIRE(! (instanceB > 100));
                        REQUIRE(! (100 > instanceB));
                        REQUIRE(! (instanceB < 100));
                        REQUIRE(! (100 < instanceB));
                    }
                }
            }

            GIVEN("2 initialised instances of different size and different value") {
                VariableUnsignedInteger instanceA(4);
                instanceA = 524288;

                VariableUnsignedInteger instanceB(2);
                instanceB = 0;

                WHEN("they are compared") {
                    THEN("all comparison operations should act appropriately") {
                        REQUIRE(instanceA != instanceB);
                        REQUIRE(instanceB != instanceA);

                        REQUIRE(! (instanceA == instanceB));
                        REQUIRE(! (instanceB == instanceA));

                        REQUIRE(instanceA >= instanceB);
                        REQUIRE(! (instanceB >= instanceA));
                        REQUIRE(! (instanceA <= instanceB));
                        REQUIRE(instanceB <= instanceA);

                        REQUIRE((instanceA > instanceB));
                        REQUIRE(! (instanceB > instanceA));
                        REQUIRE(! (instanceA < instanceB));
                        REQUIRE((instanceB < instanceA));
                    }
                }
            }

            GIVEN("2 initialised instances of different size but of the same value") {
                VariableUnsignedInteger instanceA(4);
                instanceA = 200;

                VariableUnsignedInteger instanceB(2);
                instanceB = 200;

                WHEN("they are compared") {
                    THEN("all comparison operations should act appropriately") {
                        REQUIRE(instanceA == instanceB);
                        REQUIRE(instanceB == instanceA);

                        REQUIRE(! (instanceA != instanceB));
                        REQUIRE(! (instanceB != instanceA));

                        REQUIRE(instanceA >= instanceB);
                        REQUIRE(instanceB >= instanceA);
                        REQUIRE(instanceA <= instanceB);
                        REQUIRE(instanceB <= instanceA);

                        REQUIRE(! (instanceA > instanceB));
                        REQUIRE(! (instanceB > instanceA));
                        REQUIRE(! (instanceA < instanceB));
                        REQUIRE(! (instanceB < instanceA));
                    }
                }
            }

            GIVEN("a VariableUnsignedInteger of size 2") {
                VariableUnsignedInteger instance(2);
                instance = 0;

                WHEN("arithmetic assignment operators are used") {
                    THEN("its value should change appropriately and the same object should be returned") {
                        REQUIRE(&(instance += 100) == &instance);
                        REQUIRE(instance == 100);

                        REQUIRE(&(instance -= 50) == &instance);
                        REQUIRE(instance == 50);

                        REQUIRE(&(instance *= 4) == &instance);
                        REQUIRE(instance == 200);

                        REQUIRE(&(instance /= 8) == &instance);
                        REQUIRE(instance == 25);

                        REQUIRE(&(instance %= 10) == &instance);
                        REQUIRE(instance == 5);
                    }
                }
            }

            GIVEN("two VariableUnsignedIntegers of different size") {
                VariableUnsignedInteger instanceA(4);
                VariableUnsignedInteger instanceB(2);


                WHEN("arithmetic operations are perfored between them") {
                    THEN("the resulting values are expected") {
                        instanceA = 288;
                        instanceB = 24;

                        REQUIRE(instanceA + instanceB == 312);
                        REQUIRE(instanceB + instanceA == 312);

                        REQUIRE(instanceA - instanceB == 264);

                        REQUIRE(instanceA * instanceB == 6912);
                        REQUIRE(instanceB * instanceA == 6912);

                        REQUIRE(instanceA / instanceB == 12);
                        REQUIRE(instanceB / instanceA == 0);

                        REQUIRE(instanceA % instanceB == 0);
                        REQUIRE(instanceB % instanceA == 24);

                        instanceB = 289;

                        REQUIRE(instanceB - instanceA == 1);
                    }
                }
            }

            GIVEN("a VariableUnsignedInteger of size 4") {
                VariableUnsignedInteger instance(4);

                WHEN("arithmetic operations are performed upon it") {
                    THEN("the resulting value changes appropriately") {
                        constexpr std::array<uint32_t, 10> startingValues32 = {
                            0, 1, 42,
                            255, 256,
                            65535, 65536,
                            1677715, 1677716,
                            4294967294
                        };

                        constexpr std::array<uint16_t, 11> operands16 = {
                            0, 1, 2, 542, 76,                       // randomly chosen values
                            254, 255, 256, 257,                     // around 1st byte boundary
                            65534, 65535                            // around 2nd byte boundary
                        };

                        constexpr std::array<uint32_t, 20> operands32 = {
                            0, 1, 2, 542, 76, 99999,                // randomly chosen values
                            254, 255, 256, 257,                     // around 1st byte boundary
                            65534, 65535, 65536, 65537,             // around 2nd byte boundary
                            16777214, 16777215, 16777216, 16777217, // around 3rd byte boundary
                            4294967294, 4294967295                  // around 4th byte boundary
                        };

                        constexpr std::array<uint64_t, 20> operands64 = {
                            0, 1, 2, 542, 76, 99999,                // randomly chosen values
                            254, 255, 256, 257,                     // around 1st byte boundary
                            65534, 65535, 65536, 65537,             // around 2nd byte boundary
                            16777214, 16777215, 16777216, 16777217, // around 3rd byte boundary
                            4294967294, 4294967295                  // around 4th byte boundary
                        };

                        // NOTE:
                        // this function assumes no values >= 2^32 are used
                        const auto testFunction = [&instance](const auto startingValues, const auto operands) {
                            for(const auto startingValue : startingValues) {
                                instance = startingValue;

                                for(const auto operand : operands) {
                                    //////////////
                                    // addition //
                                    //////////////

                                    if(static_cast<uint64_t>(startingValue) + static_cast<uint64_t>(operand) <= std::numeric_limits<uint32_t>::max()) {
                                        REQUIRE(instance + operand == startingValue + operand);
                                        REQUIRE(operand + instance == operand + startingValue);
                                    }

                                    ////////////////////
                                    // multiplication //
                                    ////////////////////

                                    if(static_cast<uint64_t>(startingValue) * static_cast<uint64_t>(operand) <= std::numeric_limits<uint32_t>::max()) {
                                        REQUIRE(instance * operand == startingValue * operand);
                                        REQUIRE(operand * instance == operand * startingValue);
                                    }

                                    /////////////////
                                    // subtraction //
                                    /////////////////

                                    if(static_cast<int64_t>(startingValue) - static_cast<int64_t>(operand) >= 0) {
                                        REQUIRE(instance - operand == startingValue - operand);
                                    }

                                    if(static_cast<int64_t>(operand) - static_cast<int64_t>(startingValue) >= 0) {
                                        REQUIRE(operand - instance == operand - startingValue);
                                    }

                                    //////////////
                                    // division //
                                    //////////////

                                    if(operand != 0) {
                                        REQUIRE(instance / operand == startingValue / operand);
                                    }

                                    if(startingValue != 0) {
                                        REQUIRE(operand / instance == operand / startingValue);
                                    }

                                    /////////////
                                    // modulus //
                                    /////////////

                                    if(operand != 0) {
                                        REQUIRE(instance % operand == startingValue % operand);
                                    }

                                    if(startingValue != 0) {
                                        REQUIRE(operand % instance == operand % startingValue);
                                    }
                                }
                            }
                        };

                        testFunction(startingValues32, operands16);
                        testFunction(startingValues32, operands32);
                        testFunction(startingValues32, operands64);
                    }
                }
            }

            GIVEN("a VariableUnsignedInteger of size 8") {
                VariableUnsignedInteger instance(8);

                WHEN("unary operator- is applied to it") {
                    THEN("the value changes as expected") {
                        instance = 0U;
                        REQUIRE(-instance == 0U);

                        instance = 1U;
                        REQUIRE(-instance == 18446744073709551615U);

                        instance = 18446744073709551615U;
                        REQUIRE(-instance == 1U);

                        instance = 257U;
                        REQUIRE(-instance == 18446744073709551359U);

                        instance = 18446744073709551359U;
                        REQUIRE(-instance == 257U);

                        instance = 123456789U;
                        REQUIRE(-instance == 18446744073586094827U);

                        instance = 18446744073586094827U;
                        REQUIRE(-instance == 123456789U);

                        instance = 18443616647367798558U;
                        REQUIRE(-instance == 3127426341753058U);

                        instance = 3127426341753058U;
                        REQUIRE(-instance == 18443616647367798558U);
                    }
                }
            }
            
            GIVEN("a VariableUnsignedInteger of size 4") {
                VariableUnsignedInteger instance(4);

                WHEN("binary operator- is applied where the right operand is greater than the left VariableUnsignedInteger") {
                    THEN("the result is correct") {
                        instance = 0;

                        REQUIRE(instance - 1 == 4294967295);
                        REQUIRE(instance - 200 == 4294967096);
                        REQUIRE(instance - 500 == 4294966796);
                        REQUIRE(instance - 1000 == 4294966296);
                        
                        instance = 1;
                        
                        REQUIRE(instance - 11 == 4294967286);
                        REQUIRE(instance - 200 == 4294967097);
                        REQUIRE(instance - 500 == 4294966797);
                        REQUIRE(instance - 1000 == 4294966297);
                        
                        instance = 300;
                        
                        REQUIRE(instance - 301 == 4294967295);
                        REQUIRE(instance - 3200 == 4294964396);
                        REQUIRE(instance - 500 == 4294967096);
                        REQUIRE(instance - 1000 == 4294966596);
                    }
                }
            }

            GIVEN("a VariableUnsignedInteger of size 2") {
                VariableUnsignedInteger instance(2);

                WHEN("operator~ is applied to it") {
                    THEN("its value changes appropriately") {
                        instance = 0b0000000000000000;
                        REQUIRE(~instance == 0b1111111111111111);

                        instance = 0b1111000011110000;
                        REQUIRE(~instance == 0b0000111100001111);

                        instance = 0b0011110011000011;
                        REQUIRE(~instance == 0b1100001100111100);
                    }
                }
            }

            GIVEN("a pair of VariableUnsignedIntegers of size 2 and 3") {
                VariableUnsignedInteger instanceA(2);
                VariableUnsignedInteger instanceB(3);

                WHEN("operator& is applied to it") {
                    THEN("its value changes appropriately") {
                        instanceA = 0b0000000000000000;
                        instanceB = 0b000000000000000000000000;

                        REQUIRE((instanceA & instanceB) == 0b000000000000000000000000);
                        REQUIRE((instanceB & instanceA) == 0b000000000000000000000000);

                        instanceB = 0b100000000000000000000000;

                        REQUIRE((instanceA & instanceB) == 0b000000000000000000000000);
                        REQUIRE((instanceB & instanceA) == 0b000000000000000000000000);

                        instanceA = 0b0000000000000001;

                        REQUIRE((instanceA & instanceB) == 0b000000000000000000000000);
                        REQUIRE((instanceB & instanceA) == 0b000000000000000000000000);

                        instanceB = 0b111111111111111111111111;

                        REQUIRE((instanceA & instanceB) == 0b000000000000000000000001);
                        REQUIRE((instanceB & instanceA) == 0b000000000000000000000001);

                        instanceA = 0b1000000000000000;

                        REQUIRE((instanceA & instanceB) == 0b000000001000000000000000);
                        REQUIRE((instanceB & instanceA) == 0b000000001000000000000000);

                        instanceB = 0b100000001000000000000000;

                        REQUIRE((instanceA & instanceB) == 0b000000001000000000000000);
                        REQUIRE((instanceB & instanceA) == 0b000000001000000000000000);

                        instanceA = 0b1111111111111111;

                        REQUIRE((instanceA & instanceB) == 0b000000001000000000000000);
                        REQUIRE((instanceB & instanceA) == 0b000000001000000000000000);

                        instanceB = 0b101010101010101010101010;

                        REQUIRE((instanceA & instanceB) == 0b000000001010101010101010);
                        REQUIRE((instanceB & instanceA) == 0b000000001010101010101010);
                    }
                }
            }

            GIVEN("a pair of VariableUnsignedIntegers of size 2 and 3") {
                VariableUnsignedInteger instanceA(2);
                VariableUnsignedInteger instanceB(3);

                WHEN("operator| is applied to it") {
                    THEN("its value changes appropriately") {
                        instanceA = 0b0000000000000000;
                        instanceB = 0b000000000000000000000000;

                        REQUIRE((instanceA | instanceB) == 0b000000000000000000000000);
                        REQUIRE((instanceB | instanceA) == 0b000000000000000000000000);

                        instanceB = 0b100000000000000000000000;

                        REQUIRE((instanceA | instanceB) == 0b100000000000000000000000);
                        REQUIRE((instanceB | instanceA) == 0b100000000000000000000000);

                        instanceA = 0b0000000000000001;

                        REQUIRE((instanceA | instanceB) == 0b100000000000000000000001);
                        REQUIRE((instanceB | instanceA) == 0b100000000000000000000001);

                        instanceB = 0b111111111111111111111111;

                        REQUIRE((instanceA | instanceB) == 0b111111111111111111111111);
                        REQUIRE((instanceB | instanceA) == 0b111111111111111111111111);

                        instanceA = 0b1000000000000000;

                        REQUIRE((instanceA | instanceB) == 0b111111111111111111111111);
                        REQUIRE((instanceB | instanceA) == 0b111111111111111111111111);

                        instanceB = 0b100000001000000000000000;

                        REQUIRE((instanceA | instanceB) == 0b100000001000000000000000);
                        REQUIRE((instanceB | instanceA) == 0b100000001000000000000000);

                        instanceA = 0b1111111111111111;

                        REQUIRE((instanceA | instanceB) == 0b100000001111111111111111);
                        REQUIRE((instanceB | instanceA) == 0b100000001111111111111111);

                        instanceB = 0b101010101010101010101010;

                        REQUIRE((instanceA | instanceB) == 0b101010101111111111111111);
                        REQUIRE((instanceB | instanceA) == 0b101010101111111111111111);
                    }
                }
            }

            GIVEN("a pair of VariableUnsignedIntegers of size 2 and 3") {
                VariableUnsignedInteger instanceA(2);
                VariableUnsignedInteger instanceB(3);

                WHEN("operator^ is applied to it") {
                    THEN("its value changes appropriately") {
                        instanceA = 0b0000000000000000;
                        instanceB = 0b000000000000000000000000;

                        REQUIRE((instanceA ^ instanceB) == 0b000000000000000000000000);
                        REQUIRE((instanceB ^ instanceA) == 0b000000000000000000000000);

                        instanceB = 0b100000000000000000000000;

                        REQUIRE((instanceA ^ instanceB) == 0b100000000000000000000000);
                        REQUIRE((instanceB ^ instanceA) == 0b100000000000000000000000);

                        instanceA = 0b0000000000000001;

                        REQUIRE((instanceA ^ instanceB) == 0b100000000000000000000001);
                        REQUIRE((instanceB ^ instanceA) == 0b100000000000000000000001);

                        instanceB = 0b111111111111111111111111;

                        REQUIRE((instanceA ^ instanceB) == 0b111111111111111111111110);
                        REQUIRE((instanceB ^ instanceA) == 0b111111111111111111111110);

                        instanceA = 0b1000000000000000;

                        REQUIRE((instanceA ^ instanceB) == 0b111111110111111111111111);
                        REQUIRE((instanceB ^ instanceA) == 0b111111110111111111111111);

                        instanceB = 0b100000001000000000000000;

                        REQUIRE((instanceA ^ instanceB) == 0b100000000000000000000000);
                        REQUIRE((instanceB ^ instanceA) == 0b100000000000000000000000);

                        instanceA = 0b1111111111111111;

                        REQUIRE((instanceA ^ instanceB) == 0b100000000111111111111111);
                        REQUIRE((instanceB ^ instanceA) == 0b100000000111111111111111);

                        instanceB = 0b101010101010101010101010;

                        REQUIRE((instanceA ^ instanceB) == 0b101010100101010101010101);
                        REQUIRE((instanceB ^ instanceA) == 0b101010100101010101010101);
                    }
                }
            }

            GIVEN("a VariableUnsignedInteger of size 3") {
                VariableUnsignedInteger instance(3);

                WHEN("operator<< is applied to it ") {
                    THEN("its value changes appropriately") {
                        instance = 0;

                        // TODO:
                        // should there be tests like,
                        // 0 << instance?
                        REQUIRE(instance << 0 == 0);
                        REQUIRE(instance << 1 == 0);
                        REQUIRE(instance << 7 == 0);
                        REQUIRE(instance << 8 == 0);
                        REQUIRE(instance << 9 == 0);
                        REQUIRE(instance << 15 == 0);
                        REQUIRE(instance << 16 == 0);
                        REQUIRE(instance << 17 == 0);
                        REQUIRE(instance << 23 == 0);

                        instance = 1;

                        REQUIRE(instance << 0 == 1);
                        REQUIRE(instance << 1 == 2);
                        REQUIRE(instance << 7 == 128);
                        REQUIRE(instance << 8 == 256);
                        REQUIRE(instance << 9 == 512);
                        REQUIRE(instance << 15 == 32768);
                        REQUIRE(instance << 16 == 65536);
                        REQUIRE(instance << 17 == 131072);
                        REQUIRE(instance << 23 == 8388608);

                        instance = 3;

                        REQUIRE(instance << 0 == 3);
                        REQUIRE(instance << 1 == 6);
                        REQUIRE(instance << 7 == 384);
                        REQUIRE(instance << 8 == 768);
                        REQUIRE(instance << 9 == 1536);
                        REQUIRE(instance << 15 == 98304);
                        REQUIRE(instance << 16 == 196608);
                        REQUIRE(instance << 17 == 393216);
                        REQUIRE(instance << 23 == 8388608);

                        instance = 263;

                        REQUIRE(instance << 0 == 263);
                        REQUIRE(instance << 1 == 526);
                        REQUIRE(instance << 7 == 33664);
                        REQUIRE(instance << 8 == 67328);
                        REQUIRE(instance << 9 == 134656);
                        REQUIRE(instance << 15 == 8617984);
                        REQUIRE(instance << 16 == 458752);
                        REQUIRE(instance << 17 == 917504);
                        REQUIRE(instance << 23 == 8388608);

                        instance = 98304;

                        REQUIRE(instance << 0 == 98304);
                        REQUIRE(instance << 1 == 196608);
                        REQUIRE(instance << 7 == 12582912);
                        REQUIRE(instance << 8 == 8388608);
                        REQUIRE(instance << 9 == 0);
                        REQUIRE(instance << 15 == 0);
                        REQUIRE(instance << 16 == 0);
                        REQUIRE(instance << 17 == 0);
                        REQUIRE(instance << 23 == 0);
                    }
                }
            }

            GIVEN("a VariableUnsignedInteger of size 42") {
                VariableUnsignedInteger instance(42);

                WHEN("pre/post increment/decrement are applied to it") {
                    THEN("its value changes accordingly") {
                        instance = 0;

                        REQUIRE(++instance == 1);
                        REQUIRE(instance == 1);

                        REQUIRE(instance++ == 1);
                        REQUIRE(instance == 2);

                        REQUIRE(--instance == 1);
                        REQUIRE(instance == 1);

                        REQUIRE(instance-- == 1);
                        REQUIRE(instance == 0);

                        instance = 254;

                        REQUIRE(++instance == 255);
                        REQUIRE(instance == 255);

                        REQUIRE(instance++ == 255);
                        REQUIRE(instance == 256);

                        REQUIRE(--instance == 255);
                        REQUIRE(instance == 255);

                        REQUIRE(instance-- == 255);
                        REQUIRE(instance == 254);
                    }
                }
            }

            GIVEN("a VariableUnsignedInteger of size 3") {
                VariableUnsignedInteger instance(3);

                WHEN("operator>> is applied to it ") {
                    THEN("its value changes appropriately") {
                        instance = 0;

                        // TODO:
                        // should there be tests like,
                        // 0 >> instance?
                        REQUIRE(instance >> 0 == 0);
                        REQUIRE(instance >> 1 == 0);
                        REQUIRE(instance >> 7 == 0);
                        REQUIRE(instance >> 8 == 0);
                        REQUIRE(instance >> 9 == 0);
                        REQUIRE(instance >> 15 == 0);
                        REQUIRE(instance >> 16 == 0);
                        REQUIRE(instance >> 17 == 0);
                        REQUIRE(instance >> 23 == 0);

                        instance = 1;

                        REQUIRE(instance >> 0 == 1);
                        REQUIRE(instance >> 1 == 0);
                        REQUIRE(instance >> 7 == 0);
                        REQUIRE(instance >> 8 == 0);
                        REQUIRE(instance >> 9 == 0);
                        REQUIRE(instance >> 15 == 0);
                        REQUIRE(instance >> 16 == 0);
                        REQUIRE(instance >> 17 == 0);
                        REQUIRE(instance >> 23 == 0);

                        instance = 263;

                        REQUIRE(instance >> 0 == 263);
                        REQUIRE(instance >> 1 == 131);
                        REQUIRE(instance >> 7 == 2);
                        REQUIRE(instance >> 8 == 1);
                        REQUIRE(instance >> 9 == 0);
                        REQUIRE(instance >> 15 == 0);
                        REQUIRE(instance >> 16 == 0);
                        REQUIRE(instance >> 17 == 0);
                        REQUIRE(instance >> 23 == 0);

                        instance = 98304;

                        REQUIRE(instance >> 0 == 98304);
                        REQUIRE(instance >> 1 == 49152);
                        REQUIRE(instance >> 7 == 768);
                        REQUIRE(instance >> 8 == 384);
                        REQUIRE(instance >> 9 == 192);
                        REQUIRE(instance >> 15 == 3);
                        REQUIRE(instance >> 16 == 1);
                        REQUIRE(instance >> 17 == 0);
                        REQUIRE(instance >> 23 == 0);

                        instance = 16777215;

                        REQUIRE(instance >> 0 == 16777215);
                        REQUIRE(instance >> 1 == 8388607);
                        REQUIRE(instance >> 7 == 131071);
                        REQUIRE(instance >> 8 == 65535);
                        REQUIRE(instance >> 9 == 32767);
                        REQUIRE(instance >> 15 == 511);
                        REQUIRE(instance >> 16 == 255);
                        REQUIRE(instance >> 17 == 127);
                        REQUIRE(instance >> 23 == 1);
                    }
                }
            }

            GIVEN("a VariableUnsignedInteger of size 2") {
                VariableUnsignedInteger instance(2);

                WHEN("stream operator<< is called") {
                    THEN("the appropriate string is added to the stream") {
                        std::stringstream ss;

                        instance = 0;
                        ss << instance;

                        REQUIRE(ss.str() == "0");

                        instance = 1;
                        ss << instance;

                        REQUIRE(ss.str() == "01");

                        instance = 254;
                        ss << instance;

                        REQUIRE(ss.str() == "01254");

                        instance = 255;
                        ss << instance;

                        REQUIRE(ss.str() == "01254255");

                        instance = 256;
                        ss << instance;

                        REQUIRE(ss.str() == "01254255256");

                        instance = 65535;
                        ss << instance;

                        REQUIRE(ss.str() == "0125425525665535");
                    }
                }
            }

            GIVEN("a VariableUnsignedInteger of size 2") {
                VariableUnsignedInteger instance(2);

                WHEN("steam operator>> is called") {
                    THEN("the appropriate value is assigned") {
                        std::stringstream ss;

                        ss << 42;
                        ss >> instance;

                        REQUIRE(instance == 42);

                        ss.clear();
                        ss << 254;
                        ss >> instance;

                        REQUIRE(instance == 254);

                        ss.clear();
                        ss << 255;
                        ss >> instance;

                        REQUIRE(instance == 255);

                        ss.clear();
                        ss << 256;
                        ss >> instance;

                        REQUIRE(instance == 256);

                        ss.clear();
                        ss << 0;
                        ss >> instance;

                        REQUIRE(instance == 0);
                    }
                }
            }

            GIVEN("a VariableUnsignedInteger of size 3") {
                VariableUnsignedInteger instance(3);

                WHEN("unary operator+ is called") {
                    THEN("a instance of the same value is returned") {
                        instance = 0;

                        REQUIRE(+instance == 0);

                        instance = 24;

                        REQUIRE(+instance == 24);

                        instance = 256;

                        REQUIRE(+instance == 256);
                    }
                }

                // unary operator+ is supposed to reutrn a copy, not a reference to the same value
                // that's what this is supposed to check
                static_assert(! std::is_reference<decltype(operator+(std::declval<VariableUnsignedInteger>()))>::value, "");
            }

            GIVEN("a VariableUnsignedInteger of size 2") {
                VariableUnsignedInteger instance(2);

                WHEN("unary boolean operators are applied") {
                    THEN("the returned boolean is correct") {
                        instance = 0;

                        REQUIRE(static_cast<bool>(instance) == false);
                        REQUIRE((! instance) == true);

                        instance = 1;

                        REQUIRE(static_cast<bool>(instance) == true);
                        REQUIRE((! instance) == false);

                        instance = 256;

                        REQUIRE(static_cast<bool>(instance) == true);
                        REQUIRE((! instance) == false);
                    }
                }
            }

            GIVEN("VariableUnsignedIntegers of various sizes") {
                WHEN("their size is queried") {
                    THEN("its size should be at least the passed in size") {
                        REQUIRE(VariableUnsignedInteger(0).maxValue() >= 0);
                        REQUIRE(VariableUnsignedInteger(1).maxValue() >= 255);
                        REQUIRE(VariableUnsignedInteger(2).maxValue() >= 65535);
                        REQUIRE(VariableUnsignedInteger(64).maxValue() >= 18446744073709551615UL);
                    }
                }
            }
        }
    }
}


#include <catch.hpp>

#include <bitter_variable_unsigned_integer.hpp>

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

            GIVEN("a VariableUnsignedInteger of size 4") {
                VariableUnsignedInteger instance(4);

                WHEN("arithmetic operations are performed upon it") {
                    THEN("its value changes appropriately") {
                        constexpr uint32_t startingValues[] = {
                            0, 1, 42,
                            255, 256,
                            65535, 65536,
                            1677715, 1677716,
                            4294967294
                        };

                        constexpr uint32_t operands[] = {
                            0, 1, 2, 542, 76, 99999,                // randomly chosen values
                            254, 255, 256, 257,                     // around 1st byte boundary
                            65534, 65535, 65536, 65537,             // around 2nd byte boundary
                            16777214, 16777215, 16777216, 16777217, // around 3rd byte boundary
                            4294967294, 4294967295                  // around 4th byte boundary
                        };

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
        }
    }
}


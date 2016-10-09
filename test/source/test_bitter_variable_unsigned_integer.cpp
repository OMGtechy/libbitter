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
        }
    }
}


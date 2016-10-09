#include <catch.hpp>

#include <bitter_variable_unsigned_integer.hpp>

namespace bitter {
    namespace test {
        SCENARIO("VariableUnsignedInteger can be used like an intrinsic unsigned int") {
            GIVEN("a 1 byte VariableUnsignedInteger instance") {
                VariableUnsignedInteger instance(1);

                WHEN("valid values are assigned to it") {
                    THEN("it should be equal to the value assigned "
                         "and not equal to others") {
                        instance = 42;
                        REQUIRE(instance == 42);
                        REQUIRE(! (instance != 42));
                        REQUIRE(42 == instance);
                        REQUIRE(! (42 != instance));
                        REQUIRE(instance != 180);
                        REQUIRE(! (instance == 180));
                        REQUIRE(180 != instance);
                        REQUIRE(! (180 == instance));

                        instance = 0;
                        REQUIRE(instance == 0);
                        REQUIRE(! (instance != 0));
                        REQUIRE(0 == instance);
                        REQUIRE(! (0 != instance));
                        REQUIRE(instance != 42);
                        REQUIRE(! (instance == 42));
                        REQUIRE(42 != instance);
                        REQUIRE(! (42 == instance));

                        instance = 255;
                        REQUIRE(instance == 255);
                        REQUIRE(! (instance != 255));
                        REQUIRE(255 == instance);
                        REQUIRE(! (255 != instance));
                        REQUIRE(instance != 0);
                        REQUIRE(! (instance == 0));
                        REQUIRE(0 != instance);
                        REQUIRE(! (0 == instance));
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

                        instance = 16777215;
                        REQUIRE(instance == 16777215);
                        REQUIRE(! (instance != 16777215));
                        REQUIRE(16777215 == instance);
                        REQUIRE(! (16777215 != instance));
                        REQUIRE(instance != 500);
                        REQUIRE(! (instance == 500));
                        REQUIRE(500 != instance);
                        REQUIRE(! (500 == instance));

                        instance = 65536;
                        REQUIRE(instance == 65536);
                        REQUIRE(! (instance != 65536));
                        REQUIRE(65536 == instance);
                        REQUIRE(! (65536 != instance));
                        REQUIRE(instance != 16777215);
                        REQUIRE(! (instance == 16777215));
                        REQUIRE(16777215 != instance);
                        REQUIRE(! (16777215 == instance));
                    }
                }
            }
        }
    }
}


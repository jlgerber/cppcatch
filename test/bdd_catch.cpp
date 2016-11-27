//
// Created by Jonathan Gerber on 11/27/16.
//

#include "ringbuffer.hpp"
#include "catch.hpp"

SCENARIO("RingBuffer") {

    GIVEN("An empty ring buffer with a capacity of 4") {
        size_t capacity = 4;
        RingBuffer<int> rb(capacity, 0);

        THEN("the size will be zero")
            REQUIRE(rb.size() == 0);

        WHEN("a value is pushed") {
            rb.push_back(1);
            THEN("the size becomes 1") {
                REQUIRE(rb.size() == 1);


                AND_WHEN("a value is popped") {
                    int val = rb.pop_front();

                    THEN("the size decreases and the value is returned") {
                        REQUIRE(rb.size() == 0);
                        REQUIRE(val == 1);
                    }
                }
            }
        }

        WHEN("more values than the capacity are added via push_back({...}).") {
            rb.push_back({1, 2, 3, 4, 5});

            THEN("the size is equal to the capacity") {
                REQUIRE(rb.size() == capacity);

                AND_WHEN("we pop from the front") {
                    int val = rb.pop_front();
                    THEN("we get the oldest value in the ring.")REQUIRE(val == 2);
                }
            }
        }

        WHEN("more values than the ring's capacity are push_back'ed") {

            for (auto i = 1; i <= 6; i++) {
                rb.push_back(i);
            }
            THEN("calling last returns the last value added to the ring") {
                REQUIRE(rb.last() == 6);

                AND_WHEN("we call pop_front") {
                    int val = rb.pop_front();

                    THEN("we get the oldest value from the buffer")
                        REQUIRE(val == 3);
                }
            }
        }
        WHEN("popping values where back < front") {
            rb.push_back({1, 2, 3, 4, 5});

            THEN("The size is correct, as well as first and last elements") {
                REQUIRE(rb.size() == 4);
                REQUIRE(rb.first() == 2);
                REQUIRE(rb.last() == 5);


                AND_WHEN("We pop all the values of the ring") {
                    int val;
                    for (auto i = 0; i < 4; i++) { val = rb.pop_front(); }
                    THEN("We get the last value to be pushed back onto the ring") {
                        REQUIRE(val == 5);
                    }
                }
            }
        }
    }
}
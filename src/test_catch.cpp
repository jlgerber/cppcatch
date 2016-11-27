//
// Created by Jonathan Gerber on 11/27/16.
//
#include "ringbuffer.hpp"
#include "catch.hpp"

TEST_CASE("RingBuffer") {

    RingBuffer<int> rb(4, 0);
    REQUIRE(rb.size() == 0);

    SECTION("adding a value increases the size") {
        rb.push_back(1);
        REQUIRE(rb.size() == 1);


        SECTION("popping a value decreases the size and returns the first value") {
            int val = rb.pop_front();
            REQUIRE(rb.size() == 0);
            REQUIRE(val == 1);
        }
    }

    SECTION("adding more values than the capacity wraps the buffer using push_back({}). calling pop_front will return the oldest data in the buffer.") {
        rb.push_back({1, 2, 3, 4, 5});
        REQUIRE(rb.size()==4);
        int val = rb.pop_front();

        REQUIRE(val == 2);
    }

    SECTION("pushing more individual values than capacity wraps the buffer") {
        int val;
        for(auto i=1; i<=6; i++) {
            rb.push_back(i);
        }
        REQUIRE(rb.last() == 6);
    }
    SECTION("popping values where back < front works") {
        rb.push_back({1, 2, 3, 4, 5}); // m_start = 1, m_end = 1
        REQUIRE(rb.size()==4);
        REQUIRE(rb.first() == 2);
        REQUIRE(rb.last() == 5);
        int val;
        for(auto i=0; i < 4; i++ ) {val = rb.pop_front();}
        REQUIRE(val == 5);
    }
}